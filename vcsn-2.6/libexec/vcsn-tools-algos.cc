// Generated, do not edit by hand.

#include <initializer_list>
#include <iostream>
#include <map>

#include <vcsn/dyn/algos.hh>

#include "/Users/akim/src/lrde/2/libexec/vcsn-tools.hh"

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace vcsn
{
  namespace tools
  {
    const std::multimap<std::string, algo> algos
    {
      {"accessible",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::accessible(a0);
        }}},

      {"add",
       {{type::automaton, type::automaton, type::string},
        "  LHS:automaton RHS:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::add(a0, a1, a2);
        }}},

      {"add",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::add(a0, a1);
        }}},

      {"add",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::add(a0, a1);
        }}},

      {"add",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::add(a0, a1);
        }}},

      {"add",
       {{type::weight, type::weight},
        "  LHS:weight RHS:weight -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::add(a0, a1);
        }}},

      {"ambiguous-word",
       {{type::automaton},
        "  AUT:automaton -> word",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::ambiguous_word(a0);
        }}},

      {"are-equal",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::are_equal(a0, a1);
        }}},

      {"are-equal",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::are_equal(a0, a1);
        }}},

      {"are-equivalent",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::are_equivalent(a0, a1);
        }}},

      {"are-equivalent",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::are_equivalent(a0, a1);
        }}},

      {"are-isomorphic",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::are_isomorphic(a0, a1);
        }}},

      {"cat",
       {{type::identities},
        "  ARG:identities -> identities",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::identities>(args[0], ctx);
          std::cout << dyn::cat(a0);
        }}},

      {"cat",
       {{type::automaton},
        "  ARG:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::cat(a0);
        }}},

      {"cat",
       {{type::expression},
        "  ARG:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::cat(a0);
        }}},

      {"cat",
       {{type::label},
        "  ARG:label -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          std::cout << dyn::cat(a0);
        }}},

      {"cat",
       {{type::polynomial},
        "  ARG:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          std::cout << dyn::cat(a0);
        }}},

      {"cat",
       {{type::weight},
        "  ARG:weight -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          std::cout << dyn::cat(a0);
        }}},

      {"cerny",
       {{type::number},
        "  NUM_STATES:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::cerny(ctx, a0);
        }}},

      {"coaccessible",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::coaccessible(a0);
        }}},

      {"codeterminize",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::codeterminize(a0, a1);
        }}},

      {"codeterminize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::codeterminize(a0);
        }}},

      {"cominimize",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::cominimize(a0, a1);
        }}},

      {"cominimize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::cominimize(a0);
        }}},

      {"compare",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::compare(a0, a1);
        }}},

      {"compare",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::compare(a0, a1);
        }}},

      {"compare",
       {{type::label, type::label},
        "  LHS:label RHS:label -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::compare(a0, a1);
        }}},

      {"compare",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::compare(a0, a1);
        }}},

      {"compare",
       {{type::weight, type::weight},
        "  LHS:weight RHS:weight -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::compare(a0, a1);
        }}},

      {"complement",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::complement(a0);
        }}},

      {"complement",
       {{type::expression},
        "  R:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::complement(a0);
        }}},

      {"complete",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::complete(a0);
        }}},

      {"component",
       {{type::automaton, type::number},
        "  AUT:automaton NUM:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::component(a0, a1);
        }}},

      {"compose",
       {{type::automaton, type::automaton, type::bool_},
        "  LHS:automaton RHS:automaton LAZY:bool -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          auto a2 = convert<bool>(args[2], ctx);
          std::cout << dyn::compose(a0, a1, a2);
        }}},

      {"compose",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::compose(a0, a1);
        }}},

      {"compose",
       {{},
        "   -> context",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::compose(ctx, ctx);
        }}},

      {"compose",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::compose(a0, a1);
        }}},

      {"compose",
       {{type::label, type::label},
        "  LHS:label RHS:label -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::compose(a0, a1);
        }}},

      {"compose",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::compose(a0, a1);
        }}},

      {"concatenate",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::concatenate(a0, a1);
        }}},

      {"condense",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::condense(a0);
        }}},

      {"configuration",
       {{type::string},
        "  KEY:string -> string",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<std::string>(args[0], ctx);
          std::cout << dyn::configuration(a0);
        }}},

      {"conjugate",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::conjugate(a0);
        }}},

      {"conjunction",
       {{type::automaton, type::automaton, type::bool_},
        "  LHS:automaton RHS:automaton LAZY:bool -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          auto a2 = convert<bool>(args[2], ctx);
          std::cout << dyn::conjunction(a0, a1, a2);
        }}},

      {"conjunction",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::conjunction(a0, a1);
        }}},

      {"conjunction",
       {{type::automaton, type::number},
        "  AUT:automaton N:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::conjunction(a0, a1);
        }}},

      {"conjunction",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::conjunction(a0, a1);
        }}},

      {"conjunction",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::conjunction(a0, a1);
        }}},

      {"constant-term",
       {{type::expression},
        "  E:expression -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::constant_term(a0);
        }}},

      {"context-of",
       {{type::automaton},
        "  A:automaton -> context",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::context_of(a0);
        }}},

      {"context-of",
       {{type::expression},
        "  R:expression -> context",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::context_of(a0);
        }}},

      {"context-of",
       {{type::polynomial},
        "  R:polynomial -> context",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          std::cout << dyn::context_of(a0);
        }}},

      {"copy",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::copy(a0);
        }}},

      {"copy",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::copy(a0, ctx);
        }}},

      {"copy",
       {{type::expression, type::identities},
        "  EXP:expression IDS:identities -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::identities>(args[1], ctx);
          std::cout << dyn::copy(a0, ctx, a1);
        }}},

      {"costandard",
       {{type::automaton},
        "  A:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::costandard(a0);
        }}},

      {"cotrie",
       {{type::polynomial},
        "  P:polynomial -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          std::cout << dyn::cotrie(a0);
        }}},

      {"de-bruijn",
       {{type::number},
        "  N:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::de_bruijn(ctx, a0);
        }}},

      {"delay-automaton",
       {{type::automaton},
        "  A:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::delay_automaton(a0);
        }}},

      {"derivation",
       {{type::expression, type::label, type::bool_},
        "  EXP:expression LBL:label BREAKING:bool -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          auto a2 = convert<bool>(args[2], ctx);
          std::cout << dyn::derivation(a0, a1, a2);
        }}},

      {"derivation",
       {{type::expression, type::label},
        "  EXP:expression LBL:label -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::derivation(a0, a1);
        }}},

      {"derived-term",
       {{type::expression, type::string},
        "  EXP:expression ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::derived_term(a0, a1);
        }}},

      {"derived-term",
       {{type::expression},
        "  EXP:expression -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::derived_term(a0);
        }}},

      {"determinize",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::determinize(a0, a1);
        }}},

      {"determinize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::determinize(a0);
        }}},

      {"difference",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::difference(a0, a1);
        }}},

      {"difference",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::difference(a0, a1);
        }}},

      {"divkbaseb",
       {{type::number, type::number},
        "  DIVISOR:number BASE:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::divkbaseb(ctx, a0, a1);
        }}},

      {"eliminate-state",
       {{type::automaton, type::number},
        "  AUT:automaton S:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          std::cout << dyn::eliminate_state(a0, a1);
        }}},

      {"eliminate-state",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::eliminate_state(a0);
        }}},

      {"evaluate",
       {{type::automaton, type::label},
        "  AUT:automaton L:word -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], make_word_context(ctx));
          std::cout << dyn::evaluate(a0, a1);
        }}},

      {"evaluate",
       {{type::automaton, type::polynomial},
        "  AUT:automaton P:polynomial -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::evaluate(a0, a1);
        }}},

      {"expand",
       {{type::expression},
        "  E:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::expand(a0);
        }}},

      {"expression-one",
       {{type::identities},
        "  IDS:identities -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::identities>(args[0], ctx);
          std::cout << dyn::expression_one(ctx, a0);
        }}},

      {"expression-zero",
       {{type::identities},
        "  IDS:identities -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::identities>(args[0], ctx);
          std::cout << dyn::expression_zero(ctx, a0);
        }}},

      {"factor",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::factor(a0);
        }}},

      {"focus",
       {{type::automaton, type::number},
        "  AUT:automaton TAPE:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::focus(a0, a1);
        }}},

      {"has-bounded-lag",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::has_bounded_lag(a0);
        }}},

      {"has-lightening-cycle",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::has_lightening_cycle(a0);
        }}},

      {"has-twins-property",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::has_twins_property(a0);
        }}},

      {"identities-of",
       {{type::expression},
        "  EXP:expression -> identities",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::identities_of(a0);
        }}},

      {"inductive",
       {{type::expression, type::string},
        "  E:expression ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::inductive(a0, a1);
        }}},

      {"inductive",
       {{type::expression},
        "  E:expression -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::inductive(a0);
        }}},

      {"infiltrate",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::infiltrate(a0, a1);
        }}},

      {"infiltrate",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::infiltrate(a0, a1);
        }}},

      {"infiltrate",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::infiltrate(a0, a1);
        }}},

      {"insplit",
       {{type::automaton, type::bool_},
        "  AUT:automaton LAZY:bool -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<bool>(args[1], ctx);
          std::cout << dyn::insplit(a0, a1);
        }}},

      {"insplit",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::insplit(a0);
        }}},

      {"is-accessible",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_accessible(a0);
        }}},

      {"is-ambiguous",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_ambiguous(a0);
        }}},

      {"is-coaccessible",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_coaccessible(a0);
        }}},

      {"is-codeterministic",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_codeterministic(a0);
        }}},

      {"is-complete",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_complete(a0);
        }}},

      {"is-costandard",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_costandard(a0);
        }}},

      {"is-cycle-ambiguous",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_cycle_ambiguous(a0);
        }}},

      {"is-deterministic",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_deterministic(a0);
        }}},

      {"is-empty",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_empty(a0);
        }}},

      {"is-eps-acyclic",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_eps_acyclic(a0);
        }}},

      {"is-functional",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_functional(a0);
        }}},

      {"is-letterized",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_letterized(a0);
        }}},

      {"is-normalized",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_normalized(a0);
        }}},

      {"is-out-sorted",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_out_sorted(a0);
        }}},

      {"is-partial-identity",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_partial_identity(a0);
        }}},

      {"is-proper",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_proper(a0);
        }}},

      {"is-realtime",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_realtime(a0);
        }}},

      {"is-standard",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_standard(a0);
        }}},

      {"is-synchronized",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_synchronized(a0);
        }}},

      {"is-synchronized-by",
       {{type::automaton, type::label},
        "  AUT:automaton WORD:word -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], make_word_context(ctx));
          std::cout << dyn::is_synchronized_by(a0, a1);
        }}},

      {"is-synchronizing",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_synchronizing(a0);
        }}},

      {"is-trim",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_trim(a0);
        }}},

      {"is-useless",
       {{type::automaton},
        "  AUT:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_useless(a0);
        }}},

      {"is-valid",
       {{type::automaton},
        "  E:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::is_valid(a0);
        }}},

      {"is-valid",
       {{type::expression},
        "  E:expression -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::is_valid(a0);
        }}},

      {"join",
       {{},
        "   -> context",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::join(ctx, ctx);
        }}},

      {"ladybird",
       {{type::number},
        "  N:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::ladybird(ctx, a0);
        }}},

      {"ldivide",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::ldivide(a0, a1);
        }}},

      {"ldivide",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::ldivide(a0, a1);
        }}},

      {"ldivide",
       {{type::label, type::label},
        "  LHS:label RHS:label -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::ldivide(a0, a1);
        }}},

      {"ldivide",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::ldivide(a0, a1);
        }}},

      {"ldivide",
       {{type::weight, type::weight},
        "  LHS:weight RHS:weight -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::ldivide(a0, a1);
        }}},

      {"less-than",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::less_than(a0, a1);
        }}},

      {"less-than",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> bool",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::less_than(a0, a1);
        }}},

      {"letterize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::letterize(a0);
        }}},

      {"levenshtein",
       {{},
        "   -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::levenshtein(ctx);
        }}},

      {"lgcd",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::lgcd(a0, a1);
        }}},

      {"lift",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::lift(a0);
        }}},

      {"lift",
       {{type::expression},
        "  E:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::lift(a0);
        }}},

      {"lightest",
       {{type::automaton, type::number, type::string},
        "  AUT:automaton NUM:number ALGO:string -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::lightest(a0, a1, a2);
        }}},

      {"lightest",
       {{type::automaton, type::number},
        "  AUT:automaton NUM:number -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::lightest(a0, a1);
        }}},

      {"lightest",
       {{type::automaton},
        "  AUT:automaton -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::lightest(a0);
        }}},

      {"lightest-automaton",
       {{type::automaton, type::number, type::string},
        "  AUT:automaton NUM:number ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::lightest_automaton(a0, a1, a2);
        }}},

      {"lightest-automaton",
       {{type::automaton, type::number},
        "  AUT:automaton NUM:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::lightest_automaton(a0, a1);
        }}},

      {"lightest-automaton",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::lightest_automaton(a0);
        }}},

      {"lweight",
       {{type::weight, type::automaton, type::string},
        "  W:weight AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::lweight(a0, a1, a2);
        }}},

      {"lweight",
       {{type::weight, type::automaton},
        "  W:weight AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::lweight(a0, a1);
        }}},

      {"lweight",
       {{type::weight, type::expression},
        "  W:weight EXP:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::lweight(a0, a1);
        }}},

      {"lweight",
       {{type::weight, type::polynomial},
        "  W:weight P:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::lweight(a0, a1);
        }}},

      {"minimize",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::minimize(a0, a1);
        }}},

      {"minimize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::minimize(a0);
        }}},

      {"multiply",
       {{type::automaton, type::automaton, type::string},
        "  LHS:automaton RHS:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::multiply(a0, a1, a2);
        }}},

      {"multiply",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::automaton, type::number, type::number, type::string},
        "  AUT:automaton MIN:number MAX:number ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          auto a2 = convert<int>(args[2], ctx);
          auto a3 = convert<std::string>(args[3], ctx);
          std::cout << dyn::multiply(a0, a1, a2, a3);
        }}},

      {"multiply",
       {{type::automaton, type::number, type::number},
        "  AUT:automaton MIN:number MAX:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          auto a2 = convert<int>(args[2], ctx);
          std::cout << dyn::multiply(a0, a1, a2);
        }}},

      {"multiply",
       {{type::automaton, type::number},
        "  AUT:automaton MIN:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::expression, type::number, type::number},
        "  E:expression MIN:number MAX:number -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          auto a2 = convert<int>(args[2], ctx);
          std::cout << dyn::multiply(a0, a1, a2);
        }}},

      {"multiply",
       {{type::expression, type::number},
        "  E:expression MIN:number -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::label, type::label},
        "  LHS:label RHS:label -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::label, type::number},
        "  L:label NUM:number -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::weight, type::weight},
        "  LHS:weight RHS:weight -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"multiply",
       {{type::weight, type::number, type::number},
        "  E:weight MIN:number MAX:number -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          auto a2 = convert<int>(args[2], ctx);
          std::cout << dyn::multiply(a0, a1, a2);
        }}},

      {"multiply",
       {{type::weight, type::number},
        "  E:weight MIN:number -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<int>(args[1], ctx);
          std::cout << dyn::multiply(a0, a1);
        }}},

      {"name",
       {{type::expression, type::string},
        "  EXP:expression NAME:string -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::name(a0, a1);
        }}},

      {"normalize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::normalize(a0);
        }}},

      {"num-components",
       {{type::automaton},
        "  AUT:automaton -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::num_components(a0);
        }}},

      {"num-tapes",
       {{},
        "   -> number",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::num_tapes(ctx);
        }}},

      {"pair",
       {{type::automaton, type::bool_},
        "  AUT:automaton KEEP_INITIALS:bool -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<bool>(args[1], ctx);
          std::cout << dyn::pair(a0, a1);
        }}},

      {"pair",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::pair(a0);
        }}},

      {"partial-identity",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::partial_identity(a0);
        }}},

      {"partial-identity",
       {{type::expression},
        "  E:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::partial_identity(a0);
        }}},

      {"prefix",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::prefix(a0);
        }}},

      {"project",
       {{type::automaton, type::number},
        "  AUT:automaton TAPE:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::project(a0, a1);
        }}},

      {"project",
       {{type::number},
        "  TAPE:number -> context",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::project(ctx, a0);
        }}},

      {"project",
       {{type::expression, type::number},
        "  EXP:expression TAPE:number -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::project(a0, a1);
        }}},

      {"project",
       {{type::polynomial, type::number},
        "  P:polynomial TAPE:number -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::project(a0, a1);
        }}},

      {"project",
       {{type::label, type::number},
        "  P:label TAPE:number -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::project(a0, a1);
        }}},

      {"proper",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::proper(a0);
        }}},

      {"push-weights",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::push_weights(a0);
        }}},

      {"quotkbaseb",
       {{type::number, type::number},
        "  DIVISOR:number BASE:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<unsigned>(args[1], ctx);
          std::cout << dyn::quotkbaseb(ctx, a0, a1);
        }}},

      {"random-automaton",
       {{type::number, type::float_, type::number, type::number, type::number, type::float_, type::string},
        "  NUM_STATES:number DENSITY:float NUM_INITIAL:number NUM_FINAL:number MAX_LABELS:number LOOP_CHANCE:float WEIGHTS:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<float>(args[1], ctx);
          auto a2 = convert<unsigned>(args[2], ctx);
          auto a3 = convert<unsigned>(args[3], ctx);
          auto a4 = convert<boost::optional<unsigned>>(args[4], ctx);
          auto a5 = convert<float>(args[5], ctx);
          auto a6 = convert<std::string>(args[6], ctx);
          std::cout << dyn::random_automaton(ctx, a0, a1, a2, a3, a4, a5, a6);
        }}},

      {"random-automaton",
       {{type::number, type::float_, type::number, type::number, type::number, type::float_},
        "  NUM_STATES:number DENSITY:float NUM_INITIAL:number NUM_FINAL:number MAX_LABELS:number LOOP_CHANCE:float -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<float>(args[1], ctx);
          auto a2 = convert<unsigned>(args[2], ctx);
          auto a3 = convert<unsigned>(args[3], ctx);
          auto a4 = convert<boost::optional<unsigned>>(args[4], ctx);
          auto a5 = convert<float>(args[5], ctx);
          std::cout << dyn::random_automaton(ctx, a0, a1, a2, a3, a4, a5);
        }}},

      {"random-automaton",
       {{type::number, type::float_, type::number, type::number, type::number},
        "  NUM_STATES:number DENSITY:float NUM_INITIAL:number NUM_FINAL:number MAX_LABELS:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<float>(args[1], ctx);
          auto a2 = convert<unsigned>(args[2], ctx);
          auto a3 = convert<unsigned>(args[3], ctx);
          auto a4 = convert<boost::optional<unsigned>>(args[4], ctx);
          std::cout << dyn::random_automaton(ctx, a0, a1, a2, a3, a4);
        }}},

      {"random-automaton",
       {{type::number, type::float_, type::number, type::number},
        "  NUM_STATES:number DENSITY:float NUM_INITIAL:number NUM_FINAL:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<float>(args[1], ctx);
          auto a2 = convert<unsigned>(args[2], ctx);
          auto a3 = convert<unsigned>(args[3], ctx);
          std::cout << dyn::random_automaton(ctx, a0, a1, a2, a3);
        }}},

      {"random-automaton",
       {{type::number, type::float_, type::number},
        "  NUM_STATES:number DENSITY:float NUM_INITIAL:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<float>(args[1], ctx);
          auto a2 = convert<unsigned>(args[2], ctx);
          std::cout << dyn::random_automaton(ctx, a0, a1, a2);
        }}},

      {"random-automaton",
       {{type::number, type::float_},
        "  NUM_STATES:number DENSITY:float -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          auto a1 = convert<float>(args[1], ctx);
          std::cout << dyn::random_automaton(ctx, a0, a1);
        }}},

      {"random-automaton",
       {{type::number},
        "  NUM_STATES:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::random_automaton(ctx, a0);
        }}},

      {"random-automaton-deterministic",
       {{type::number},
        "  NUM_STATES:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::random_automaton_deterministic(ctx, a0);
        }}},

      {"random-expression",
       {{type::string, type::identities},
        "  PARAM:string IDS:identities -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<std::string>(args[0], ctx);
          auto a1 = convert<dyn::identities>(args[1], ctx);
          std::cout << dyn::random_expression(ctx, a0, a1);
        }}},

      {"random-expression",
       {{type::string},
        "  PARAM:string -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<std::string>(args[0], ctx);
          std::cout << dyn::random_expression(ctx, a0);
        }}},

      {"random-expression",
       {{},
        "   -> expression",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::random_expression(ctx);
        }}},

      {"random-weight",
       {{type::string},
        "  PARAM:string -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<std::string>(args[0], ctx);
          std::cout << dyn::random_weight(ctx, a0);
        }}},

      {"rdivide",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::rdivide(a0, a1);
        }}},

      {"rdivide",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::rdivide(a0, a1);
        }}},

      {"rdivide",
       {{type::label, type::label},
        "  LHS:label RHS:label -> label",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::label>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::rdivide(a0, a1);
        }}},

      {"rdivide",
       {{type::weight, type::weight},
        "  LHS:weight RHS:weight -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::weight>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::rdivide(a0, a1);
        }}},

      {"realtime",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::realtime(a0);
        }}},

      {"reduce",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::reduce(a0);
        }}},

      {"rweight",
       {{type::automaton, type::weight, type::string},
        "  AUT:automaton W:weight ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::rweight(a0, a1, a2);
        }}},

      {"rweight",
       {{type::automaton, type::weight},
        "  AUT:automaton W:weight -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::rweight(a0, a1);
        }}},

      {"rweight",
       {{type::expression, type::weight},
        "  EXP:expression W:weight -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::rweight(a0, a1);
        }}},

      {"rweight",
       {{type::polynomial, type::weight},
        "  P:polynomial W:weight -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::weight>(args[1], ctx);
          std::cout << dyn::rweight(a0, a1);
        }}},

      {"scc",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::scc(a0, a1);
        }}},

      {"scc",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::scc(a0);
        }}},

      {"shortest",
       {{type::automaton, type::number, type::number},
        "  AUT:automaton NUM:number LEN:number -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<boost::optional<unsigned>>(args[1], ctx);
          auto a2 = convert<boost::optional<unsigned>>(args[2], ctx);
          std::cout << dyn::shortest(a0, a1, a2);
        }}},

      {"shortest",
       {{type::automaton, type::number},
        "  AUT:automaton NUM:number -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<boost::optional<unsigned>>(args[1], ctx);
          std::cout << dyn::shortest(a0, a1);
        }}},

      {"shortest",
       {{type::automaton},
        "  AUT:automaton -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::shortest(a0);
        }}},

      {"shuffle",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::shuffle(a0, a1);
        }}},

      {"shuffle",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::shuffle(a0, a1);
        }}},

      {"shuffle",
       {{type::polynomial, type::polynomial},
        "  LHS:polynomial RHS:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          auto a1 = convert<dyn::polynomial>(args[1], ctx);
          std::cout << dyn::shuffle(a0, a1);
        }}},

      {"sort",
       {{type::automaton},
        "  A:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::sort(a0);
        }}},

      {"split",
       {{type::expression},
        "  EXP:expression -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::split(a0);
        }}},

      {"split",
       {{type::polynomial},
        "  P:polynomial -> polynomial",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          std::cout << dyn::split(a0);
        }}},

      {"standard",
       {{type::automaton},
        "  A:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::standard(a0);
        }}},

      {"standard",
       {{type::expression},
        "  E:expression -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::standard(a0);
        }}},

      {"star",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::star(a0, a1);
        }}},

      {"star",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::star(a0);
        }}},

      {"star-height",
       {{type::expression},
        "  RS:expression -> number",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::star_height(a0);
        }}},

      {"star-normal-form",
       {{type::expression},
        "  E:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::star_normal_form(a0);
        }}},

      {"strip",
       {{type::automaton},
        "  A:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::strip(a0);
        }}},

      {"subword",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::subword(a0);
        }}},

      {"suffix",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::suffix(a0);
        }}},

      {"synchronize",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::synchronize(a0);
        }}},

      {"synchronizing-word",
       {{type::automaton, type::string},
        "  AUT:automaton ALGO:string -> word",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::synchronizing_word(a0, a1);
        }}},

      {"synchronizing-word",
       {{type::automaton},
        "  AUT:automaton -> word",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::synchronizing_word(a0);
        }}},

      {"thompson",
       {{type::expression},
        "  E:expression -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::thompson(a0);
        }}},

      {"to-automaton",
       {{type::expression, type::string},
        "  EXP:expression ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::to_automaton(a0, a1);
        }}},

      {"to-automaton",
       {{type::expression},
        "  EXP:expression -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::to_automaton(a0);
        }}},

      {"to-expansion",
       {{type::expression},
        "  EXP:expression -> expansion",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::to_expansion(a0);
        }}},

      {"to-expression",
       {{type::automaton, type::identities, type::string},
        "  AUT:automaton IDS:identities ALGO:string -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::identities>(args[1], ctx);
          auto a2 = convert<std::string>(args[2], ctx);
          std::cout << dyn::to_expression(a0, a1, a2);
        }}},

      {"to-expression",
       {{type::automaton, type::identities},
        "  AUT:automaton IDS:identities -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::identities>(args[1], ctx);
          std::cout << dyn::to_expression(a0, a1);
        }}},

      {"to-expression",
       {{type::automaton},
        "  AUT:automaton -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::to_expression(a0);
        }}},

      {"to-expression",
       {{type::identities, type::label},
        "  IDS:identities L:label -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::identities>(args[0], ctx);
          auto a1 = convert<dyn::label>(args[1], ctx);
          std::cout << dyn::to_expression(ctx, a0, a1);
        }}},

      {"transpose",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::transpose(a0);
        }}},

      {"transpose",
       {{type::expression},
        "  E:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::transpose(a0);
        }}},

      {"transposition",
       {{type::expression},
        "  R:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::transposition(a0);
        }}},

      {"trie",
       {{type::polynomial},
        "  P:polynomial -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::polynomial>(args[0], ctx);
          std::cout << dyn::trie(a0);
        }}},

      {"trim",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::trim(a0);
        }}},

      {"tuple",
       {{type::automaton, type::automaton},
        "  LHS:automaton RHS:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          auto a1 = convert<dyn::automaton>(args[1], ctx);
          std::cout << dyn::tuple(a0, a1);
        }}},

      {"tuple",
       {{},
        "   -> context",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::tuple(ctx, ctx);
        }}},

      {"tuple",
       {{type::expression, type::expression},
        "  LHS:expression RHS:expression -> expression",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<dyn::expression>(args[1], ctx);
          std::cout << dyn::tuple(a0, a1);
        }}},

      {"type",
       {{type::automaton},
        "  A:automaton -> string",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::type(a0);
        }}},

      {"u",
       {{type::number},
        "  N:number -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<unsigned>(args[0], ctx);
          std::cout << dyn::u(ctx, a0);
        }}},

      {"universal",
       {{type::automaton},
        "  AUT:automaton -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::universal(a0);
        }}},

      {"weight-one",
       {{},
        "   -> weight",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::weight_one(ctx);
        }}},

      {"weight-series",
       {{type::automaton},
        "  AUT:automaton -> weight",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::automaton>(args[0], ctx);
          std::cout << dyn::weight_series(a0);
        }}},

      {"weight-zero",
       {{},
        "   -> weight",
        [](const auto& args, const dyn::context& ctx)
        {

          std::cout << dyn::weight_zero(ctx);
        }}},

      {"zpc",
       {{type::expression, type::string},
        "  EXP:expression ALGO:string -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          auto a1 = convert<std::string>(args[1], ctx);
          std::cout << dyn::zpc(a0, a1);
        }}},

      {"zpc",
       {{type::expression},
        "  EXP:expression -> automaton",
        [](const auto& args, const dyn::context& ctx)
        {
          auto a0 = convert<dyn::expression>(args[0], ctx);
          std::cout << dyn::zpc(a0);
        }}},
    };

    const std::multimap<std::string, algo_doc> algos_doc
    {
      {"accessible",
       {"  AUT:automaton -> automaton",
        "  The accessible subautomaton of AUT."
       }},

      {"add",
       {"  LHS:automaton RHS:automaton [ALGO=\"auto\":string] -> automaton",
        "  Sum of two automata.\n"
        "    Parameters:\n"
        "      LHS   an automaton.\n"
        "      RHS   another one.\n"
        "      ALGO  how to compute the result\n"
        "        - \"standard\"    both LHS and RHS are standard,\n"
        "                        build a standard automaton.\n"
        "        - \"general\"     no requirement on LHS and and RHS.\n"
        "        - \"auto\"        \"standard\" if both automata are standard,\n"
        "                        \"general\" otherwise."
       }},

      {"add",
       {"  LHS:expression RHS:expression -> expression",
        "  Sum of two expressions."
       }},

      {"add",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  Sum of two polynomials."
       }},

      {"add",
       {"  LHS:weight RHS:weight -> weight",
        "  Sum of two weights."
       }},

      {"ambiguous-word",
       {"  AUT:automaton -> word",
        "  An ambiguous word, or raise if there is none."
       }},

      {"are-equal",
       {"  LHS:automaton RHS:automaton -> bool",
        "  Whether are the same automaton."
       }},

      {"are-equal",
       {"  LHS:expression RHS:expression -> bool",
        "  Whether are the same expression."
       }},

      {"are-equivalent",
       {"  LHS:automaton RHS:automaton -> bool",
        "  Whether compute the same series.\n"
        "    Preconditions:\n"
        "      The labelsets of lhs and rhs are free.\n"
        "      lhs and rhs are Boolean, or on Z, or on a field."
       }},

      {"are-equivalent",
       {"  LHS:expression RHS:expression -> bool",
        "  Whether denote the same series.\n"
        "    Preconditions:\n"
        "      The labelsets of lhs and rhs are free.\n"
        "      lhs and rhs are Boolean, or on Z, or on a field."
       }},

      {"are-isomorphic",
       {"  LHS:automaton RHS:automaton -> bool",
        "  Whether there exists an isomorphism between the states of \\a\n"
        "    lhs and those of RHS."
       }},

      {"cat",
       {"  ARG:identities -> identities",
        "  Return its argument."
       }},

      {"cat",
       {"  ARG:automaton -> automaton",
        "  Return its argument."
       }},

      {"cat",
       {"  ARG:expression -> expression",
        "  Return its argument."
       }},

      {"cat",
       {"  ARG:label -> label",
        "  Return its argument."
       }},

      {"cat",
       {"  ARG:polynomial -> polynomial",
        "  Return its argument."
       }},

      {"cat",
       {"  ARG:weight -> weight",
        "  Return its argument."
       }},

      {"cerny",
       {"  NUM_STATES:number -> automaton",
        "  Produce a Černý automaton of NUM_STATES states."
       }},

      {"coaccessible",
       {"  AUT:automaton -> automaton",
        "  The coaccessible subautomaton of AUT."
       }},

      {"codeterminize",
       {"  AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  The codeterminized automaton.\n"
        "    Parameters:\n"
        "      AUT        the automaton to codeterminize\n"
        "      ALGO\n"
        "        - \"boolean\"     use efficient bitsets\n"
        "        - \"weighted\"    accept non Boolean automata (might not terminate)\n"
        "        - \"auto\"        \"boolean\" if the automaton is Boolean,\n"
        "                        \"weighted\" otherwise.\n"
        "    Preconditions:\n"
        "       the labelset of AUT must be free."
       }},

      {"cominimize",
       {"  AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  The cominimized automaton.\n"
        "    Parameters:\n"
        "      AUT       the automaton to cominimize\n"
        "      ALGO      the specific algorithm to use\n"
        "    Preconditions:\n"
        "       AUT must be LAL.\n"
        "       AUT must be deterministic."
       }},

      {"compare",
       {"  LHS:automaton RHS:automaton -> number",
        "  Three-way comparison between automata.\n"
        "    Return value:\n"
        "      negative if `lhs < rhs`\n"
        "               null     if `lhs = rhs`\n"
        "               positive if `lhs > rhs`"
       }},

      {"compare",
       {"  LHS:expression RHS:expression -> number",
        "  Three-way comparison between expressions.\n"
        "    Return value:\n"
        "      negative if `lhs < rhs`\n"
        "               null     if `lhs = rhs`\n"
        "               positive if `lhs > rhs`"
       }},

      {"compare",
       {"  LHS:label RHS:label -> number",
        "  Three-way comparison between labels.\n"
        "    Return value:\n"
        "      negative if `lhs < rhs`\n"
        "               null     if `lhs = rhs`\n"
        "               positive if `lhs > rhs`"
       }},

      {"compare",
       {"  LHS:polynomial RHS:polynomial -> number",
        "  Three-way comparison between polynomials.\n"
        "    Return value:\n"
        "      negative if `lhs < rhs`\n"
        "               null     if `lhs = rhs`\n"
        "               positive if `lhs > rhs`"
       }},

      {"compare",
       {"  LHS:weight RHS:weight -> number",
        "  Three-way comparison between weights.\n"
        "    Return value:\n"
        "      negative if `lhs < rhs`\n"
        "               null     if `lhs = rhs`\n"
        "               positive if `lhs > rhs`"
       }},

      {"complement",
       {"  AUT:automaton -> automaton",
        "  The complement of AUT.\n"
        "    Preconditions:\n"
        "      aut is lal\n"
        "      aut is Boolean\n"
        "      aut is deterministic\n"
        "      aut is complete"
       }},

      {"complement",
       {"  R:expression -> expression",
        "  Add the complement operator to R."
       }},

      {"complete",
       {"  AUT:automaton -> automaton",
        "  A completed copy of AUT.\n"
        "    Preconditions:\n"
        "      aut is lal"
       }},

      {"component",
       {"  AUT:automaton NUM:number -> automaton",
        "  The automaton of a strongly connected component.\n"
        "    Parameters:\n"
        "      AUT    the input automaton.\n"
        "      NUM    the component number."
       }},

      {"compose",
       {"  LHS:automaton RHS:automaton [LAZY=false:bool] -> automaton",
        "  The composition of transducers LHS and RHS.\n"
        "    Parameters:\n"
        "      LHS   the left transducer\n"
        "      RHS   the right transducer\n"
        "      LAZY  whether to perform the computations on demand."
       }},

      {"compose",
       {"   -> context",
        "  The composition of two contexts."
       }},

      {"compose",
       {"  LHS:expression RHS:expression -> expression",
        "  The composition of two expressions."
       }},

      {"compose",
       {"  LHS:label RHS:label -> label",
        "  The composition of two labels."
       }},

      {"compose",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  The composition of two polynomials."
       }},

      {"concatenate",
       {"  LHS:expression RHS:expression -> expression",
        "  Concatenate two expressions.\n"
        "    Do not use this routine, see multiply instead."
       }},

      {"condense",
       {"  AUT:automaton -> automaton",
        "  The condensation of AUT such that each state is a strongly\n"
        "    connected component."
       }},

      {"configuration",
       {"  KEY:string -> string",
        "  Access a configuration value."
       }},

      {"conjugate",
       {"  AUT:automaton -> automaton",
        "  The conjugate of AUT"
       }},

      {"conjunction",
       {"  LHS:automaton RHS:automaton [LAZY=false:bool] -> automaton",
        "  The conjunction (aka synchronized product) of automata.\n"
        "    Performs the meet of the contexts.\n"
        "    Parameters:\n"
        "      LHS   the left automaton\n"
        "      RHS   the right automaton\n"
        "      LAZY  whether to perform the computations on demand."
       }},

      {"conjunction",
       {"  AUT:automaton N:number -> automaton",
        "  Repeated conjunction of AUT with itself."
       }},

      {"conjunction",
       {"  LHS:expression RHS:expression -> expression",
        "  The Hadamard product of expressions LHS and RHS."
       }},

      {"conjunction",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  The Hadamard product of polynomials LHS and RHS."
       }},

      {"constant-term",
       {"  E:expression -> weight",
        "  The weight associated to the empty word in E."
       }},

      {"context-of",
       {"  A:automaton -> context",
        "  The context of this automaton."
       }},

      {"context-of",
       {"  R:expression -> context",
        "  The context of this expression."
       }},

      {"context-of",
       {"  R:polynomial -> context",
        "  The context of this polynomial."
       }},

      {"copy",
       {"  AUT:automaton -> automaton",
        "  A copy of AUT."
       }},

      {"copy",
       {"  AUT:automaton -> automaton",
        "  A copy of AUT converted to context CTX."
       }},

      {"copy",
       {"  EXP:expression IDS:identities -> expression",
        "  Copy of EXP, but built with CTX."
       }},

      {"costandard",
       {"  A:automaton -> automaton",
        "  A co-standardized A."
       }},

      {"cotrie",
       {"  P:polynomial -> automaton",
        "  A reversed trie-like automaton (multiple initial states,\n"
        "    single final state) automaton to accept P.\n"
        "    Parameters:\n"
        "      P    the polynomial that describes the (finite) series"
       }},

      {"de-bruijn",
       {"  N:number -> automaton",
        "  A simple NFA for (a+b)*a(a+b)^n."
       }},

      {"delay-automaton",
       {"  A:automaton -> automaton",
        "  The automaton with the delay of each state."
       }},

      {"derivation",
       {"  EXP:expression LBL:label [BREAKING=false:bool] -> polynomial",
        "  Derive EXP with respect to S.\n"
        "    Parameters:\n"
        "      EXP       the input expression\n"
        "      LBL       the label used for derivation\n"
        "      BREAKING  whether to split the result\n"
        "    Preconditions:\n"
        "       EXP must be LAL."
       }},

      {"derived-term",
       {"  EXP:expression [ALGO=\"auto\":string] -> automaton",
        "  The derived-term automaton of EXP.\n"
        "    Parameters:\n"
        "      EXP    the input expression\n"
        "      ALGO   how the derived terms are computed:\n"
        "         - \"auto\"                  alias for \"expansion\"\n"
        "         - \"derivation\"            compute by derivation\n"
        "         - \"breaking_derivation\"   compute by breaking derivation\n"
        "         - \"expansion\"             compute by expansion\n"
        "         - \"breaking_expansion\"    compute by breaking expansion"
       }},

      {"determinize",
       {"  AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  The determinized automaton.\n"
        "    Parameters:\n"
        "      AUT        the automaton to determinize\n"
        "      ALGO\n"
        "          - \"boolean\"     use efficient bitsets\n"
        "          - \"weighted\"    accept non Boolean automata (might not terminate)\n"
        "          - \"auto\"        \"boolean\" if the automaton is Boolean,\n"
        "                          \"weighted\" otherwise.\n"
        "    Preconditions:\n"
        "       the labelset of AUT must be free."
       }},

      {"difference",
       {"  LHS:automaton RHS:automaton -> automaton",
        "  An automaton whose behavior is that of LHS on words not\n"
        "    accepted by RHS.\n"
        "    Parameters:\n"
        "      LHS   a LAL automaton\n"
        "      RHS   a LAL Boolean automaton\n"
        "    Preconditions:\n"
        "      RHS is Boolean."
       }},

      {"difference",
       {"  LHS:expression RHS:expression -> expression",
        "  Words accepted by LHS, but not by RHS."
       }},

      {"divkbaseb",
       {"  DIVISOR:number BASE:number -> automaton",
        "  An automaton which accepts a word n representing a number in\n"
        "    base b iff k|n."
       }},

      {"eliminate-state",
       {"  AUT:automaton [S=-1:number] -> automaton",
        "  The LAO automaton AUT with state S removed."
       }},

      {"evaluate",
       {"  AUT:automaton L:word -> weight",
        "  Evaluate L on AUT."
       }},

      {"evaluate",
       {"  AUT:automaton P:polynomial -> weight",
        "  Evaluate P on AUT."
       }},

      {"expand",
       {"  E:expression -> expression",
        "  Distribute product over addition recursively under the starred\n"
        "    subexpressions and group the equal monomials."
       }},

      {"expression-one",
       {"  IDS:identities -> expression",
        "  The expression for `\\\\e`."
       }},

      {"expression-zero",
       {"  IDS:identities -> expression",
        "  The expression for `\\\\z`."
       }},

      {"factor",
       {"  AUT:automaton -> automaton",
        "  Create a factor automaton from AUT."
       }},

      {"focus",
       {"  AUT:automaton TAPE:number -> automaton",
        "  Focus on a specific tape of a tupleset automaton."
       }},

      {"has-bounded-lag",
       {"  AUT:automaton -> bool",
        "  Whether the transducer has bounded lag."
       }},

      {"has-lightening-cycle",
       {"  AUT:automaton -> bool",
        "  Whether the automaton has a cycle with lightening weight."
       }},

      {"has-twins-property",
       {"  AUT:automaton -> bool",
        "  Whether the automaton has the twins property."
       }},

      {"identities-of",
       {"  EXP:expression -> identities",
        "  The identities of expression EXP."
       }},

      {"inductive",
       {"  E:expression [ALGO=\"auto\":string] -> automaton",
        "  The inductive translation of E in an automaton.\n"
        "    Parameters:\n"
        "      E     the expressions\n"
        "      ALGO  how to compute the result\n"
        "        - \"standard\"    build a standard automaton.\n"
        "        - \"general\"     no requirement on the result\n"
        "        - \"auto\"        same as \"standard\""
       }},

      {"infiltrate",
       {"  LHS:automaton RHS:automaton -> automaton",
        "  The infiltration of automata LHS and RHS.\n"
        "    Performs the join of their types."
       }},

      {"infiltrate",
       {"  LHS:expression RHS:expression -> expression",
        "  The infiltration product of expressions LHS and RHS.\n"
        "    Performs the join of their type."
       }},

      {"infiltrate",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  The infiltration product of polynomial LHS and RHS."
       }},

      {"insplit",
       {"  AUT:automaton [LAZY=false:bool] -> automaton",
        "  Split automaton on the incoming transition.\n"
        "    In an insplit automaton, each state has either only\n"
        "    spontaneous incoming transitions or only proper incoming\n"
        "    transitions.\n"
        "    Parameters:\n"
        "      AUT   automaton to insplit\n"
        "      LAZY  whether to perform the computations on demand.\n"
        "    Preconditions:\n"
        "      aut is lal or lan."
       }},

      {"is-accessible",
       {"  AUT:automaton -> bool",
        "  Whether AUT is accessible."
       }},

      {"is-ambiguous",
       {"  AUT:automaton -> bool",
        "  Whether AUT is ambiguous.\n"
        "    Preconditions:\n"
        "      AUT is LAL."
       }},

      {"is-coaccessible",
       {"  AUT:automaton -> bool",
        "  Whether AUT is coaccessible."
       }},

      {"is-codeterministic",
       {"  AUT:automaton -> bool",
        "  Whether AUT is codeterministic.\n"
        "    Preconditions:\n"
        "      AUT is LAL."
       }},

      {"is-complete",
       {"  AUT:automaton -> bool",
        "  Whether AUT is complete.\n"
        "    Preconditions:\n"
        "      AUT is LAL."
       }},

      {"is-costandard",
       {"  AUT:automaton -> bool",
        "  Whether is costandard (unique final state, with weight one, no\n"
        "    outcoming transition)."
       }},

      {"is-cycle-ambiguous",
       {"  AUT:automaton -> bool",
        "  Whether the automaton is cycle-ambiguous."
       }},

      {"is-deterministic",
       {"  AUT:automaton -> bool",
        "  Whether AUT is deterministic.\n"
        "    Preconditions:\n"
        "      AUT is LAL."
       }},

      {"is-empty",
       {"  AUT:automaton -> bool",
        "  Whether has no state."
       }},

      {"is-eps-acyclic",
       {"  AUT:automaton -> bool",
        "  Whether has no cycle of spontaneous transitions."
       }},

      {"is-functional",
       {"  AUT:automaton -> bool",
        "  Whether AUT is functional.\n"
        "    Preconditions:\n"
        "      AUT is a transducer."
       }},

      {"is-letterized",
       {"  AUT:automaton -> bool",
        "  Whether AUT is letterized."
       }},

      {"is-normalized",
       {"  AUT:automaton -> bool",
        "  Whether is normalized (in the Thompson sense), i.e., standard\n"
        "    and co-standard."
       }},

      {"is-out-sorted",
       {"  AUT:automaton -> bool",
        "  Whether the outgoing transitions of each state have increasing labels."
       }},

      {"is-partial-identity",
       {"  AUT:automaton -> bool",
        "  Whether AUT realizes a partial identity.\n"
        "    Preconditions:\n"
        "      AUT is a transducer."
       }},

      {"is-proper",
       {"  AUT:automaton -> bool",
        "  Whether has no spontaneous transition."
       }},

      {"is-realtime",
       {"  AUT:automaton -> bool",
        "  Whether has no spontaneous transition, and is letterized."
       }},

      {"is-standard",
       {"  AUT:automaton -> bool",
        "  Whether is standard (unique initial state, with weight one, no\n"
        "    incoming transition)."
       }},

      {"is-synchronized",
       {"  AUT:automaton -> bool",
        "  Whether is synchronized."
       }},

      {"is-synchronized-by",
       {"  AUT:automaton WORD:word -> bool",
        "  Whether the word synchronizes aut."
       }},

      {"is-synchronizing",
       {"  AUT:automaton -> bool",
        "  Whether is synchronizing."
       }},

      {"is-trim",
       {"  AUT:automaton -> bool",
        "  Whether has no useless state."
       }},

      {"is-useless",
       {"  AUT:automaton -> bool",
        "  Whether has no useful state."
       }},

      {"is-valid",
       {"  E:automaton -> bool",
        "  Whether automaton is valid (epsilon-cycles converge)."
       }},

      {"is-valid",
       {"  E:expression -> bool",
        "  Whether rational expression is valid (all the starred\n"
        "    sub-expressions are starrable)."
       }},

      {"join",
       {"   -> context",
        "  The join between two contexts, i.e., their lowest common supertype."
       }},

      {"ladybird",
       {"  N:number -> automaton",
        "  The ladybird automaton with N states."
       }},

      {"ldivide",
       {"  LHS:automaton RHS:automaton -> automaton",
        "  Left-division of two automata (lhs \\ rhs)."
       }},

      {"ldivide",
       {"  LHS:expression RHS:expression -> expression",
        "  Left-division of two expressions (lhs \\ rhs)."
       }},

      {"ldivide",
       {"  LHS:label RHS:label -> label",
        "  Left-division of two labels (lhs \\ rhs)."
       }},

      {"ldivide",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  Left-division of two polynomials (lhs \\ rhs)."
       }},

      {"ldivide",
       {"  LHS:weight RHS:weight -> weight",
        "  Left-division of two weights (lhs \\ rhs)."
       }},

      {"less-than",
       {"  LHS:automaton RHS:automaton -> bool",
        "  Ordering between automata."
       }},

      {"less-than",
       {"  LHS:expression RHS:expression -> bool",
        "  Ordering between expressions."
       }},

      {"letterize",
       {"  AUT:automaton -> automaton",
        "  The automaton with letter transitions instead of words."
       }},

      {"levenshtein",
       {"   -> automaton",
        "  The transducer representing the Levenshtein distance."
       }},

      {"lgcd",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  Left greatest common divisor of two polynomials (lhs \\ rhs)."
       }},

      {"lift",
       {"  AUT:automaton -> automaton",
        "  Lift some tapes of the transducer, or turn an automaton into a\n"
        "    spontaneous automaton.\n"
        "    Each `<k>l` transition is mapped to a `<<k>l>\\\\e` transition.\n"
        "    Parameters:\n"
        "      AUT    the input automaton"
       }},

      {"lift",
       {"  E:expression -> expression",
        "  The lifted LAO rational expression from E."
       }},

      {"lightest",
       {"  AUT:automaton [NUM=1:number] [ALGO=\"auto\":string] -> polynomial",
        "  The approximated behavior of an automaton with smallest weights.\n"
        "    Parameters:\n"
        "      AUT   the automaton whose behavior to approximate\n"
        "      NUM   number of words looked for.\n"
        "      ALGO  the specific algorithm to use"
       }},

      {"lightest-automaton",
       {"  AUT:automaton [NUM=1:number] [ALGO=\"auto\":string] -> automaton",
        "  The shortest path automaton using the given algorithm."
       }},

      {"lweight",
       {"  W:weight AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  The left-multiplication of an automaton with W as weight.\n"
        "    Parameters:\n"
        "      W     the weight to left-multiply\n"
        "      AUT   the input automaton.\n"
        "      ALGO  how to compute the result.\n"
        "        - \"standard\"    AUT is standard,\n"
        "                        build a standard automaton.\n"
        "        - \"general\"     no requirement on AUT,\n"
        "                        but add spontaneous transitions.\n"
        "        - \"auto\"        \"standard\" if AUT is standard,\n"
        "                        \"general\" otherwise."
       }},

      {"lweight",
       {"  W:weight EXP:expression -> expression",
        "  The left-multiplication of an expression with W as weight."
       }},

      {"lweight",
       {"  W:weight P:polynomial -> polynomial",
        "  The left-multiplication of a polynomial with W as weight."
       }},

      {"minimize",
       {"  AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  The minimized automaton.\n"
        "    Parameters:\n"
        "      AUT       the automaton to minimize\n"
        "      ALGO      the specific algorithm to use\n"
        "    Preconditions:\n"
        "       AUT must be LAL.\n"
        "       AUT must be deterministic."
       }},

      {"multiply",
       {"  LHS:automaton RHS:automaton [ALGO=\"auto\":string] -> automaton",
        "  Multiply (concatenate) two automata.\n"
        "    Parameters:\n"
        "      LHS   an automaton.\n"
        "      RHS   another one.\n"
        "      ALGO  how to compute the result\n"
        "        - \"standard\"    both LHS and RHS are standard,\n"
        "                        build a standard automaton.\n"
        "        - \"general\"     no requirement on LHS and and RHS,\n"
        "                        but add spontaneous transitions.\n"
        "        - \"auto\"        \"standard\" if both automata are standard,\n"
        "                        \"general\" otherwise."
       }},

      {"multiply",
       {"  AUT:automaton MIN:number [MAX=-2:number] [ALGO=\"auto\":string] -> automaton",
        "  Repeated multiplication (concatenation) of an automaton with itself.\n"
        "    Parameters:\n"
        "      AUT  the automaton.\n"
        "      MIN  the minimum number.  If -1, denotes 0.\n"
        "      MAX  the maximum number.\n"
        "           If -1, denotes infinity, using star.\n"
        "           If -2, denotes the same value as min.\n"
        "      ALGO  how to compute the result\n"
        "        - \"standard\"    AUT is standard,\n"
        "                        build a standard automaton.\n"
        "        - \"general\"     no requirement on AUT,\n"
        "                        but add spontaneous transitions.\n"
        "        - \"auto\"        \"standard\" if AUT is standard,\n"
        "                        \"general\" otherwise."
       }},

      {"multiply",
       {"  LHS:expression RHS:expression -> expression",
        "  Multiply (concatenate) two expressions."
       }},

      {"multiply",
       {"  E:expression MIN:number [MAX=-2:number] -> expression",
        "  Repeated multiplication (concatenation) of an expression with itself.\n"
        "    Parameters:\n"
        "      E    the expression.\n"
        "      MIN  the minimum number.  If -1, denotes 0.\n"
        "      MAX  the maximum number.\n"
        "           If -1, denotes infinity, using star.\n"
        "           If -2, denotes the same value as min."
       }},

      {"multiply",
       {"  LHS:label RHS:label -> label",
        "  Multiply (concatenate) two labels."
       }},

      {"multiply",
       {"  L:label NUM:number -> label",
        "  Repeated multiplication of a label with itself.\n"
        "    Parameters:\n"
        "      L    the label.\n"
        "      NUM  the exponent."
       }},

      {"multiply",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  Multiply two polynomials."
       }},

      {"multiply",
       {"  LHS:weight RHS:weight -> weight",
        "  Multiply two weights."
       }},

      {"multiply",
       {"  E:weight MIN:number [MAX=-2:number] -> weight",
        "  Repeated multiplication of a weight with itself.\n"
        "    Parameters:\n"
        "      E    the weight.\n"
        "      MIN  the minimum number.  If -1, denotes 0.\n"
        "      MAX  the maximum number.\n"
        "           If -1, denotes infinity, using star.\n"
        "           If -2, denotes the same value as min."
       }},

      {"name",
       {"  EXP:expression NAME:string -> expression",
        "  Name an expression."
       }},

      {"normalize",
       {"  AUT:automaton -> automaton",
        "  Normalize automaton AUT."
       }},

      {"num-components",
       {"  AUT:automaton -> number",
        "  The number of strongly connected components."
       }},

      {"num-tapes",
       {"   -> number",
        "  The number of input tapes.\n"
        "    Return value:\n"
        "      0 if the context is not tupleset."
       }},

      {"pair",
       {"  AUT:automaton [KEEP_INITIALS=false:bool] -> automaton",
        "  Build the pair automaton of the given automaton"
       }},

      {"partial-identity",
       {"  AUT:automaton -> automaton",
        "  Create a partial identity transducer from AUT."
       }},

      {"partial-identity",
       {"  E:expression -> expression",
        "  Create a partial-identity two-tape expression from E."
       }},

      {"prefix",
       {"  AUT:automaton -> automaton",
        "  Create a prefix automaton from AUT."
       }},

      {"project",
       {"  AUT:automaton TAPE:number -> automaton",
        "  Keep a single tape from a multiple-tape automaton."
       }},

      {"project",
       {"  TAPE:number -> context",
        "  Keep a single tape from a multiple-tape context."
       }},

      {"project",
       {"  EXP:expression TAPE:number -> expression",
        "  Keep a single tape from a multiple-tape expression."
       }},

      {"project",
       {"  P:polynomial TAPE:number -> polynomial",
        "  Keep a single tape from a multiple-tape polynomial."
       }},

      {"project",
       {"  P:label TAPE:number -> label",
        "  Keep a single tape from a multiple-tape label."
       }},

      {"proper",
       {"  AUT:automaton -> automaton",
        "  An equivalent automaton without spontaneous transitions.\n"
        "    Parameters:\n"
        "      AUT    the automaton in which to remove them"
       }},

      {"push-weights",
       {"  AUT:automaton -> automaton",
        "  The weight pushing automaton of AUT."
       }},

      {"quotkbaseb",
       {"  DIVISOR:number BASE:number -> automaton",
        "  A transducer that computes the quotient of the division\n"
        "    of a word n by k in base b iff k|n."
       }},

      {"random-automaton",
       {"  NUM_STATES:number [DENSITY=0.1:float] [NUM_INITIAL=1:number] [NUM_FINAL=1:number] [MAX_LABELS:number] [LOOP_CHANCE=0.0:float] [WEIGHTS=\"\":string] -> automaton",
        "  A random automaton.\n"
        "    Parameters:\n"
        "      NUM_STATES\n"
        "         The number of states wanted in the automata\n"
        "         (>0).  All states will be connected, and there will be no dead\n"
        "         state.  However, some might not be coaccessible.\n"
        "      DENSITY\n"
        "         The density of the automata.  This is the probability\n"
        "         (between 0.0 and 1.0), to add a transition between two\n"
        "         states.  All states have at least one outgoing transition,\n"
        "         so D is considered only when adding the remaining transition.\n"
        "         A density of 1 means all states will be connected to each other.\n"
        "      NUM_INITIAL\n"
        "         The number of initial states wanted (0 <= num_initial <= num_states)\n"
        "      NUM_FINAL\n"
        "         The number of final states wanted (0 <= num_final <= num_states)\n"
        "      MAX_LABELS\n"
        "         The maximum number of labels per transition.  Defaults to the\n"
        "         number of generators.\n"
        "      LOOP_CHANCE\n"
        "         The probability (between 0.0 and 1.0) for each state to have\n"
        "         a loop.\n"
        "      WEIGHTS\n"
        "         The specification string (following the format of random_weight) used\n"
        "         to generate weights on each transitions."
       }},

      {"random-automaton-deterministic",
       {"  NUM_STATES:number -> automaton",
        "  A random deterministic automaton.\n"
        "    Parameters:\n"
        "      NUM_STATES\n"
        "         The number of states wanted in the automata (>0)."
       }},

      {"random-expression",
       {"  [PARAM=\"+, ., *=.2, w., .w, length=10\":string] [IDS={}:identities] -> expression",
        "  A random expression.\n"
        "    Parameters:\n"
        "      PARAM\n"
        "         A specification of the wanted operators and their relative\n"
        "         probability.  May also contain the maximum number of\n"
        "         symbols of the expression with key `length`.  For instance:\n"
        "         \"+=1,.=2,{T}=0.5,length=6\".\n"
        "      IDS\n"
        "         The identities to use for the expression."
       }},

      {"random-weight",
       {"  PARAM:string -> weight",
        "  A random weight.\n"
        "    Parameters:\n"
        "      PARAM\n"
        "         A string containing paramaters for the generation such as the\n"
        "         min and max, or an element you want with specific probability.\n"
        "         For instance: \"1=0.2, 10=0.3, min=0, max=20\"."
       }},

      {"rdivide",
       {"  LHS:automaton RHS:automaton -> automaton",
        "  Right-division of two automata (lhs / rhs)."
       }},

      {"rdivide",
       {"  LHS:expression RHS:expression -> expression",
        "  Right-division of two expressions (lhs / rhs)."
       }},

      {"rdivide",
       {"  LHS:label RHS:label -> label",
        "  Right-division of two labels (lhs / rhs)."
       }},

      {"rdivide",
       {"  LHS:weight RHS:weight -> weight",
        "  Right-division of two weights (lhs / rhs)."
       }},

      {"realtime",
       {"  AUT:automaton -> automaton",
        "  Create the realtime automaton (letterized and proper)."
       }},

      {"reduce",
       {"  AUT:automaton -> automaton",
        "  Reduce AUT."
       }},

      {"rweight",
       {"  AUT:automaton W:weight [ALGO=\"auto\":string] -> automaton",
        "  The right-mult automaton with W as weight.\n"
        "    Parameters:\n"
        "      AUT   the input automaton.\n"
        "      W     the weight to right-multiply\n"
        "      ALGO  how to compute the result.\n"
        "            In most cases, \"standard\" and \"general\" have\n"
        "            equal results.  The only difference in when\n"
        "            when W is null, in which case \"general\"\n"
        "            produces an empty automaton, while \"standard\"\n"
        "            produces an automaton with a single state, which\n"
        "            is initial (and, of course, no final states).\n"
        "        - \"standard\"    AUT is standard,\n"
        "                        build a standard automaton.\n"
        "        - \"general\"     no requirement on AUT,\n"
        "                        but add spontaneous transitions.\n"
        "        - \"auto\"        \"standard\" if AUT is standard,\n"
        "                        \"general\" otherwise."
       }},

      {"rweight",
       {"  EXP:expression W:weight -> expression",
        "  The right-multiplication of an expression with W as weight."
       }},

      {"rweight",
       {"  P:polynomial W:weight -> polynomial",
        "  The right-multiplication of a polynomial with W as weight."
       }},

      {"scc",
       {"  AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  Build the SCC automaton whose states are labeled with number\n"
        "    of the strongly-connected component they belong to.\n"
        "    Parameters:\n"
        "      AUT    the input automaton.\n"
        "      ALGO   the specific algorithm to use."
       }},

      {"shortest",
       {"  AUT:automaton [NUM:number] [LEN:number] -> polynomial",
        "  The approximated behavior of an automaton.\n"
        "    Parameters:\n"
        "      AUT   the automaton whose behavior to approximate\n"
        "      NUM   number of words looked for.\n"
        "      LEN   maximum length of words looked for."
       }},

      {"shuffle",
       {"  LHS:automaton RHS:automaton -> automaton",
        "  The shuffle product of automata LHS and RHS.\n"
        "    Performs the join of their type."
       }},

      {"shuffle",
       {"  LHS:expression RHS:expression -> expression",
        "  The shuffle product of expressions LHS and RHS.\n"
        "    Performs the join of their type."
       }},

      {"shuffle",
       {"  LHS:polynomial RHS:polynomial -> polynomial",
        "  The shuffle product of polynomial LHS and RHS."
       }},

      {"sort",
       {"  A:automaton -> automaton",
        "  A copy of A with normalized state numbers."
       }},

      {"split",
       {"  EXP:expression -> polynomial",
        "  Break EXP."
       }},

      {"split",
       {"  P:polynomial -> polynomial",
        "  Break all the expressions in P."
       }},

      {"standard",
       {"  A:automaton -> automaton",
        "  A standardized A."
       }},

      {"standard",
       {"  E:expression -> automaton",
        "  The standard automaton of E."
       }},

      {"star",
       {"  AUT:automaton [ALGO=\"auto\":string] -> automaton",
        "  Star of an automaton.\n"
        "    Parameters:\n"
        "      AUT   the input automaton.\n"
        "      ALGO  how to compute the result.\n"
        "        - \"standard\"    AUT is standard,\n"
        "                        build a standard automaton.\n"
        "        - \"general\"     no requirement on AUT,\n"
        "                        but add spontaneous transitions.\n"
        "        - \"auto\"        \"standard\" if AUT is standard,\n"
        "                        \"general\" otherwise."
       }},

      {"star-height",
       {"  RS:expression -> number",
        "  Star height of an expression."
       }},

      {"star-normal-form",
       {"  E:expression -> expression",
        "  A normalized form where star is applied only to proper\n"
        "    expressions.\n"
        "    Preconditions:\n"
        "      E is Boolean."
       }},

      {"strip",
       {"  A:automaton -> automaton",
        "  The automaton in A with its metadata layers removed."
       }},

      {"subword",
       {"  AUT:automaton -> automaton",
        "  Create a subword automaton from AUT.\n"
        "    For each non-spontaneous transition, add a spontaneous\n"
        "    transition with same source, destination, and weight."
       }},

      {"suffix",
       {"  AUT:automaton -> automaton",
        "  Create a suffix automaton from AUT."
       }},

      {"synchronize",
       {"  AUT:automaton -> automaton",
        "  Create a synchronized transducer from AUT."
       }},

      {"synchronizing-word",
       {"  AUT:automaton [ALGO=\"greedy\":string] -> word",
        "  A synchronizing word, or raise if there is none."
       }},

      {"thompson",
       {"  E:expression -> automaton",
        "  The Thompson automaton of E."
       }},

      {"to-automaton",
       {"  EXP:expression [ALGO=\"auto\":string] -> automaton",
        "  An automaton denoting the language of EXP.\n"
        "    Parameters:\n"
        "      EXP   the expression defining the series.\n"
        "      ALGO  the conversion algorithm.\n"
        "        - \"auto\": currently equivalent to \"expansion\", eventually should\n"
        "           mix \"standard\" for basic expressions (faster) and \"expansion\"\n"
        "           otherwise (more general).\n"
        "        - \"derivation\": use derivation-based expression.derived_term,\n"
        "           stripped.\n"
        "        - \"derived_term\": same as \"expansion\"\n"
        "        - \"expansion\": use expansion-based expression.derived_term, stripped.\n"
        "        - \"inductive\": use expression.inductive\n"
        "        - \"standard\": use expression.standard.\n"
        "        - \"thompson\": use expression.thompson.\n"
        "        - \"zpc\": use expression.zpc.\n"
        "        - \"zpc,compact\": use expression.zpc, \"compact\" version."
       }},

      {"to-expansion",
       {"  EXP:expression -> expansion",
        "  First order development of a EXP.\n"
        "    Parameters:\n"
        "      EXP              the input expression"
       }},

      {"to-expression",
       {"  AUT:automaton [IDS={}:identities] [ALGO=\"auto\":string] -> expression",
        "  An expression denoting the language of AUT.\n"
        "    Parameters:\n"
        "      AUT   the input automaton\n"
        "      IDS   the identities to use for the expression\n"
        "      ALGO  the state selection strategy"
       }},

      {"to-expression",
       {"  IDS:identities L:label -> expression",
        "  An expression denoting the label of L."
       }},

      {"transpose",
       {"  AUT:automaton -> automaton",
        "  Transpose AUT."
       }},

      {"transpose",
       {"  E:expression -> expression",
        "  Transpose E."
       }},

      {"transposition",
       {"  R:expression -> expression",
        "  Add the transposition operator to R."
       }},

      {"trie",
       {"  P:polynomial -> automaton",
        "  A trie-like automaton (single initial state, multiple final\n"
        "    states) to accept P.\n"
        "    Parameters:\n"
        "      P    the polynomial that describes the (finite) series"
       }},

      {"trim",
       {"  AUT:automaton -> automaton",
        "  The trim subautomaton of AUT."
       }},

      {"tuple",
       {"  LHS:automaton RHS:automaton -> automaton",
        "  Build a two-tape automaton from two automata.\n"
        "    Parameters:\n"
        "      LHS   the left automaton\n"
        "      RHS   the right automaton"
       }},

      {"tuple",
       {"   -> context",
        "  Tuple two contexts."
       }},

      {"tuple",
       {"  LHS:expression RHS:expression -> expression",
        "  Build a two-tape expression from two expressions."
       }},

      {"type",
       {"  A:automaton -> string",
        "  The implementation type of a."
       }},

      {"u",
       {"  N:number -> automaton",
        "  The Brzozowski universal witness."
       }},

      {"universal",
       {"  AUT:automaton -> automaton",
        "  The universal automaton of AUT."
       }},

      {"weight-one",
       {"   -> weight",
        "  The weight one."
       }},

      {"weight-series",
       {"  AUT:automaton -> weight",
        "  Compute weight of the series"
       }},

      {"weight-zero",
       {"   -> weight",
        "  The weight zero."
       }},

      {"zpc",
       {"  EXP:expression [ALGO=\"auto\":string] -> automaton",
        "  The ZPC automaton of EXP.\n"
        "    Parameters:\n"
        "      EXP    the expression to build the automaton from.\n"
        "      ALGO   the specific algorithm to use.\n"
        "             It can be \"regular\"/\"auto\" or the variant \"compact\"."
       }},
    };
  }
}
