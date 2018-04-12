#pragma once

#include <memory>

#include <boost/range/algorithm/mismatch.hpp>
#include <boost/algorithm/string/predicate.hpp> // starts_with
#include <boost/optional.hpp>

#include <vcsn/alphabets/char.hh> // type of letter
#include <vcsn/core/kind.hh>
#include <vcsn/labelset/fwd.hh>
#include <vcsn/labelset/genset-labelset.hh>
#include <vcsn/labelset/labelset.hh>
#include <vcsn/labelset/letterset.hh> // for letterized_traits
#include <vcsn/misc/attributes.hh>
#include <vcsn/misc/functional.hh>
#include <vcsn/misc/irange.hh>
#include <vcsn/misc/raise.hh>
#include <vcsn/labelset/wordset.hh>

using namespace vcsn ; 


int main() {
	wordset word = wordset<char_letters("abc")>; 
}

