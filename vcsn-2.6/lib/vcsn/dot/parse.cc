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
// //                    "%code top" blocks.
#line 128 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:397

  /// Run Stm, and bounces exceptions into parse errors at Loc.
#define TRY(Loc, Stm)                           \
  do {                                          \
    try                                         \
      {                                         \
        Stm;                                    \
      }                                         \
    catch (std::exception& e)                   \
      {                                         \
        error(Loc, e.what());                   \
        YYERROR;                                \
      }                                         \
  } while (false)

#line 50 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:397


// First part of user declarations.

#line 55 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parse.hh"

// User implementation prologue.

#line 69 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 71 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:413

  #include <cassert>
  #include <vcsn/algos/edit-automaton.hh>
  #include <lib/vcsn/dot/scan.hh>

  namespace vcsn
  {
    namespace detail
    {
      namespace dot
      {
        static std::ostream&
        operator<<(std::ostream& o, const states_t ss)
        {
          bool first = true;
          o << '{';
          for (auto s: ss)
            {
              if (!first)
                o << ", ";
              o << s;
              first = false;
            }
          return o << '}';
        }

        static std::ostream&
        operator<<(std::ostream& o, const paths_t ps)
        {
          bool first = true;
          o << '{';
          for (auto t: ps.transitions)
            {
              if (!first)
                o << ", ";
              o << t.first << "->" << t.second;
              first = false;
            }
          return o << '}';
        }

        /// Use our local scanner object.
        static
        inline
        parser::symbol_type
        yylex(driver& driver_)
        {
          return driver_.scanner_->lex(driver_);
        }
      }
    }
  }

#line 125 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:413


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

#line 11 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:479
namespace vcsn { namespace detail { namespace dot {
#line 211 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:479

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
      case 31: // path
        value.move< paths_t > (that.value);
        break;

      case 20: // stmt_list
      case 21: // stmt
      case 30: // nodes
      case 32: // edge_stmt
      case 36: // subgraph
        value.move< states_t > (that.value);
        break;

      case 17: // "identifier"
      case 23: // attr_list
      case 24: // attr_list.opt
      case 25: // attr_assign
      case 26: // a_list.1
      case 29: // a_list.0
      case 33: // node_stmt
      case 34: // node_id
      case 37: // id.opt
        value.move< string_t > (that.value);
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
      case 31: // path
        value.copy< paths_t > (that.value);
        break;

      case 20: // stmt_list
      case 21: // stmt
      case 30: // nodes
      case 32: // edge_stmt
      case 36: // subgraph
        value.copy< states_t > (that.value);
        break;

      case 17: // "identifier"
      case 23: // attr_list
      case 24: // attr_list.opt
      case 25: // attr_assign
      case 26: // a_list.1
      case 29: // a_list.0
      case 33: // node_stmt
      case 34: // node_id
      case 37: // id.opt
        value.copy< string_t > (that.value);
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
            case 17: // "identifier"

#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< string_t > (); }
#line 426 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 20: // stmt_list
//-
//-#line 176 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
//-        { debug_stream() << yysym.value.template as< states_t > (); }
//-#line 433 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
//-        break;

      case 21: // stmt

#line 176 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< states_t > (); }
#line 440 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 23: // attr_list
//-
//-#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
//-        { debug_stream() << yysym.value.template as< string_t > (); }
//-#line 447 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
//-        break;

      case 24: // attr_list.opt
//-
//-#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
//-        { debug_stream() << yysym.value.template as< string_t > (); }
//-#line 454 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
//-        break;

      case 25: // attr_assign
//-
//-#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
//-        { debug_stream() << yysym.value.template as< string_t > (); }
//-#line 461 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
//-        break;

      case 26: // a_list.1
//-
//-#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
//-        { debug_stream() << yysym.value.template as< string_t > (); }
//-#line 468 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
//-        break;

      case 29: // a_list.0

#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< string_t > (); }
#line 475 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 30: // nodes

#line 176 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< states_t > (); }
#line 482 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 31: // path

#line 282 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< paths_t > (); }
#line 489 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 32: // edge_stmt

#line 176 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< states_t > (); }
#line 496 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 33: // node_stmt
//-
//-#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
//-        { debug_stream() << yysym.value.template as< string_t > (); }
//-#line 503 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
//-        break;

