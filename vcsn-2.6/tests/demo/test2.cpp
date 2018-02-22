#include <stack>

#include <vcsn/algos/accessible.hh> // vcsn::trim
#include <vcsn/algos/is-ambiguous.hh> // is_cycle_ambiguous
#include <vcsn/algos/conjunction.hh> // conjunction
#include <vcsn/algos/scc.hh>
#include <vcsn/dyn/automaton.hh>
#include <vcsn/concepts/automaton.hh> // Automaton
#include <vcsn/dyn/fwd.hh>
#include <vcsn/labelset/tupleset.hh>
#include <vcsn/algos/dot.hh> // display algorithm
#include <vcsn/misc/unordered_map.hh> // vcsn::has

int main() {
	

	auto a1 = vcsn::dyn::make_automaton("context = lal, q\n"
							 "$ 0 <1/2>\n"
							 "0 1 <2>a, <6>b\n"
							 "1 $\n", "daut");

	auto res = vcsn::algos::accessible_states(a1) ; 
	vcsn::dot(res, std::cout) << '\n';

}