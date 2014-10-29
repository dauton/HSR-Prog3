#include <iostream>
#include <iterator>

#include "chacount.h"

void count(std::istream &in, std::ostream &out) {
	std::istream_iterator<char> it{in};
	std::istream_iterator<char> eos{};

	out << std::distance(it, eos);
}
