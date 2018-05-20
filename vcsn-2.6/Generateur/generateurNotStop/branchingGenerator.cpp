#include <iostream> //std::cout
#include <random>
#include <cstdlib>
#include <fstream> // to save in file

#include <vcsn/alphabets/char.hh> // type of letter
#include <vcsn/alphabets/setalpha.hh> // alphabet
#include <vcsn/algos/compose.hh> // composition algorithm
#include <vcsn/algos/dot.hh> // display algorithm
#include <vcsn/labelset/tupleset.hh> // tupleset
#include <vcsn/labelset/letterset.hh> // letterset
#include <vcsn/weightset/b.hh> // weightset b

#include <vcsn/algos/dot.hh> // display algorithm
#include <vcsn/algos/random-weight.hh>
#include <vcsn/core/mutable-automaton.hh>
#include <vcsn/ctx/traits.hh>
#include <vcsn/dyn/automaton.hh>
#include <vcsn/dyn/context.hh>
#include <vcsn/dyn/algos.hh>
#include <vcsn/misc/irange.hh>
#include <vcsn/algos/info.hh>
#include <vcsn/algos/strip.hh>
#include <vcsn/algos/is-deterministic.hh>
#include <vcsn/algos/is-functional.hh>
#include <vcsn/algos/has-twins-property.hh>
#include <vcsn/algos/accessible.hh>

using namespace vcsn ; 

/* Return a random  number between 1 and max */
int uni_rand(int max) { 
    std::random_device rd;          //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());         //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, max);
 
    return dis(gen) ;
}

/* Check if a state has already been visited  */
bool in_state_list(auto states_list, auto state, int num_states) {
    int i = 0 ; 
    bool found = false ; 

    while(i < states_list.size() && !found) {
        if (states_list[i] == state) {
            found = true ; 
        }
        i++ ; 
    } 
    return found ; 
} 

/* Choose randomly the Initial and Final states */ 
template <typename Ctx>
auto choose_initial_final(const Ctx& ctx, auto states_list, unsigned num_states, unsigned num_s) {	
    using automaton_t = mutable_automaton<Ctx>;
    using state_t = state_t_of<automaton_t>;

    auto states = std::vector<state_t>{}; 
    int counter = num_s  ;  
    
    while (counter > 0) {
        int i = 0 ; 
        while (i < num_states && states.size() < num_s) {

            int temp = uni_rand(2) ;
           
            if (temp == 1 && !(in_state_list(states, states_list[i], num_states))) {
                states.emplace_back(states_list[i]);

                counter --   ; 
            }
        i++ ; 

        }
    }
    return states ; 
}


template <typename Ctx> 
int random_aut(const Ctx& ctx, unsigned num_states, float density = 0.1,
                                        unsigned num_initial = 1, unsigned num_final = 1,
                                        const std::string& weights = "") {

    //Alias declaration to declare a name to use as a synonym for a previously declared type
    using detail::irange;
    using automaton_t = mutable_automaton<Ctx>;
    using state_t = state_t_of<automaton_t>;
    
    // pointer to the automaton
    auto res = make_shared_ptr<automaton_t>(ctx);
    
    auto& gen = make_random_engine();
    
    // Weight -> no weight here 
    const auto& ws = *ctx.weightset();
    auto random_weight = [&weights, &ws]() {
        return weights.empty() ? ws.one() : vcsn::random_weight(ws, weights);
    };

    // Labels 
    const auto& ls = *ctx.labelset();
    const auto& gens = ls.generators();

    // create states and store them in vector 
    auto states = std::vector<state_t>{};
    for (unsigned i: detail::irange(num_states)){
        states.emplace_back(res->new_state());
    }

    // Choose and assign Initial States  
    std::vector<state_t> initial_states =  choose_initial_final(ctx, states, num_states, num_initial) ; 
    for (unsigned i: detail::irange(initial_states.size())){
        res->set_initial(initial_states[i]) ;     
    }
    
    // Choose and assign Final States  
    std::vector<state_t> final_states =  choose_initial_final(ctx, states, num_states, num_final) ; 
    for (unsigned i: detail::irange(final_states.size())){
        res->set_final(final_states[i]) ;     
    }

    // User to input the density of adding a transition
    require(0 <= density && density <= 1, "random_automaton: density must be in [0,1]");

    // Random States selector 
    auto select = make_random_selector(make_random_engine()); 
    
    int initial_num_useful_states = 0  ;
    bool found = false ; 

    while (initial_num_useful_states < num_states ){ 

        state_t random_state1 = select(states) ;
        state_t random_state2 = select(states) ;

        // temporary automaton
    	auto temp_aut = make_shared_ptr<automaton_t>(ctx); 
        temp_aut = res ;
        int temp = uni_rand(1000) ; 

        if (temp <= floor(density*1000)) {

            auto t = temp_aut->get_transition(random_state1, random_state2, random_label(ls, gen));
            if (t == temp_aut->null_transition()) {

                temp_aut->add_transition(random_state1, random_state2, random_label(ls, gen), random_weight()) ;  
                    
                if ( !(is_cycle_ambiguous(temp_aut)) && (is_functional(temp_aut)) && (has_twins_property(temp_aut)) ){ 
                    res->add_transition(random_state1, random_state2, random_label(ls, gen), random_weight()) ;  
                        
                }
                else {
                    temp_aut->del_transition(random_state1, random_state2, random_label(ls, gen))  ;  
                }    
            }
        }

        initial_num_useful_states = num_useful_states(res) ;

    }

    if (!(is_cycle_ambiguous(res)) && (is_functional(res)) && (has_twins_property(res)) && !(is_deterministic(res)) && num_useful_states(res) == num_states ) {
        found = true ; 
        vcsn::dot(res, std::cout) << '\n';
    }

    return found ; 
}
auto create_context() {
    using namespace vcsn;

    // Basic alphabet type.
    using alphabet_t = set_alphabet<char_letters>;

    // Letterset (single-tape labelset).
    using letterset_t = letterset<alphabet_t>;

    // Create the letterset.
    auto ls1 = letterset_t{'a', 'b', 'c', 'd'};

    // Labelset (double-tape).
    using labelset_t = tupleset<letterset_t, letterset_t>;

    // Create the double-tape labelset.
    const auto ls = labelset_t{ls1, ls1};

    // Context of the automaton: lat<lal_char, lal_char>, b.
    using context_t = context<labelset_t, b>;

    // Create the context from the labelset.
    // No parameter for the weightset, as it's just B.
    // B = boolean
    const auto ctx = context_t{ls};
    return ctx  ; 
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
        auto res = create_context() ; 
        bool result = random_aut(res, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) ; 

        while (!result ) {
        result = random_aut(res, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) ;  ; 
        }
    }
    else if (argc > 5){
        std::cout << "Il y a trop de paramètres " << std::endl; 
        message() ; 
    }
    return 0 ; 
}