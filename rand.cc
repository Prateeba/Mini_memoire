#include <iostream> //std::cout

#include <vcsn/alphabets/char.hh> // type of letter
#include <vcsn/alphabets/setalpha.hh> // alphabet
#include <vcsn/core/automaton.hh> // all_transitions
#include <vcsn/algos/random-automaton.hh>
#include <vcsn/labelset/tupleset.hh> // tupleset
#include <vcsn/labelset/letterset.hh> // letterset
#include <vcsn/weightset/b.hh> // weightset b

int main()
{
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


  // Create an empty automaton (transducer), from the context.
  auto a = random_automaton(ctx, 10);
  for (const auto t: all_transitions(a))
    {
      a->print(t);
      std::cout << '\n';
    }
}
