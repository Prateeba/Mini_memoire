#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <lib/vcsn/dyn/context-parser.hh>
#include <lib/vcsn/dyn/signature-printer.hh>

#include <vcsn/misc/escape.hh>
#include <vcsn/misc/raise.hh>
#include <vcsn/misc/set.hh>
#include <vcsn/misc/stream.hh>

namespace vcsn
{
  namespace ast
  {
    /// Parser of snames.
    class context_parser
    {
    public:
      context_parser(std::istringstream& is)
        : is_(is)
      {}

      /// Accept anything.
      std::shared_ptr<ast_node> parse()
      {
        auto res = any_();
        check_eof_(res);
        return res;
      }

      /// Accept only a valid context.
      std::shared_ptr<ast_node> parse_context()
      {
        auto res = context_();
        check_eof_(res);
        return res;
      }

    private:
      /// The next character, possibly preceded by spaces.
      int peek_()
      {
        skip_space(is_);
        return is_.peek();
      }

      /// Accept this character, possibly preceded by spaces.
      char eat_(char c)
      {
        skip_space(is_);
        return eat(is_, c);
      }

      /// Accept this string, possibly preceded by spaces.
      const std::string& eat_(const std::string& s)
      {
        skip_space(is_);
        return eat(is_, s);
      }

      /// We managed to read \a res in \a is, check that `is_` is
      /// finished.
      void check_eof_(std::shared_ptr<ast_node> res)
      {
        if (peek_() != EOF)
        {
          std::ostringstream o;
          auto printer = signature_printer{o, true};
          res->accept(printer);
          vcsn::fail_reading(is_,
              "unexpected trailing characters after '",
              o.str(), "'");
        }
      }

      /// The next word in the stream.  Does not consider that
      /// underscore is word-constituent.  Skips spaces.
      std::string word_()
      {
        skip_space(is_);
        std::string res;
        int c;
        while ((c = is_.peek()) != EOF)
          if (c == '<' || c == ',' || c == '>' || c == '(')
            break;
          else
          {
            res += c;
            is_.ignore();
          }
        // Keep inner spaces, but not trailing spaces.
        boost::algorithm::trim_right(res);
        return res;
      }

      /// The next parameters in the stream.  Must be right before the
      /// opening `<`.  Will return up to the matching `>`.  Skips
      /// spaces.
      std::string parameters_()
      {
        auto res = std::string{};
        res += eat_('<');
        auto nesting = 1;
        int c;
        while ((c = peek_()) != EOF)
          {
            if (c == '<')
              ++nesting;
            else if (c == '>' && --nesting == 0)
              break;
            res += c;
            is_.ignore();
          }
        res += eat_('>');
        return res;
      }

      /// Accept anything.
      std::shared_ptr<ast_node> any_()
      {
        auto w = word_();
        auto res = std::shared_ptr<ast_node>{};
        if (boost::ends_with(w, "_automaton"))
          res = automaton_(w);
        else if (w == "context")
          res = context_(w);
        else if (w == "expansionset")
          res = expansionset_();
        else if (w == "expressionset" || w == "seriesset")
          res = expressionset_(w);
        else if (has(labelsets_, w))
          res = labelset_(w);
        else if (w == "lat")
          res = tupleset_();
        else if (w == "polynomialset")
          res = polynomialset_();
        else if (w == "std::tuple")
          res = tuple_();
        else if (has(weightsets_, w))
          res = weightset_(w);
        else
          // int,
          // std::integral_constant<unsigned, 2>,
          // boost::optional<unsigned>,
          // std::vector<unsigned>,
          // const std::set<std::pair<std::string, std::string>>,
          // etc.
          {
            if (peek_() == '<')
              w += parameters_();
            res = std::make_shared<other>(w);
          }
        return res;
      }

      /// An optional generator set in brackets (e.g.,
      /// `<char_letters(abc)>` or `<char>`).  Defaults to `<char>` if
      /// the stream does not start with `<`.
      std::shared_ptr<const genset> genset_()
      {
        if (peek_() == '<')
          {
            eat_('<');
            auto res = genset_(word_());
            eat_('>');
            return res;
          }
        else
          return genset_("char_letters");
      }

      /// A generator set (e.g., `char_letters(abc)` or `char`).
      /// \param letter_type should be `char_letter`, or `char`, etc.
      std::shared_ptr<const genset> genset_(std::string letter_type)
      {
        if (letter_type == "char" || letter_type == "string")
          letter_type += "_letters";
        std::string gens;
        if (peek_() == '(')
          {
            gens += '(';
            int c = is_.get();
            while ((c = is_.get()) != EOF && c != ')')
              {
                gens += c;
                if (c == '\\')
                  {
                    c = is_.get();
                    require(c != EOF, "unexpected end of file");
                    gens += c;
                  }
              }
            gens += ')';
          }
        return std::make_shared<const genset>(letter_type, gens);
      }

