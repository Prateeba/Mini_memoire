#include <fstream>
#include <string>

#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/predicate.hpp> // starts_with
#include <boost/algorithm/string/replace.hpp> // replace_all_copy

#include <lib/vcsn/algos/fwd.hh>
#include <vcsn/algos/edit-automaton.hh>
#include <vcsn/dyn/algos.hh>
#include <vcsn/dyn/automaton.hh>
#include <vcsn/misc/getargs.hh>
#include <vcsn/misc/symbol.hh>
#include <vcsn/misc/regex.hh>

namespace vcsn
{
  namespace dyn
  {
    namespace
    {
      /// Look for the next "cat >$medir/FILE <<\EOFSM" file,
      /// and return FILE.
      std::string
      read_here_doc(std::istream& is)
      {
        static const auto re
          = std::regex("cat >\\$medir/([a-z]+)\\.[a-z]* <<\\\\EOFSM",
                       std::regex::extended);
        std::string line;
        std::smatch res;
        while (is.good())
          {
            std::getline(is, line, '\n');
            if (std::regex_match(line, res, re))
              return res[1];
          }
        raise("invalid efsm file: missing \"cat\" symbol");
      }

      /// Read a symbol table (i.e., eat up to the next EOFSM) and
      /// return the single piece of information we need from the
      /// symbol table: the representation of the empty word.
      std::string
      read_symbol_table(std::istream& is)
      {
        std::string res;
        std::string line;
        std::string val;
        while (is.good())
          {
            std::getline(is, line, '\n');
            std::istringstream ss{line};
            ss >> res;
            if (ss.fail())
              continue;
            ss >> val;
            if (ss.fail())
              raise("invalid efsm file");
            if (val == "0" || res == "EOFSM")
              break;
          }

        while (line != "EOFSM" && is.good())
            std::getline(is, line, '\n');

        require(line == "EOFSM",
                "invalid efsm file: missing closing EOFSM");
        return res;
      }

      /// Look for the "arc_type=" line that specifies the weightset.
      lazy_automaton_editor::weightset_type
      read_weightset_type(std::istream& is)
      {
        using weightset_type = lazy_automaton_editor::weightset_type;
        std::string line;
        while (is.good())
          {
            std::getline(is, line, '\n');
            if (boost::starts_with(line, "arc_type="))
              {
                boost::algorithm::erase_first(line, "arc_type=");
                static auto map = getarg<weightset_type>
                  {
                    "arc type",
                    {
                      {"log",      weightset_type::logarithmic},
                      {"log64",    weightset_type::logarithmic},
                      {"standard", weightset_type::tropical},
                    }
                  };
                return map[line];
              }
          }
        raise("invalid efsm file: missing \"arc_type=\"");
      }
    }

    automaton
    read_efsm(std::istream& is, const location&)
    {
      std::string file = "file.efsm";
      using string_t = symbol;

      // Whether has both isysmbols and osymbols.
      bool is_transducer = false;

      // Look for the arc type, which describes the weightset.
      auto weightset = read_weightset_type(is);

      // Look for the symbol table.
      auto isyms = read_here_doc(is);
      // The single piece of information we need from the symbol
      // table: the representation of the empty word.
      std::string ione = read_symbol_table(is);

      // If we had "isymbols", we now expect "osymbols".
      std::string oone = ione;
      if (isyms == "isymbols")
      {
        is_transducer = true;
        auto osyms = read_here_doc(is);
        require(osyms == "osymbols",
                "invalid efsm file: expected osymbols: ", osyms);
        oone = read_symbol_table(is);
      }

      auto edit = vcsn::lazy_automaton_editor{};
      edit.open(true);
      edit.weightset(weightset);

      // The first transition also provides the initial state.
      bool first = true;
      auto trans = read_here_doc(is);
      require(trans == "transitions",
              "invalid efsm file: expected transitions: ", trans);
      // Line: Source Dest ILabel [OLabel] [Weight].
      // Line: FinalState [Weight].
      std::string line;
      while (is.good())
        {
          std::getline(is, line, '\n');
          if (line == "EOFSM")
            break;
          std::istringstream ss{line};
          string_t s, d, l1, l2, w;
          ss >> s >> d >> l1 >> l2 >> w;
          if (first)
            edit.add_initial(s);
          if (l1.get().empty())
            // FinalState [Weight]
            edit.add_final(s, d);
          else
            {
              if (l1 == ione)
                l1 = "\\e";
              if (is_transducer)
                {
                  if (l2 == oone)
                    l2 = "\\e";
                  edit.add_transition(s, d, l1, l2, w);
                }
              else
                {
                  // l2 is actually the weight.
                  edit.add_transition(s, d, l1, l2);
                }
            }
          first = false;
        }

      require(line == "EOFSM",
              file, ": bad input format, missing EOFSM");
      // Flush till EOF.
      while (is.get() != EOF)
        continue;

      // We don't want to read it as a `law<char>` automaton, as for
      // OpenFST, these "words" are insecable.  The proper
      // interpretation is lal<string> (or lan<string>).
      using boost::algorithm::replace_all_copy;
      auto ctx = replace_all_copy(edit.result_context(),
                                  "law<char>", "lan<string>");
      return edit.result(ctx);
    }
  }
}
