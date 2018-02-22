#include <iostream> //std::cout
#include <stdlib.h>
#include <vector>

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

using namespace vcsn::dyn ;

auto random_generator(int num_states, int num_initial_states, int num_final_states) {
	/* Uses the random automata generator of vaucanson */
	auto a1 = make_automaton("context = lat<lal_char(abc), lal_char(def)>, b\n", "daut");
	auto ctx = context_of(a1);
	auto res = random_automaton(ctx, num_states, 0.1, num_initial_states, num_final_states) ; 

	return res ; 

}

void generator(int num_states, int num_initial_states, int num_final_states) {
	/* Generate a transducer, test if it is deterministic : 
		if yes : 
			Re generate another transducer 
		if No : 
			Test if the transducer is functional and is determinisable 
	*/

	auto res = random_generator(num_states, num_initial_states, num_final_states) ;  
	int good_example_counter = 0 ; 

	if (good_example_counter >= 5) {
		return ;  
	}

	else {

		if (is_deterministic(res)) {   
			generator(num_states, num_initial_states, num_final_states) ;  
			//res = random_generator(num_states, num_initial_states, num_final_states) ;
		}
			
		else {  
			if (!(is_cycle_ambiguous(res))){

				if ( is_functional(res) && has_twins_property(res) ) {
					good_example_counter ++ ; 
					print(res) ; 
				}

				else {
					generator(num_states, num_initial_states, num_final_states) ; 
					//res = random_generator(num_states, num_initial_states, num_final_states) ;
				
				}
			}		
		}
	}
} 
 

int main(int argc, char *argv[]) {

	if (argc < 4) {
		std::cout << "Missing arguments " ;  
	}

	int count_loop = 1000 ; 
	int counter = 0 ; 
	
	while (counter < count_loop) {
		/* num_states, num_initial_states, num_final_states */
		generator(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])) ;
		counter ++ ; 
	}
	
} 