      /// `<LabelSet>, <WeightSet>`.
      std::shared_ptr<context> context_()
      {
        return context_(word_());
      }

      /// `<LabelSet>, <WeightSet>`.
      std::shared_ptr<context> context_(std::string w)
      {
        bool close = false;
        if (w == "context")
          {
            eat_('<');
            close = true;
            w = word_();
          }
        auto ls = labelset_(w);
        eat_(',');
        auto ws = weightset_();
        if (close)
          eat_('>');
        return std::make_shared<context>(ls, ws);
      }

      /// `<LabelSet>`.
      std::shared_ptr<ast_node> labelset_()
      {
        return labelset_(word_());
      }

      /// `<LabelSet>`.
      std::shared_ptr<ast_node> labelset_(const std::string& ls)
      {
        if (ls == "lal_char")
          return std::make_shared<letterset>(genset_("char_letters"));
        else if (ls == "lan")
          // lan<GENSET> => nullableset<letterset<GENSET>>.
          return std::make_shared<nullableset>(std::make_shared<letterset>
                                               (genset_()));
        else if (ls == "lan_char")
          return std::make_shared<nullableset>(std::make_shared<letterset>
                                               (genset_("char_letters")));
        else if (ls == "lao")
          return std::make_shared<oneset>();
        else if (ls == "lat")
          return tupleset_();
        else if (ls == "law_char")
          return std::make_shared<wordset>(genset_("char_letters"));
        else if (ls == "lal" || ls == "letterset")
          return std::make_shared<letterset>(genset_());
        else if (ls == "law" || ls == "wordset")
          return std::make_shared<wordset>(genset_());
        else if (ls == "nullableset")
          {
            eat_('<');
            auto res = labelset_();
            eat_('>');
            if (!res->has_one())
              res = std::make_shared<nullableset>(res);
            return res;
          }
        else if (ls == "expressionset" || ls == "seriesset")
          return expressionset_(ls);
        else
          raise("invalid labelset name: ", str_quote(ls));
      }

      /// `<WeightSet>`.
      std::shared_ptr<ast_node> weightset_()
      {
        return weightset_(word_());
      }

      /// `<WeightSet>`.
      std::shared_ptr<ast_node> weightset_(const std::string& ws)
      {
        if (has(weightsets_, ws))
          return std::make_shared<weightset>(ws);
        else if (ws == "expressionset" || ws == "seriesset")
          return expressionset_(ws);
        else if (ws == "polynomialset")
          return polynomialset_();
        else if (ws == "lat")
          return tupleset_();
        else
          raise("invalid weightset name: ", str_quote(ws));
      }

      /// `<Automaton> "<" <Context> ">"`.
      std::shared_ptr<automaton> automaton_()
      {
        return automaton_(word_());
      }

      /// `<Automaton> "<" <Context> ">"`.
      std::shared_ptr<automaton> automaton_(std::string prefix)
      {
        auto res = std::shared_ptr<automaton>{};
        // focus_automaton<TapeNum, Aut>.
        if (prefix == "focus_automaton")
          {
            eat_('<');
            res = std::make_shared<automaton>(prefix,
                                              std::make_shared<other>(word_()));
            eat_(',');
            res->get_content().emplace_back(automaton_());
            eat_('>');
          }
        // xxx_automaton<Aut>.
        else if (prefix == "delay_automaton"
                 || prefix == "expression_automaton"
                 || prefix == "filter_automaton"
                 || prefix == "insplit_automaton"
                 || prefix == "lazy_proper_automaton"
                 || prefix == "name_automaton"
                 || prefix == "pair_automaton"
                 || prefix == "partition_automaton"
                 || prefix == "permutation_automaton"
                 || prefix == "scc_automaton"
                 || prefix == "synchronized_automaton"
                 || prefix == "transpose_automaton")
          {
            eat_('<');
            res = std::make_shared<automaton>(prefix, automaton_());
            eat_('>');
          }
        // xxx_automaton<Aut, Tag, Lazy>.
        else if (prefix == "determinized_automaton")
          {
            eat_('<');
            res = std::make_shared<automaton>(prefix, automaton_());
            eat_(',');
            res->get_content().emplace_back(any_());
            eat_(',');
            res->get_content().emplace_back(any_());
            eat_('>');
          }
        // mutable_automaton<Context>.
        else if (prefix == "mutable_automaton")
          {
            eat_('<');
            res = std::make_shared<automaton>(prefix, context_());
            eat_('>');
          }
        // xxx_automaton<ExpresionSet>.
        else if (prefix == "derived_term_automaton")
          {
            eat_('<');
            res = std::make_shared<automaton>(prefix, expressionset_());
            eat_('>');
          }
        // xxx_automaton<Aut...>.
        else if (prefix == "compose_automaton"
                 || prefix == "product_automaton"
                 || prefix == "tuple_automaton")
          {
            eat_('<');
            std::string w = "";
            if (prefix != "tuple_automaton")
            {
              w = word_();
              eat_(',');
            }
            res = std::make_shared<automaton>(prefix,
                                              automaton_(word_()));
            if (prefix != "tuple_automaton")
            {
              auto& c = res->get_content();
              c.insert(c.begin(), std::make_shared<other>(w));
            }
            while (peek_() == ',')
              {
                eat_(',');
                res->get_content().emplace_back(automaton_());
              }
            eat_('>');
          }
        else
          raise("invalid automaton name: ", str_quote(prefix));
        return res;
      }

