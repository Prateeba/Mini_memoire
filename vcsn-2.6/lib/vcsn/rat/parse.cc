// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parse.hh"

// User implementation prologue.

#line 51 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 63 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:413

  #include <lib/vcsn/rat/driver.hh>
  #include <lib/vcsn/rat/scan.hh>
  #include <vcsn/dyn/algos.hh>
  #include <vcsn/misc/stream.hh>
  #include <vcsn/dyn/context.hh>

#define TRY(Loc, Stm)                           \
  try                                           \
    {                                           \
      Stm;                                      \
    }                                           \
  catch (std::exception& e)                     \
    {                                           \
      error(Loc, e.what());                     \
      YYERROR;                                  \
    }

  namespace vcsn
  {
    namespace rat
    {
      /// Generate an expression for "e <+ f = e % f + f".
      static inline
      dyn::expression prefer(const dyn::expression& e,
                             const dyn::expression& f);

      /// Get the context of the driver.
      static inline
      dyn::context ctx(const driver& d)
      {
        return d.context();
      }

      /// Get the identities of the driver.
      static inline
      identities ids(const driver& d)
      {
        return d.identities();
      }

      /// Use our local scanner object.
      static inline
      parser::symbol_type yylex(driver& d)
      {
        return d.scanner_->lex(d);
      }
    }
  }

#line 104 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 11 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:479
namespace vcsn { namespace rat {
#line 190 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (driver& driver__yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver_ (driver__yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 34: // input
      case 36: // add
      case 37: // tuple
      case 41: // exp
        value.move< braced_expression > (that.value);
        break;

      case 43: // class
        value.move< class_t > (that.value);
        break;

      case 42: // weights
        value.move< dyn::weight > (that.value);
        break;

      case 26: // "*"
        value.move< irange_type > (that.value);
        break;

      case 27: // "letter"
      case 28: // "weight"
        value.move< std::string > (that.value);
        break;

      case 39: // tuple.1
        value.move< std::vector<vcsn::dyn::expression> > (that.value);
        break;

      case 29: // "("
        value.move< symbol > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 34: // input
      case 36: // add
      case 37: // tuple
      case 41: // exp
        value.copy< braced_expression > (that.value);
        break;

      case 43: // class
        value.copy< class_t > (that.value);
        break;

      case 42: // weights
        value.copy< dyn::weight > (that.value);
        break;

      case 26: // "*"
        value.copy< irange_type > (that.value);
        break;

      case 27: // "letter"
      case 28: // "weight"
        value.copy< std::string > (that.value);
        break;

      case 39: // tuple.1
        value.copy< std::vector<vcsn::dyn::expression> > (that.value);
        break;

      case 29: // "("
        value.copy< symbol > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 27: // "letter"

#line 121 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        { yyo << '"' << yysym.value.template as< std::string > () << '"'; }
#line 421 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 28: // "weight"

#line 128 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        { yyo << '<' << yysym.value.template as< std::string > () << '>'; }
#line 428 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 29: // "("

#line 121 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        { yyo << '"' << yysym.value.template as< symbol > () << '"'; }
#line 435 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 34: // input
//-
//-#line 130 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
//-        {
//-  dyn::print(yysym.value.template as< braced_expression > ().exp, yyo);
//-  yyo << (yysym.value.template as< braced_expression > ().lparen ? " (lpar, " : " (no lpar, ");
//-  yyo << (yysym.value.template as< braced_expression > ().rparen ? "rpar)" : "no rpar)");
//-}
//-#line 446 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
//-        break;

      case 36: // add
//-
//-#line 130 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
//-        {
//-  dyn::print(yysym.value.template as< braced_expression > ().exp, yyo);
//-  yyo << (yysym.value.template as< braced_expression > ().lparen ? " (lpar, " : " (no lpar, ");
//-  yyo << (yysym.value.template as< braced_expression > ().rparen ? "rpar)" : "no rpar)");
//-}
//-#line 457 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
//-        break;

