#include <iostream>
#include <iterator>

#include "chcount.h"

void count(std::istream &in, std::ostream &out) {
	std::istream_iterator<char> it{in};
	std::istream_iterator<char> eos{};

	unsigned int count{0};

	while(it != eos) {
		it++;
		count++;
	}

	out << count;
}
