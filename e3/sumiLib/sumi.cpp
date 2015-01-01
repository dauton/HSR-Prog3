#include "sumi.h"

#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void sum(std::istream &in, std::ostream &out)
{
	std::istream_iterator<int> it {in};
	std::istream_iterator<int> eos {};

	out << std::accumulate(it, eos, 0);
}
