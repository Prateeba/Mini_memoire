/* Create a transducer of 100 useful states : 
	- Create 100 states and place them in a list
	- Choose 10 states randomly and connect them with a ramdom tansition
	- Property check : 
		if not ok  : pop the transtions till property check ok */ 

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
#include <vcsn/algos/strip.hh>
#include <vcsn/algos/is-deterministic.hh>
#include <vcsn/algos/is-functional.hh>
#include <vcsn/algos/has-twins-property.hh>
#include <vcsn/algos/accessible.hh>

using namespace vcsn ; 

int uni_rand(int max) {
    /* return a random  number between 1 and max */ 
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, max);
 
    return dis(gen) ;
}

bool in_state_list(auto states_list, auto state, int num_states) {
    /* Check if a state has already been visited  */ 
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
    /* Choose randomly the Initial and Final states */ 
	
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
                                        unsigned max_labels = 1, const std::string& weights = "") {

    using detail::irange;
    using automaton_t = mutable_automaton<Ctx>;
    using state_t = state_t_of<automaton_t>;
    using label_t = label_t_of<automaton_t> ; 

    // User to input the density of adding a transition
    require(0 <= density && density <= 1, "random_automaton: density must be in [0,1]");

    /* pointer to transducer */ 
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
    auto all_states = std::vector<state_t>{};
    for (unsigned i: detail::irange(num_states)){
        all_states.emplace_back(res->new_state());
    }

    // Choose and assign Initial States  
    std::vector<state_t> initial_states =  choose_initial_final(ctx, all_states, num_states, num_initial) ; 
    for (unsigned i: detail::irange(initial_states.size())){
        res->set_initial(initial_states[i]) ;     
    }
    
    // Choose and assign Final States  
    std::vector<state_t> final_states =  choose_initial_final(ctx, all_states, num_states, num_final) ; 
    for (unsigned i: detail::irange(final_states.size())){
        res->set_final(final_states[i]) ;     
    }

    /* Random states selector */ 
    auto select = make_random_selector(make_random_engine()); 
    
    // Choose x random states and connect them 
    for (unsigned i: detail::irange(num_states)){
        for (unsigned j: detail::irange(num_states)) {
            int temp = uni_rand(1000) ; 
            if (temp <= floor(density*1000)) {
                res->add_transition(all_states[i], all_states[j],  random_label(ls, gen) , random_weight()) ;  
            }

        }
    }
    
    bool found = false ; 
    auto t_list = res->all_transitions() ; 
    int size_transition =  t_list.size() ; 
    int initial_num_useful_states = 0  ;

    while (size_transition > 0 && !found){ 
		
		/* Test if the random transducer generated respect the properties */ 
		if ( !(is_cycle_ambiguous(res)) && is_functional(res) && has_twins_property(res) && !(is_deterministic(res)) && num_useful_states(res) == num_states ) {
			found = true ; 
			vcsn::dot(res, std::cout) << '\n';
			info(res) ; 
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

auto create_context() {
    using namespace vcsn;

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


int main() {

    /*int i = 0 ; 
    int max  = 100 ; 
    int count = 0 ; 

    auto res = create_context() ; 

    while (i < max) {
        std::cout << "COUNTER : " << i << "\n" ; 
        count += random_aut(res, 10, 0.1, 2, 2) ; 
        i += 1 ; 
    }

    std::cout << "Number of good example : "<< count << "\n" ; 
    std::cout << "Good example ratio : "<< double(count) /double(max) << "\n" ;  */
    
    auto res = create_context() ;
    bool result = random_aut(res, 100, 0.1, 30, 22) ; 
    while (!result) {
    	result = random_aut(res, 100, 0.1, 30, 22) ; 
    }
    
    return 0 ; 
}