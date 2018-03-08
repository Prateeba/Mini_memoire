#pragma once

#include <iostream> //std::cout
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

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
#include <vcsn/algos/make-context.hh>
#include <vcsn/ctx/context.hh>
#include <vcsn/dyn/automaton.hh>
#include <vcsn/dyn/algos.hh>
#include <vcsn/core/expression-automaton.hh>
#include <vcsn/core/rat/expression.hh>


#include <vcsn/algos/accessible.hh>
#include <vcsn/algos/has-twins-property.hh>
#include <vcsn/algos/is-ambiguous.hh>
#include <vcsn/algos/is-complete.hh>
#include <vcsn/algos/is-deterministic.hh>
#include <vcsn/algos/is-acyclic.hh>
#include <vcsn/algos/normalize.hh>
#include <vcsn/algos/is-valid.hh>
#include <vcsn/algos/is-valid-expression.hh>
#include <vcsn/algos/scc.hh>
#include <vcsn/algos/standard.hh>
#include <vcsn/algos/synchronizing-word.hh>
#include <vcsn/core/rat/info.hh>
#include <vcsn/core/rat/size.hh>
#include <vcsn/dyn/fwd.hh>
#include <vcsn/dyn/value.hh>
#include <vcsn/misc/static-if.hh>
#include <vcsn/misc/type_traits.hh>


/* Creer un random automate , pouvoir enlever les transitions */ 
/* parameters : num_states, num_init_states, num_final_states */ 

using namespace vcsn::dyn ;


int main(int argc, char *argv[]) {
  
  	auto a1 = make_automaton("context = lat<lal_char(ab), lal_char(xy)>, b\n", "daut");
	auto ctx = context_of(a1);
	auto res = make_expression(ctx,"(a|x)*((b|x)(a|y)(a|x))*(b|y)*") ;
	auto out = to_automaton(res) ; 

	/* To visualize in dotty*/ 
	std::ofstream myfile;
	myfile.open("file.txt");
	myfile << out ;
	myfile.close();

	return 0 ; 
}


/*std::string create_random_expression(std::string input, std::string output) {

} */ 