      case 37: // tuple

#line 130 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        {
  dyn::print(yysym.value.template as< braced_expression > ().exp, yyo);
  yyo << (yysym.value.template as< braced_expression > ().lparen ? " (lpar, " : " (no lpar, ");
  yyo << (yysym.value.template as< braced_expression > ().rparen ? "rpar)" : "no rpar)");
}
#line 468 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 39: // tuple.1

#line 136 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        {
  const char* sep = "[[";
  for (auto e: yysym.value.template as< std::vector<vcsn::dyn::expression> > ())
    {
      yyo << sep << e;
      sep = " || ";
    }
  yyo << "]]";
}
#line 483 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 41: // exp

#line 130 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        {
  dyn::print(yysym.value.template as< braced_expression > ().exp, yyo);
  yyo << (yysym.value.template as< braced_expression > ().lparen ? " (lpar, " : " (no lpar, ");
  yyo << (yysym.value.template as< braced_expression > ().rparen ? "rpar)" : "no rpar)");
}
#line 494 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 42: // weights

#line 146 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        { dyn::print(yysym.value.template as< dyn::weight > (), yyo); }
#line 501 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;

      case 43: // class

#line 123 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:636
        {
  yyo << '[';
  for (auto c: yysym.value.template as< class_t > ()) yyo << c.first << "-" << c.second;
  yyo << ']';
}
#line 512 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 117 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:741
{
  yyla.location = driver_.location_;
}

#line 630 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver_));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 34: // input
      case 36: // add
      case 37: // tuple
      case 41: // exp
        yylhs.value.build< braced_expression > ();
        break;

      case 43: // class
        yylhs.value.build< class_t > ();
        break;

      case 42: // weights
        yylhs.value.build< dyn::weight > ();
        break;

      case 26: // "*"
        yylhs.value.build< irange_type > ();
        break;

      case 27: // "letter"
      case 28: // "weight"
        yylhs.value.build< std::string > ();
        break;

      case 39: // tuple.1
        yylhs.value.build< std::vector<vcsn::dyn::expression> > ();
        break;

      case 29: // "("
        yylhs.value.build< symbol > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 206 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {
    auto dim_exp = dyn::num_tapes(dyn::context_of(yystack_[1].value.as< braced_expression > ().exp));
    auto dim_ctx = dyn::num_tapes(driver_.ctx_);
    if (dim_exp == 0 && dim_ctx == 1)
      // tuple never returns a tuple of rank 1 (see the case
      // `$2.size() == 1`).  Time to make it for such contexts.
      yylhs.value.as< braced_expression > () = vcsn::dyn::tuple({yystack_[1].value.as< braced_expression > ().exp});
    else if (dim_exp == dim_ctx)
      // Provide a value for $$ only for sake of traces: shows the result.
      yylhs.value.as< braced_expression > () = yystack_[1].value.as< braced_expression > ();
    else
      throw syntax_error(yylhs.location,
                         "not enough tapes: "
                         // num_tapes returns 0 on non lat.  In this
                         // case, 1 is clearer.
                         + std::to_string(std::max(size_t{1}, dim_exp))
                         + " expected "
                         + std::to_string(dim_ctx));
    driver_.result_ = yylhs.value.as< braced_expression > ().exp;
    YYACCEPT;
  }
#line 792 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 3:
#line 230 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {}
#line 798 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 4:
#line 231 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { driver_.scanner_->putback(','); }
#line 804 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 5:
#line 232 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { driver_.scanner_->putback(')'); }
#line 810 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 6:
#line 233 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { driver_.scanner_->putback(']'); }
#line 816 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 7:
#line 237 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = yystack_[0].value.as< braced_expression > (); }
#line 822 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 8:
#line 238 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::add(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 828 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 9:
#line 239 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::compose(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 834 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 10:
#line 245 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { driver_.tape_push(); }
#line 840 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 11:
#line 246 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {
    driver_.tape_pop();
    if (yystack_[0].value.as< std::vector<vcsn::dyn::expression> > ().size() == 1)
      yylhs.value.as< braced_expression > () = yystack_[0].value.as< std::vector<vcsn::dyn::expression> > ().back();
    else if (yystack_[0].value.as< std::vector<vcsn::dyn::expression> > ().size() == driver_.tape_ctx_.size())
      yylhs.value.as< braced_expression > () = vcsn::dyn::tuple(yystack_[0].value.as< std::vector<vcsn::dyn::expression> > ());
    else
      throw syntax_error(yylhs.location,
                         "not enough tapes: "
                         + std::to_string(yystack_[0].value.as< std::vector<vcsn::dyn::expression> > ().size())
                         + " expected "
                         + std::to_string(driver_.tape_ctx_.size()));
  }
