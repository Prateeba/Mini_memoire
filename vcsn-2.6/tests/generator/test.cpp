#include <iostream> //std::cout

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

int main() {

	
	/* using namespace vcsn;
	using alphabet_t = set_alphabet<char_letters>;
	using letterset_t = letterset<alphabet_t> ;

	auto ls1 = letterset_t{'a'};
	auto ls2 = letterset_t{'c'};

	using labelset_t = tupleset<letterset_t, letterset_t>;
	auto ls = labelset_t{ls1, ls2};

	using context_t = context<labelset_t, b>;

	auto ctx = context_t{ls};
	auto result = random_automaton(ctx, 5) ;
	dot(result, std::cout) << '\n'; */ 


	//auto t = make_mutable_automaton(ctx);
	
	//  ce qu'on veut :context = "lat<lal_char, lal_char>, b"

	/* using context_t = context<tupleset<letterset_t, letterset_t>, b>;
	auto cx = context_t{labelset_t{letterset_t{'b'}, letterset_t{'d'}}} ; 
	
	auto res = random_automaton(cx, 5) ; 
	std::cout << has_twins_property(res) ;  
	std::cout << is_deterministic(res) ;  
	std::cout << is_functional(res) ; 
	dot(res, std::cout) << '\n';  */ 


	// ------------- TO DO --------------------
	/* Find a way to have more than one labels */


	using namespace vcsn::dyn ;


	//auto a1 = make_automaton("context = lal, q\n" "$ 0 <1/2>\n" "0 1 <2>a, <6>b\n" "1 $\n", "daut");
	auto a1 = make_automaton("context = lat<lal_char(abc), lal_char(def)>, b\n", "daut");

	auto ctx = context_of(a1);
	auto res = random_automaton(ctx, 6) ; 
	info(res) ;   


	/*int counter  = 0 ;  
	while (counter < 100) { 
		auto res = random_generator(6,3,2) ; 
		if ( !(is_cycle_ambiguous(res)) ) {
			std::cout << has_twins_property(res) ; 
			print(res) ; 
			std::cout << counter ; 
			counter ++ ; 
		}
		
	}*/


	/* faire le test de determinisme 
			- si c'est deterministe : re genere un autre random directe et recommence le test
			- si c'est pas deterministe : 
				voir si c'est fonctionnel : 
					- si c'est fonctionel : 
						- voir s'il a la twins property  
							- s'il a le twins property : 
								- On imprime dans un premier temps ; mettre un compteur pour compter le nombre de bon qu'on a eu  
							- s'il n'a pas le twins property : 
								regenere un autre random et recommence le test

				si c'est pas fonctionnel : 
					re genere un autre random et recommence le test

	Mettre tout ça dans une boucle de 100 fois au debut  */ 

}

