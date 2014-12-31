#include "acount.h"

#include <iostream>
#include <iterator>
#include <algorithm>

void count(std::istream &in, std::ostream &out)
{
	std::istream_iterator<char> it {in};
	std::istream_iterator<char> eos {};

	out << std::count(it, eos, 'a');
}