#line 858 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 12:
#line 263 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {
    yylhs.value.as< std::vector<vcsn::dyn::expression> > ().emplace_back(yystack_[0].value.as< braced_expression > ().exp);
  }
#line 866 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 13:
#line 266 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { driver_.tape_inc(yystack_[0].location); }
#line 872 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 14:
#line 267 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {
    yylhs.value.as< std::vector<vcsn::dyn::expression> > () = yystack_[3].value.as< std::vector<vcsn::dyn::expression> > ();
    yylhs.value.as< std::vector<vcsn::dyn::expression> > ().emplace_back(yystack_[0].value.as< braced_expression > ().exp);
  }
#line 881 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 15:
#line 274 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::multiply(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 887 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 16:
#line 275 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::conjunction(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 893 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 17:
#line 276 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::shuffle(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 899 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 18:
#line 277 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::infiltrate(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 905 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 19:
#line 278 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = prefer(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 911 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 20:
#line 279 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::ldivide(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 917 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 21:
#line 280 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::rdivide(yystack_[2].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp); }
#line 923 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 22:
#line 281 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::conjunction(yystack_[2].value.as< braced_expression > ().exp,
                                                      dyn::complement(yystack_[0].value.as< braced_expression > ().exp)); }
#line 930 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 23:
#line 283 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::lweight(yystack_[1].value.as< dyn::weight > (), yystack_[0].value.as< braced_expression > ().exp); }
#line 936 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 24:
#line 284 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::rweight(yystack_[1].value.as< braced_expression > ().exp, yystack_[0].value.as< dyn::weight > ()); }
#line 942 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 25:
#line 286 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {
    // See README.txt.
    if (!yystack_[1].value.as< braced_expression > ().rparen && !yystack_[0].value.as< braced_expression > ().lparen)
      yylhs.value.as< braced_expression > () = dyn::concatenate(yystack_[1].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp);
    else
      {
        yylhs.value.as< braced_expression > ().exp = dyn::multiply(yystack_[1].value.as< braced_expression > ().exp, yystack_[0].value.as< braced_expression > ().exp);
        yylhs.value.as< braced_expression > ().lparen = yystack_[1].value.as< braced_expression > ().lparen;
        yylhs.value.as< braced_expression > ().rparen = yystack_[0].value.as< braced_expression > ().rparen;
      }
  }
#line 958 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 26:
#line 297 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { TRY(yylhs.location,
                          yylhs.value.as< braced_expression > () =
                          dyn::multiply(yystack_[1].value.as< braced_expression > ().exp,
                                        std::get<0>(yystack_[0].value.as< irange_type > ()), std::get<1>(yystack_[0].value.as< irange_type > ()))); }
#line 967 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 27:
#line 301 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::complement(yystack_[1].value.as< braced_expression > ().exp); }
#line 973 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 28:
#line 302 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::complement(yystack_[0].value.as< braced_expression > ().exp); }
#line 979 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 29:
#line 303 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::transposition(yystack_[1].value.as< braced_expression > ().exp); }
#line 985 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 30:
#line 304 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::transpose(yystack_[1].value.as< braced_expression > ().exp); }
#line 991 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 31:
#line 305 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::expression_zero(ctx(driver_), ids(driver_)); }
#line 997 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 32:
#line 306 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = dyn::expression_one(ctx(driver_), ids(driver_)); }
#line 1003 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 33:
#line 307 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = driver_.make_atom(yystack_[0].location, yystack_[0].value.as< std::string > ()); }
#line 1009 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 34:
#line 308 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = driver_.make_expression(yylhs.location, yystack_[1].value.as< class_t > (), true); }
#line 1015 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 35:
#line 309 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< braced_expression > () = driver_.make_expression(yylhs.location, yystack_[1].value.as< class_t > (), false); }
#line 1021 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 36:
#line 311 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {
    yylhs.value.as< braced_expression > ().exp = yystack_[1].value.as< braced_expression > ().exp;
    yylhs.value.as< braced_expression > ().lparen = yylhs.value.as< braced_expression > ().rparen = true;
    if (!yystack_[2].value.as< symbol > ().get().empty())
      yylhs.value.as< braced_expression > () = dyn::name(yylhs.value.as< braced_expression > ().exp, yystack_[2].value.as< symbol > ().get());
  }
