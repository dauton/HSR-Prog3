#include "multab.h"

#include <algorithm>
#include <ostream>
#include <numeric>
#include <vector>

void multab(std::ostream &out, unsigned int size)
{
	std::vector<int> numbers(size);

	iota(numbers.begin(), numbers.end(), 1);

	for_each(numbers.begin(), numbers.end(), [&](int line) {
		for_each(numbers.begin(), numbers.end(), [&](int column) {
			out << line * column << "\t";
		});

		out << "\n";
	});
}
