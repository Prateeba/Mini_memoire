#include <iostream> //std::cout
#include <vector>
#include <ratio>

#include <vcsn/alphabets/char.hh> // type of letter
#include <vcsn/alphabets/setalpha.hh> // alphabet
#include <vcsn/algos/compose.hh> // composition algorithm
#include <vcsn/algos/dot.hh> // display algorithm
#include <vcsn/labelset/tupleset.hh> // tupleset
#include <vcsn/labelset/letterset.hh> // letterset
#include <vcsn/weightset/b.hh> // weightset b
#include <vcsn/algos/has-twins-property.hh>
#include <vcsn/algos/is-complete.hh>
#include <vcsn/algos/strip.hh>
#include <vcsn/algos/random-automaton.hh>
#include <vcsn/algos/is-deterministic.hh>
#include <vcsn/algos/info.hh>
#include <vcsn/algos/is-functional.hh>
#include <vcsn/ctx/context.hh>
#include <vcsn/core/mutable-automaton.hh> 

using namespace vcsn::dyn ;

auto random_generator(int num_states, int num_initial_states, int num_final_states) {
	/* Uses the random automata generator of vaucanson */

	auto a1 = make_automaton("context = lat<lal_char(abc), lal_char(def)>, b\n", "daut");
	auto ctx = context_of(a1);
	auto res = random_automaton(ctx, num_states, 1, num_initial_states, num_final_states, 1) ; 

	return res ; 
}

int main() {

	std::cout << "Heloo" ; 
	auto res = random_generator(6,3,2) ;
	auto transitions = all_transitions(res) ;  
 
	
} 