#line 1032 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 37:
#line 320 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< dyn::weight > () = driver_.make_weight(yystack_[0].location, yystack_[0].value.as< std::string > ()); }
#line 1038 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 38:
#line 321 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< dyn::weight > () = dyn::multiply(driver_.make_weight(yystack_[1].location, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< dyn::weight > ()); }
#line 1044 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 39:
#line 325 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    {}
#line 1050 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 40:
#line 326 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< class_t > () = yystack_[1].value.as< class_t > (); yylhs.value.as< class_t > ().emplace(yystack_[0].value.as< std::string > (), yystack_[0].value.as< std::string > ()); }
#line 1056 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;

  case 41:
#line 327 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:859
    { yylhs.value.as< class_t > () = yystack_[3].value.as< class_t > (); yylhs.value.as< class_t > ().emplace(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ()); }
#line 1062 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
    break;


#line 1066 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -17;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
     -17,     2,     0,   -17,   160,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   160,    -1,   -17,   -17,   -17,     8,   -17,     6,
      53,   160,   -17,    25,   179,   -17,   -16,   -17,     4,   -17,
     160,   160,   160,   160,   -17,   160,   160,   160,   160,   -17,
     -17,   -17,   198,   -13,   101,   -14,   -17,    26,   -17,   160,
     131,   131,   155,   131,   198,    80,   107,   155,   -17,    14,
      53,   -17
  };

  const unsigned char
  parser::yydefact_[] =
  {
      10,     0,     3,     7,     0,     1,    10,     4,    10,     6,
       5,     2,     0,    39,    32,    31,    33,    37,    10,    11,
      12,     0,     9,     8,    28,    39,     0,    38,     0,    13,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    29,
      30,    26,    25,    24,    23,     0,    34,    40,    36,     0,
      16,    18,    20,    17,    15,    19,    22,    21,    35,     0,
      14,    41
  };

  const signed char
  parser::yypgoto_[] =
  {
     -17,   -17,   -17,    29,   -17,   -17,   -17,   -17,    -4,    -2,
      18
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    11,     2,     3,     4,    19,    49,    42,    21,
      26
  };

  const unsigned char
  parser::yytable_[] =
  {
      20,    13,     5,    14,    46,     6,    58,    25,    24,     6,
       7,    47,    15,    47,    16,    27,    18,    44,    43,     8,
       9,    10,    43,     8,    29,    48,    50,    51,    52,    53,
       6,    54,    55,    56,    57,    22,    17,    23,    59,    44,
      43,    61,    43,    45,     0,    60,     0,    28,    43,    43,
      43,    43,    43,    43,    43,    43,    30,    31,    43,    32,
      12,     0,    33,     0,    34,     0,    35,    13,    36,    14,
      37,     0,     0,     0,     0,    38,    39,    40,    15,    41,
      16,    17,    18,    30,    31,     0,    32,    12,     0,    33,
       0,    34,     0,    35,    13,     0,    14,    37,     0,     0,
       0,     0,    38,    39,    40,    15,    41,    16,    17,    18,
      30,    31,    34,    32,    12,     0,    33,     0,    34,     0,
      35,    13,     0,    14,    39,    40,     0,    41,     0,    38,
      39,    40,    15,    41,    16,    17,    18,    32,    12,     0,
       0,     0,    34,     0,    35,    13,     0,    14,     0,     0,
       0,     0,     0,    38,    39,    40,    15,    41,    16,    17,
      18,    32,    12,     0,     0,     0,    34,    12,    35,    13,
       0,    14,     0,     0,    13,     0,    14,     0,    39,    40,
      15,    41,    16,    17,    18,    15,     0,    16,    17,    18,
      34,     0,    35,    13,     0,    14,     0,     0,     0,     0,
       0,     0,    39,    40,    15,    41,    16,    17,    18,    34,
       0,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,    39,    40,    15,    41,    16,    17,    18
  };

  const signed char
  parser::yycheck_[] =
  {
       4,    14,     0,    16,    20,     5,    20,     8,    12,     5,
      10,    27,    25,    27,    27,    17,    29,    21,    20,    19,
      20,    21,    24,    19,    18,    21,    30,    31,    32,    33,
       5,    35,    36,    37,    38,     6,    28,     8,    12,    43,
      42,    27,    44,    25,    -1,    49,    -1,    18,    50,    51,
      52,    53,    54,    55,    56,    57,     3,     4,    60,     6,
       7,    -1,     9,    -1,    11,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,     3,     4,    -1,     6,     7,    -1,     9,
      -1,    11,    -1,    13,    14,    -1,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
       3,     4,    11,     6,     7,    -1,     9,    -1,    11,    -1,
      13,    14,    -1,    16,    23,    24,    -1,    26,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,     6,     7,    -1,    -1,    -1,    11,     7,    13,    14,
      -1,    16,    -1,    -1,    14,    -1,    16,    -1,    23,    24,
      25,    26,    27,    28,    29,    25,    -1,    27,    28,    29,
      11,    -1,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    11,
      -1,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    34,    36,    37,    38,     0,     5,    10,    19,    20,
      21,    35,     7,    14,    16,    25,    27,    28,    29,    39,
      41,    42,    36,    36,    41,     8,    43,    42,    36,    18,
       3,     4,     6,     9,    11,    13,    15,    17,    22,    23,
      24,    26,    41,    42,    41,    43,    20,    27,    21,    40,
      41,    41,    41,    41,    41,    41,    41,    41,    20,    12,
      41,    27
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    33,    34,    35,    35,    35,    35,    36,    36,    36,
      38,    37,    39,    40,    39,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    42,    42,    43,
      43,    43
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     0,     1,     1,     1,     1,     3,     3,
       0,     2,     1,     0,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     3,     4,     3,     1,     2,     0,
       2,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end\"", "error", "$undefined", "\"&\"", "\"&:\"", "\"@\"",
  "\"{\\\\}\"", "\"!\"", "\"^\"", "\":\"", "\",\"", "\"{c}\"", "\"-\"",
  "\".\"", "\"[\"", "\"<+\"", "\"\\\\e\"", "\"%\"", "\"|\"", "\"+\"",
  "\"]\"", "\")\"", "\"{/}\"", "\"{T}\"", "\"{t}\"", "\"\\\\z\"", "\"*\"",
  "\"letter\"", "\"weight\"", "\"(\"", "CONCAT", "RWEIGHT", "LWEIGHT",
  "$accept", "input", "terminator.opt", "add", "tuple", "$@1", "tuple.1",
  "$@2", "exp", "weights", "class", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   205,   205,   230,   231,   232,   233,   237,   238,   239,
     245,   245,   262,   266,   266,   274,   275,   276,   277,   278,
     279,   280,   281,   283,   284,   285,   297,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   320,   321,   325,
     326,   327
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 11 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:1167
} } // vcsn::rat
#line 1510 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.cc" // lalr1.cc:1167
#line 330 "/Users/akim/src/lrde/2/lib/vcsn/rat/parse.yy" // lalr1.cc:1168


namespace vcsn
{
  namespace rat
  {
    // "e <+ f = e + (f % e) = e + e{c} & f".
    static
    dyn::expression prefer(const dyn::expression& e, const dyn::expression& f)
    {
      return dyn::add(e, dyn::conjunction(dyn::complement(e), f));
    }

    void
    vcsn::rat::parser::error(const location_type& l, const std::string& m)
    {
      driver_.error(l, m);
    }
  }
}
