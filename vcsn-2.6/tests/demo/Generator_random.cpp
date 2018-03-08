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

#include <vcsn/algos/is-functional.hh>
#include <vcsn/algos/has-twins-property.hh>

using namespace vcsn ; 

/* TODO : 
        1) Enlarge context 
        2) Choose initial and finals 
        3) Verify that it does what the teacher asked */ 

int uni_rand() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 1000);
 
    return dis(gen) ;
}

template <typename Ctx>
mutable_automaton<Ctx> random_automaton(const Ctx& ctx, unsigned num_states, float density = 0.1,
                                        unsigned num_initial = 1, unsigned num_final = 1,
                                        unsigned max_labels = 1,float loop_chance = 0.0, const std::string& weights = "") {

    using detail::irange;
    using automaton_t = mutable_automaton<Ctx>;
    using state_t = state_t_of<automaton_t>;
    auto res = make_shared_ptr<automaton_t>(ctx);

    
    auto& gen = make_random_engine();
    // Weight
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

    // Connect states with transitions 
    require(0 <= density && density <= 1, "random_automaton: density must be in [0,1]");

    for (unsigned i: detail::irange(num_states)){
        for (unsigned j: detail::irange(num_states)){
            
            int temp = uni_rand() ; 
            if (temp <= floor(density*1000)) {

                /* Either add by default then remove if doesnt respect the required property 
                    Or make a copy of the automaton every time  */ 
                res->add_transition(states[i], states[j], random_label(ls, gen), random_weight()) ; 

                if ( !(is_cycle_ambiguous(res)) ){
                    
                    if ( !(is_functional(res)) && !(has_twins_property(res)) ) {
                        res->del_transition(states[i], states[j], random_label(ls, gen)) ; 
                    }

                }
            
            }
        }
    }
    
    return res ; 


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
    auto aut = random_automaton(res, 10, 0.1, 1, 1) ; 

    vcsn::dot(aut, std::cout) << '\n';

    return 0 ; 
}