      /// `"<" (<Any> ",")* ">"`.
      std::shared_ptr<tuple> tuple_()
      {
        eat_('<');
        typename tuple::value_t res;
        res.emplace_back(any_());
        while (peek_() == ',')
        {
          eat_(',');
          res.emplace_back(any_());
        }
        eat_('>');
        return std::make_shared<tuple>(res);
      }

      /// `"<" (<LabelSet> | <WeightSet> ",")+ ">"`.
      std::shared_ptr<tupleset> tupleset_()
      {
        eat_('<');
        auto res = typename tupleset::value_t{};
        res.emplace_back(labelset_or_weightset_());
        while (peek_() == ',')
        {
          eat_(',');
          res.emplace_back(labelset_or_weightset_());
        }
        eat_('>');
        return std::make_shared<tupleset>(res);
      }

      /// `("expressionset"|"seriesset") "<" <Context> ">"`,
      /// possibly followed by identities.
      std::shared_ptr<expressionset> expressionset_()
      {
        return expressionset_(word_());
      }

      /// `"expressionset" "<" <Context> ">"`, possibly followed by identities.
      /// \a w is `"expressionset"` or `"seriesset"`, already eaten.
      std::shared_ptr<expressionset> expressionset_(const std::string& w)
      {
        require(w == "expressionset" || w == "seriesset",
                "invalid expressionset type: ", w,
                " expected expressionset or seriesset");
        eat_('<');
        auto context = context_();
        eat_('>');
        auto ids =
          w == "seriesset" ? rat::identities::distributive : rat::identities{};
        if (peek_() == '(')
          {
            eat_('(');
            is_ >> ids;
            eat_(')');
          }
        return std::make_shared<expressionset>(context, ids);
      }

      /// `"expansionset" "<" <Expressionset> ">"`.
      std::shared_ptr<expansionset> expansionset_()
      {
        eat_('<');
        auto res = std::make_shared<expansionset>(expressionset_());
        eat_('>');
        return res;
      }

      /// `"polynomialset" "<" <Context> ">"`.
      std::shared_ptr<polynomialset> polynomialset_()
      {
        eat_('<');
        auto res = std::make_shared<polynomialset>(context_());
        eat_('>');
        return res;
      }

      /// `<LabelSet> | <WeightSet>`
      std::shared_ptr<ast_node> labelset_or_weightset_()
      {
        return labelset_or_weightset_(word_());
      }

      /// `<LabelSet> | <WeightSet>`
      std::shared_ptr<ast_node> labelset_or_weightset_(const std::string& w)
      {
        if (w == "lat")
          return tupleset_();
        else if (w == "expressionset" || w == "seriesset")
          return expressionset_(w);
        else if (has(labelsets_, w))
          return labelset_(w);
        else if (has(weightsets_, w))
          return weightset_(w);
        else
          raise("invalid weightset or labelset name: ", str_quote(w));
      }

      /// The stream we are parsing.
      std::istringstream& is_;

      /// The set of terminal weightset names.
      std::set<std::string> weightsets_ =
        {
          "b",
          "f2",
          "log",
          "nmin",
          "q",
          "qmp",
          "r",
          "rmin",
          "z",
          "zmin",
        };

      /// The set of weightset names.
      std::set<std::string> labelsets_ =
        {
          "lal",
          "lal_char",
          "lan",
          "lan_char",
          "lao",
          "law",
          "law_char",
          "letterset",
          "nullableset",
          "wordset",
        };
    };

    std::shared_ptr<ast_node> parse_context(const std::string& ctx)
    {
      std::istringstream is{ctx};
      auto parser = ast::context_parser{is};
      try
        {
          return parser.parse_context();
        }
      catch (const std::runtime_error& e)
        {
          raise(e, "  while reading context: ", str_quote(ctx));
        }
    }

    std::shared_ptr<ast_node> parse_type(const std::string& type)
    {
      std::istringstream is{type};
      auto parser = ast::context_parser{is};
      try
        {
          return parser.parse();
        }
      catch (const std::runtime_error& e)
        {
          raise(e, "  while reading type: ", str_quote(type));
        }
    }
  }
}