      case 34: // node_id

#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< string_t > (); }
#line 510 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 36: // subgraph

#line 176 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< states_t > (); }
#line 517 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
        break;

      case 37: // id.opt

#line 172 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:636
        { debug_stream() << yysym.value.template as< string_t > (); }
#line 524 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:636
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
    #line 145 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:741
{
  yyla.location = driver_.location_;
}

#line 642 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:741

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
      case 31: // path
        yylhs.value.build< paths_t > ();
        break;

      case 20: // stmt_list
      case 21: // stmt
      case 30: // nodes
      case 32: // edge_stmt
      case 36: // subgraph
        yylhs.value.build< states_t > ();
        break;

      case 17: // "identifier"
      case 23: // attr_list
      case 24: // attr_list.opt
      case 25: // attr_assign
      case 26: // a_list.1
      case 29: // a_list.0
      case 33: // node_stmt
      case 34: // node_id
      case 37: // id.opt
        yylhs.value.build< string_t > ();
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
//-#line 183 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 776 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 3:
#line 187 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {}
#line 782 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 4:
#line 189 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    // Preserve the set of states.
    std::swap(yylhs.value.as< states_t > (), yystack_[2].value.as< states_t > ());
    for (auto s: yystack_[1].value.as< states_t > ())
      yylhs.value.as< states_t > ().emplace_back(std::move(s));
  }
#line 793 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 5:
#line 198 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { yylhs.value.as< states_t > ().emplace_back(std::move(yystack_[0].value.as< string_t > ())); }
#line 799 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 6:
#line 199 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { std::swap(yylhs.value.as< states_t > (), yystack_[0].value.as< states_t > ()); }
#line 805 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 7:
//-#line 200 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 811 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 8:
#line 201 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {}
#line 817 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 9:
#line 202 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { std::swap(yylhs.value.as< states_t > (), yystack_[0].value.as< states_t > ()); }
#line 823 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 10:
//-#line 203 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 829 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 11:
//-#line 207 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 835 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 12:
//-#line 208 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 841 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 13:
#line 209 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {}
#line 847 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 14:
#line 214 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    std::swap(yylhs.value.as< string_t > (), yystack_[2].value.as< string_t > ().get().empty() ? yystack_[0].value.as< string_t > () : yystack_[2].value.as< string_t > ());
  }
#line 855 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 15:
#line 222 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { yylhs.value.as< string_t > () = ""; }
#line 861 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 16:
#line 223 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { std::swap(yylhs.value.as< string_t > (), yystack_[0].value.as< string_t > ()); }
#line 867 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 17:
#line 228 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    static const auto label = string_t{"label"};
    static const auto ctx = string_t{"vcsn_context"};
    if (yystack_[2].value.as< string_t > () == label)
      std::swap(yylhs.value.as< string_t > (), yystack_[0].value.as< string_t > ());
    else if (yystack_[2].value.as< string_t > () == ctx)
      driver_.setup_(yystack_[0].location, yystack_[0].value.as< string_t > ());
    else
      // Beware of the default "$$ = $1;" action.
      yylhs.value.as< string_t > () = "";
  }
#line 883 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 18:
#line 243 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    std::swap(yylhs.value.as< string_t > (), yystack_[2].value.as< string_t > ().get().empty() ? yystack_[0].value.as< string_t > () : yystack_[2].value.as< string_t > ());
  }
#line 891 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 24:
//-#line 259 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 897 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 25:
#line 260 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {}
#line 903 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 26:
#line 261 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { std::swap(yylhs.value.as< string_t > (), yystack_[0].value.as< string_t > ()); }
#line 909 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 27:
#line 265 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { yylhs.value.as< states_t > ().emplace_back(std::move(yystack_[0].value.as< string_t > ())); }
#line 915 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 28:
#line 266 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { yylhs.value.as< states_t > () = yystack_[0].value.as< states_t > (); }
#line 921 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 29:
#line 285 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    for (auto s1: yystack_[2].value.as< states_t > ())
      for (auto s2: yystack_[0].value.as< states_t > ())
        yylhs.value.as< paths_t > ().transitions.emplace_back(s1, s2);
    yylhs.value.as< paths_t > ().ends = yystack_[0].value.as< states_t > ();
  }
