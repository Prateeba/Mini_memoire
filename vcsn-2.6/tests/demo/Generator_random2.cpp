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

int random_generator(int num_states, int num_initial_states, int num_final_states, int index) {
	/* Uses the random automata generator of vaucanson */

	/* Create a context */ 
	auto ctx = create_context() ; 
	
	/* Generate a near complete automata/transducer */ 
	auto res = random_automaton(ctx, num_states, 1, num_initial_states, num_final_states, 1) ; 
	

	/* Get all transitions of the automata */ 
	auto t_list = all_transitions(res) ; 
	int size_transition =  t_list.size() ; 

	/* Create a random transition selector */ 
	auto select = make_random_selector(make_random_engine());
	
	int counter_good = 0 ; 
	/* Pruning */
	while (size_transition > 0 ){ 
		
		/* Choose a random transition */ 
		auto t = select(all_transitions(res));
		
		/* Test if T - t respect the properties  */ 
		if ( !(is_cycle_ambiguous(res)) && (is_functional(res)) && (has_twins_property(res))) {
			// Normally suppose to return the automaton at this point  
			break ; 
		}

		else {
			res->del_transition(t) ;
			t = select(all_transitions(res)); 
			size_transition = all_transitions(res).size() ;    			
		}
	} 

	/* Returns only non deterministic good example */ 
	if ( !(is_cycle_ambiguous(res)) && (is_functional(res)) && (has_twins_property(res)) && !(is_deterministic(res)) ) {
		counter_good += 1 ; 

		/* std::ofstream myfile;
		std::stringstream ss;
		ss << "./Results2/" << "file" << std::to_string(index) << ".txt" ; 
		std::string s = ss.str();
		
		myfile.open(s);
		myfile << vcsn::dot(res, std::cerr) << '\n';
		myfile.close(); */ 
		//info(trim(res)) ;   
	  	vcsn::dot(res, std::cout) << '\n';
	}

	return counter_good ;
}



int main() {
	int i = 0 ; 
	int max  = 1000 ; 
	int count = 0 ; 
	while (i < max) {
		std::cout << i << "\n" ; 
		count += random_generator(20,13,15,i) ;  
		i += 1 ; 
	}

	std::cout << "Number of good example : "<< count << "\n" ; 
	std::cout << "Good example ratio : "<< double(count) /double(max) << "\n" ;
	
	return 0 ;
} 



