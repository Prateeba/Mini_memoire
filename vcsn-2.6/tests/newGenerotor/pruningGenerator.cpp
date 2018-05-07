#include <iostream> //std::cout
#include <stdio.h> 
#include <fstream>  
#include <string> 

#include <vcsn/algos/dot.hh> // display algorithm
#include <vcsn/algos/copy.hh> // display algorithm
#include <vcsn/alphabets/char.hh> // type of letter
#include <vcsn/alphabets/setalpha.hh> // alphabet
#include <vcsn/core/automaton.hh> // all_transitions
#include <vcsn/algos/random-automaton.hh>
#include <vcsn/labelset/tupleset.hh> // tupleset
#include <vcsn/labelset/letterset.hh> // letterset
#include <vcsn/weightset/b.hh> // weightset b
#include <vcsn/misc/irange.hh>
#include <vcsn/misc/random.hh>
#include <vcsn/algos/info.hh>
#include <vcsn/dyn/algos.hh>
#include <vcsn/algos/is-deterministic.hh>
#include <vcsn/algos/is-functional.hh>
#include <vcsn/algos/has-twins-property.hh>
#include <vcsn/algos/accessible.hh>



using namespace vcsn;
auto create_context() {
	
	// Basic alphabet type.
	using alphabet_t = set_alphabet<char_letters>;

	// Letterset (single-tape labelset).
	using letterset_t = letterset<alphabet_t>;

	// Create the letterset.
	auto ls1 = letterset_t{'a', 'b', 'c'};

	// Labelset (double-tape).
	using labelset_t = tupleset<letterset_t, letterset_t>;

	// Create the double-tape labelset.
	const auto ls = labelset_t{ls1, ls1};

	// Context of the automaton: lat<lal_char, lal_char>, b.
	using context_t = context<labelset_t, b>;

	// Create the context from the labelset.
	// No parameter for the weightset, as it's just B.
	const auto ctx = context_t{ls};
	return ctx  ; 
} 

bool random_generator(int num_states, int num_initial_states, int num_final_states) {
	/* Uses the random automata generator of vaucanson */

	/* Create a context */ 
	auto ctx = create_context() ; 
	
	/* Generate a near complete automata/transducer */ 
	auto res = random_automaton(ctx, num_states, 0.02, num_initial_states, num_final_states, 1) ; 
	
	/* Get all transitions of the automata */ 
	auto t_list = all_transitions(res) ; 
	int size_transition =  t_list.size() ; 
	/* counter of useful states*/ 
	int initial_num_useful_states = 0  ;
	bool found = false ; 

	/* Create a random transition selector */ 
	auto select = make_random_selector(make_random_engine());

	while (size_transition > 0 && !found){ 
		
		/* Test if the random transducer generated respect the properties */ 
		if ( !(is_cycle_ambiguous(res)) && is_functional(res) && has_twins_property(res) && !(is_deterministic(res)) && num_useful_states(res) == num_states ) {
			found = true ; 
			vcsn::dot(res, std::cout) << '\n';
		}

		else {
			/* Pruning */
			/* Choose a random transition t and Test if Transducer - t respect the properties  */ 
			auto t = select(t_list);
			res->del_transition(t) ;
			size_transition -- ;   
			std::cout << "size_transition" << size_transition << "\n" ; 
			initial_num_useful_states = num_useful_states(res) ; 	
		}
	} 
	return found ;
}

int main() {
	bool result = random_generator(300,50,41) ; 
	while (!result) { 
		result = random_generator(300,50,41) ; 
	}

	return 0 ;
} 



