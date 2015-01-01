#include "fractab.h"

#include <algorithm>
#include <ostream>
#include <vector>

void fractab(std::ostream &out, unsigned int size)
{
	std::vector<float> numbers(size);

	iota(numbers.begin(), numbers.end(), 1);

	for_each(numbers.begin(), numbers.end(), [&](int line) {
		for_each(numbers.begin(), numbers.end(), [&](int column) {
			out << (float) line / column << "\t";
		});

		out << "\n";
	});
}
