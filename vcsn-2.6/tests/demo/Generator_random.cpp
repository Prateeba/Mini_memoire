#include <iostream> //std::cout
#include <random>

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
#include <vcsn/algos/is-deterministic.hh>
#include <vcsn/algos/is-functional.hh>
#include <vcsn/algos/has-twins-property.hh>

using namespace vcsn ; 

/* TODO : 
        1) Enlarge context : DONE 
        2) Choose initial and finals : DONE 
        3) Have just one label per transition 
        4) Verify that it does what the teacher asked : DONE */ 

int uni_rand(int max) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, max);
 
    return dis(gen) ;
}

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

template <typename Ctx>
auto choose_initial_final(const Ctx& ctx, auto states_list, unsigned num_states, unsigned num_s) {
    /* */ 
	using automaton_t = mutable_automaton<Ctx>;
    using state_t = state_t_of<automaton_t>;

    auto states = std::vector<state_t>{}; 
    int counter = num_s  ;  
    
    while (counter > 0) {
        /* Tant qu'on n'a pas encore le nombre d'état Initiaux demandé */

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
mutable_automaton<Ctx> random_aut(const Ctx& ctx, unsigned num_states, float density = 0.1,
                                        unsigned num_initial = 1, unsigned num_final = 1,
                                        unsigned max_labels = 1,float loop_chance = 0.0, const std::string& weights = "") {

    using detail::irange;
    using automaton_t = mutable_automaton<Ctx>;
    using state_t = state_t_of<automaton_t>;
    auto res = make_shared_ptr<automaton_t>(ctx);

    auto final_res = make_shared_ptr<automaton_t>(ctx);  
    
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

    require(0 <= density && density <= 1, "random_automaton: density must be in [0,1]");

    for (unsigned i: detail::irange(num_states)){
    	/* go through pair of states, if the transition between the pair respect the given 
    	property -> keep transition else ignore */ 

    	auto temp_aut = make_shared_ptr<automaton_t>(ctx); // temporary automaton
        temp_aut = res ;
        for (unsigned j: detail::irange(num_states)){
            
            int temp = uni_rand(1000) ; 
            //std::cout << temp ;
            if (temp <= floor(density*1000)) {

            	temp_aut->add_transition(states[i], states[j], random_label(ls, gen), random_weight()) ;  
                
                if ( !(is_cycle_ambiguous(temp_aut)) && (is_functional(temp_aut)) && (has_twins_property(temp_aut)) ){ 
                	res->add_transition(states[i], states[j], random_label(ls, gen), random_weight()) ;  
                    
                }
                else {
                	temp_aut->del_transition(states[i], states[j], random_label(ls, gen))  ;  
                }
            
            }
        }
    }

    if (( !(is_cycle_ambiguous(res)) && (is_functional(res)) && (has_twins_property(res)) ) && !(is_deterministic(res))) {
        std::cout << "OK" << "\n" ; 
        final_res = res   ; 
    }

    else {
        std::cout << "DID NOT FIND A GOOD EXAMPLE" << "\n" ; 
    }

    return final_res ;  
}
auto create_context() {
    using alphabet_t = set_alphabet<char_letters>;   // Basic alphabet type.
    using letterset_t = letterset<alphabet_t>;       // Letterset (single-tape labelset).
    auto ls1 = letterset_t{'a'};     
    auto ls2 = letterset_t{'b'};                 // Create the letterset.
    using labelset_t = tupleset<letterset_t, letterset_t>; // Labelset (double-tape).
    auto ls = labelset_t{ls1, ls2};                  // Create the double-tape labelset.
    using context_t = context<labelset_t, b>;        // Context of the automaton: lat<lal_char, lal_char>, b.
    
    // Create the context from the labelset.
    // No parameter for the weightset, as it's just B.
    auto ctx = context_t{ls};
    return ctx  ; 
} 


int main() {

    auto res = create_context() ; 
    auto aut = random_aut(res, 10, 0.1, 2, 3) ; 

    vcsn::dot(aut, std::cout) << '\n';
    

    return 0 ; 
}