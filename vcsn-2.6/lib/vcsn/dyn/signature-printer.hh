#pragma once

#include <ostream>

#include <lib/vcsn/dyn/type-ast.hh>

namespace vcsn
{
  namespace ast
  {
    class signature_printer : public context_visitor
    {
    public:
      signature_printer(std::ostream& os, bool full)
        : os_(os), full_(full)
      {}

#define DEFINE(Type)                            \
      virtual void visit(const Type& t)

      DEFINE(automaton);
      DEFINE(context);
      DEFINE(expansionset);
      DEFINE(expressionset);
      DEFINE(genset);
      DEFINE(letterset);
      DEFINE(nullableset);
      DEFINE(oneset);
      DEFINE(other);
      DEFINE(polynomialset);
      DEFINE(tuple);
      DEFINE(tupleset);
      DEFINE(weightset);
      DEFINE(wordset);

#undef DEFINE

    private:
      std::ostream& os_;
      bool full_;
    };

    /// A context, normalized.
    ///
    /// E.g., 'lan_char(ab), b' -> 'lan<letterset<char_letters(ab)>, b'.
    ///
    /// \param ctx   the context to normalize.
    /// \param full  whether to print the runtime values.
    ///    (e.g., the generators: 'lan<letterset<char_letters(ab)>, b' or
    ///                           'lan<letterset<char_letters>, b').
    std::string normalize_context(const std::string& ctx, bool full = true);
  }
}
