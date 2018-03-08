#include <iostream> //std::cout
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

#include <vcsn/ctx/lal_char_b.hh>
#include <vcsn/alphabets/char.hh> // type of letter
#include <vcsn/alphabets/setalpha.hh> // alphabet
#include <vcsn/labelset/tupleset.hh> // tupleset
#include <vcsn/labelset/letterset.hh> // letterset
#include <vcsn/labelset/labelset.hh>
#include <vcsn/algos/make-context.hh>

/* Algo to implement  : 
	Create states : DONE 
	Create right context : ...
	Link states with transitions : ... */ 

 
int main(int argc, char *argv[]) {

	/*auto a1 = vcsn::dyn::make_automaton("context = lat<lal_char(abc), lal_char(def)>, b\n", "daut");
	auto ctx_dyn = context_of(a1); */ 

	//auto ctx = vcsn::ctx::lal_char_b(); 

	using namespace vcsn;

	// Basic alphabet type.
	using alphabet_t = set_alphabet<char_letters>;

	// Letterset (single-tape labelset).
	using letterset_t = letterset<alphabet_t>;

	// Create the letterset.
	auto ls1 = letterset_t{'a'};

	// Labelset (double-tape).
	using labelset_t = tupleset<letterset_t, letterset_t>;

	// Create the double-tape labelset.
	auto ls = labelset_t{ls1, ls1};


	// Context of the automaton: lat<lal_char, lal_char>, b.
	using context_t = context<labelset_t, b>;

	// Create the context from the labelset.
	// No parameter for the weightset, as it's just B.
	auto ctx = context_t{ls};

	auto aut = vcsn::make_mutable_automaton(ctx); 
	auto init_state = aut->new_state();
	auto s1 = aut->new_state();
	auto s2 = aut->new_state();
	auto final_state = aut->new_state();


	aut->set_initial(init_state);
	aut->set_final(final_state);

	/*auto label = ctx.labelset()->generators() ; 
	std::cout << label ; */ 

 

	

	return 0 ; 
}