#line 932 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 30:
#line 292 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    std::swap(yylhs.value.as< paths_t > ().transitions, yystack_[2].value.as< paths_t > ().transitions);
    for (auto s1: yystack_[2].value.as< paths_t > ().ends)
      for (auto s2: yystack_[0].value.as< states_t > ())
        yylhs.value.as< paths_t > ().transitions.emplace_back(s1, s2);
    yylhs.value.as< paths_t > ().ends = yystack_[0].value.as< states_t > ();
  }
#line 944 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 31:
#line 303 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    if (driver_.has_edit_(yystack_[1].location))
      for (auto t: yystack_[1].value.as< paths_t > ().transitions)
        TRY(yystack_[0].location, driver_.edit_->add_entry(t.first, t.second, yystack_[0].value.as< string_t > ()));
  }
#line 954 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 32:
#line 312 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    std::swap(yylhs.value.as< string_t > (), yystack_[1].value.as< string_t > ());
  }
#line 962 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 33:
#line 319 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {
    std::swap(yylhs.value.as< string_t > (), yystack_[1].value.as< string_t > ());
    if (driver_.has_edit_(yystack_[1].location))
      {
        if (yylhs.value.as< string_t > ().get()[0] == 'I')
          TRY(yystack_[1].location, driver_.edit_->add_pre(yylhs.value.as< string_t > ()));
        else if (yylhs.value.as< string_t > ().get()[0] == 'F')
          TRY(yystack_[1].location, driver_.edit_->add_post(yylhs.value.as< string_t > ()));
        else
          // This is not needed, but it ensures that the states will be
          // numbered by their order of appearance in the file.
          TRY(yystack_[1].location, driver_.edit_->add_state(yylhs.value.as< string_t > ()));
      }
  }
#line 981 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 34:
//-#line 340 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 987 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 35:
//-#line 341 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    {}
//-#line 993 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 36:
#line 342 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {}
#line 999 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 37:
//-#line 346 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
//-    { std::swap(yylhs.value.as< states_t > (), yystack_[1].value.as< states_t > ()); }
//-#line 1005 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
//-    break;

  case 38:
#line 347 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { std::swap(yylhs.value.as< states_t > (), yystack_[1].value.as< states_t > ()); }
#line 1011 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 39:
#line 351 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    {}
#line 1017 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;

  case 40:
#line 352 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:859
    { std::swap(yylhs.value.as< string_t > (), yystack_[0].value.as< string_t > ()); }
#line 1023 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
    break;


