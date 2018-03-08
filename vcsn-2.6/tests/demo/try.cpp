#include <iostream> //std::cout
#include <ctime>
#include <vector>
#include <string>
#include <iterator>
#include <random>


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

using namespace vcsn;

char randomletter_generator() {
	srand((int)time(0));
	char randomletter  = 'a' + rand() % 26 ; 
	return randomletter ; 
}


auto create_context() {
	using alphabet_t = set_alphabet<char_letters>;   // Basic alphabet type.
	using letterset_t = letterset<alphabet_t>;       // Letterset (single-tape labelset).
	auto ls1 = letterset_t{'a'};                     // Create the letterset.
	using labelset_t = tupleset<letterset_t, letterset_t>; // Labelset (double-tape).
	auto ls = labelset_t{ls1, ls1};                  // Create the double-tape labelset.
	using context_t = context<labelset_t, b>;        // Context of the automaton: lat<lal_char, lal_char>, b.
	
	// Create the context from the labelset.
	// No parameter for the weightset, as it's just B.
	auto ctx = context_t{ls};
	return ctx  ; 
}

/* 1. Create number of states demanded : DONE 
   2. Choose randomly the initial and final states 
   3. Connect with transitions while respecting the properties
*/ 


/*auto generate_context() {
	//using namespace vcsn::dyn ;
	auto a1 = make_automaton("context = lat<lal_char(abc), lal_char(def)>, b\n", "daut");
	auto ctx = context_of(a1);
	return ctx ;

} */ 

void generator(int num_states, int init_states, int final_states) {
	auto ctx = create_context() ; 
	// Create an empty automaton (transducer), from the context.
	auto t = make_mutable_automaton(ctx);

	// Add a state.
	// p is a state identifier, probably 0
	auto p = t->new_state() ; 

	//t->print_state_name(p) ; 
	auto q = t->new_state();
	auto r = t->new_state();


	// Make p initial.
	t->set_initial(p);
	// Transition from p to q, with label "a|a".
	t->new_transition(p, q, ctx.labelset()->tuple('a', 'a'));
	t->new_transition(q, r, ctx.labelset()->tuple('b', 'c'));
	// Make q final
	t->set_final(q);

	//info(t) ; 

	/*char letter = randomletter_generator() ; 
	std::cout << letter  ; */ 

	//dot(t, std::cout) << '\n';

}

template <typename Ctx>
mutable_automaton<Ctx>
generate_states(auto ctx, unsigned num_states, auto aut) {

	using automaton_t = mutable_automaton<Ctx>;
	using state_t = state_t_of<automaton_t>;

	std::vector<state_t> states;

	for (unsigned i = 0; i < num_states; ++i)
	  	states.push_back(aut->new_state());

	/*for (unsigned i = 0; i < num_states; ++i) {
		bool la = true;
		
		for (auto l : ctx.labelset()->generators()) {
			auto dest = (la || i == num_states - 1) ? (i + 1) % num_states : i;
			aut->add_transition(states[i], states[dest], l, ctx.weightset()->one());
			la = false;
		}
	}

	aut->set_initial(states[0]);
	aut->set_final(states[0]); */ 

	return states;
}

/*template <typename Ctx>
mutable_automaton<Ctx>
generate_initial_and_final_states(auto ctx, unsigned num_states, unsigned n, auto aut, auto list_states) { 
	int counter ; 
	counter = num_states
	while (counter > 0) {
		int s = rand_int(1,num_states) ; 
		if (rand_int(1,2) == 1 && )
	}

} */

void in_list(auto states) {
	for ( auto i = states.begin(); i != states.end(); i++ ) {
    	std::cout << *i << std::endl;

   	}
}

int rand_int(int min, int max) {

	using namespace std;
	default_random_engine gen;
	uniform_int_distribution dist(min,max);
	int random_number_one = dist(gen);
	
	return random_number_one ;

}

int main(){
	
	generator(4, 1, 1);

}


