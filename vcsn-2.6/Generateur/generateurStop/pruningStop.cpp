#include <iostream> //std::cout
#include <stdio.h> 
#include <fstream>  
#include <string> 

#include <vcsn/alphabets/char.hh>       // type of letter
#include <vcsn/alphabets/setalpha.hh>   // alphabet
#include <vcsn/core/automaton.hh>       // all_transitions
#include <vcsn/algos/random-automaton.hh>
#include <vcsn/labelset/tupleset.hh>    // tupleset
#include <vcsn/labelset/letterset.hh>   // letterset
#include <vcsn/weightset/b.hh>          // weightset b
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

bool random_generator(int num_states,int density, int num_initial_states, int num_final_states) {
    /* Uses the random automata generator of vaucanson */

    /* Create a context */ 
    auto ctx = create_context() ; 
    
    /* Generate a near complete automata  */ 
    auto res = random_automaton(ctx, num_states, density , num_initial_states, num_final_states, 1) ; 
  
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
        if ( !(is_cycle_ambiguous(res)) && is_functional(res) && has_twins_property(res) && !(is_deterministic(res)) && res->num_initials() == num_initial_states && res->num_finals() == num_final_states ) {
            found = true ;  
            auto aut = trim(res) ; 
            vcsn::dot(aut, std::cout) << '\n';

        }

        else {
            /* Pruning */
            /* Choose a random transition t and Test if Transducer - t respect the properties  */ 
            auto t = select(t_list);
            res->del_transition(t) ;
            size_transition -- ;   
            initial_num_useful_states = num_useful_states(res) ;    
        }
    } 
    return found ;
}

void message(){
    std::cout << "Veuillez entrer comme paramètres :" << std::endl ;
    std::cout << "1) le nombre d'états" << std::endl ;
    std::cout << "2) la densité" << std::endl ; 
    std::cout << "3) le nombre d'états initiaux" << std::endl ; 
    std::cout << "4) le nombre d'états finaux" << std::endl; 
} 

int main ( int argc, char *argv[]) {

    if (argc < 5) {
        std::cout << "Il manque quelques paramètres"<< std::endl ;
        message();    
    }
    else if (argc == 5 ) {
        bool result = random_generator(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) ; 

        while (!result ) {
            result = random_generator(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) ;  ; 
        }
    }
    else if (argc > 5){
        std::cout << "Il y a trop de paramètres " << std::endl; 
        message() ; 
    }
    return 0 ; 
}