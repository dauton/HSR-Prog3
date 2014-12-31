#include "lcount.h"

#include <iostream>
#include <iterator>
#include <algorithm>

void count(std::istream &in, std::ostream &out)
{
	std::istreambuf_iterator<char> it {in};
	std::istreambuf_iterator<char> eos {};

	out << std::count(it, eos, '\n');
}