#line 1027 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -24;

  const signed char parser::yytable_ninf_ = -29;

  const signed char
  parser::yypact_[] =
  {
       0,     9,    33,   -24,    31,   -24,   -24,     1,   -24,    37,
      37,    37,     9,   -24,   -24,    34,    44,   -24,   -24,    39,
       4,   -24,   -24,    17,    48,    14,   -24,   -24,   -24,    41,
      15,    45,    46,   -24,   -24,   -24,    21,    21,   -24,   -24,
     -24,   -24,    52,    35,   -24,    54,   -24,   -24,   -24,    53,
      55,   -24,   -24,   -24,   -24,   -24,   -24,    14,    37,    36,
      49,   -24,   -24,   -24,   -24
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    39,     0,    40,     0,     1,     3,     0,    10,     0,
       0,     0,    39,     3,     2,    34,    22,     7,     8,     0,
      15,     6,     5,    15,     9,     0,    13,    11,    12,     0,
       0,     0,     0,    33,    23,     4,     0,     0,    16,    31,
      32,    25,     0,    19,    26,     0,     3,    38,    17,    35,
      34,    29,    27,    28,    30,    20,    21,     0,    15,     0,
       0,    18,    14,    37,    36
  };

  const signed char
  parser::yypgoto_[] =
  {
     -24,   -24,   -12,   -24,   -24,     2,   -23,   -21,   -24,   -24,
     -24,    11,    18,   -24,   -24,   -24,    20,   -24,    22,    58
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     7,    16,    17,    38,    39,    18,    44,    57,
      35,    45,    19,    20,    21,    22,    23,    33,    24,     4
  };

  const signed char
  parser::yytable_[] =
  {
      40,    30,     8,     1,    43,     9,    10,    11,    12,    13,
      14,    26,    27,    28,    25,    41,     8,    37,    15,     9,
      10,    11,    12,    13,    47,   -24,     3,    25,    12,    13,
     -27,    42,    15,     5,    59,    62,    43,     8,    50,     6,
       9,    10,    11,    12,    13,    63,    31,    25,    32,    46,
      55,    56,    36,    15,    51,    54,    52,    52,    53,    53,
      34,   -28,    48,    49,    31,    58,    64,    60,    61,    32,
      29
  };

  const unsigned char
  parser::yycheck_[] =
  {
      23,    13,     1,     3,    25,     4,     5,     6,     7,     8,
       9,     9,    10,    11,    10,     1,     1,    13,    17,     4,
       5,     6,     7,     8,     9,    11,    17,    10,     7,     8,
      13,    17,    17,     0,    46,    58,    57,     1,    17,     8,
       4,     5,     6,     7,     8,     9,    12,    10,    14,     8,
      15,    16,    13,    17,    36,    37,    36,    37,    36,    37,
      16,    13,    17,    17,    12,    11,    17,    14,    57,    14,
      12
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    19,    17,    37,     0,     8,    20,     1,     4,
       5,     6,     7,     8,     9,    17,    21,    22,    25,    30,
      31,    32,    33,    34,    36,    10,    23,    23,    23,    37,
      20,    12,    14,    35,    16,    28,    13,    13,    23,    24,
      24,     1,    17,    25,    26,    29,     8,     9,    17,    17,
      17,    30,    34,    36,    30,    15,    16,    27,    11,    20,
      14,    29,    24,     9,    17
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    18,    19,    20,    20,    21,    21,    21,    21,    21,
      21,    22,    22,    22,    23,    24,    24,    25,    26,    27,
      27,    27,    28,    28,    29,    29,    29,    30,    30,    31,
      31,    32,    33,    34,    35,    35,    35,    36,    36,    37,
      37
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     5,     0,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     4,     0,     1,     3,     3,     0,
       1,     1,     0,     1,     0,     1,     1,     1,     1,     3,
       3,     2,     2,     2,     0,     2,     4,     5,     3,     0,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end\"", "error", "$undefined", "\"digraph\"", "\"edge\"",
  "\"graph\"", "\"node\"", "\"subgraph\"", "\"{\"", "\"}\"", "\"[\"",
  "\"]\"", "\"=\"", "\"->\"", "\":\"", "\",\"", "\";\"", "\"identifier\"",
  "$accept", "graph", "stmt_list", "stmt", "attr_stmt", "attr_list",
  "attr_list.opt", "attr_assign", "a_list.1", "comma.opt", "semi.opt",
  "a_list.0", "nodes", "path", "edge_stmt", "node_stmt", "node_id",
  "port.opt", "subgraph", "id.opt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   183,   183,   187,   188,   198,   199,   200,   201,   202,
     203,   207,   208,   209,   213,   222,   223,   227,   242,   249,
     249,   249,   253,   254,   259,   260,   261,   265,   266,   284,
     291,   302,   311,   318,   340,   341,   342,   346,   347,   351,
     352
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


#line 11 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:1167
} } } // vcsn::detail::dot
#line 1441 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.cc" // lalr1.cc:1167
#line 354 "/Users/akim/src/lrde/2/lib/vcsn/dot/parse.yy" // lalr1.cc:1168


namespace vcsn
{
  namespace detail
  {
    namespace dot
    {
      void
      parser::error(const location_type& l, const std::string& m)
      {
        driver_.error(l, m);
      }
    }
  }
}
