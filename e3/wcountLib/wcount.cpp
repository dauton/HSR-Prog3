#include "wcount.h"

#include <iterator>

void count(std::istream &in, std::ostream &out)
{
	std::istream_iterator<std::string> it {in};
	std::istream_iterator<std::string> eos {};

	out << std::distance(it, eos);
}
