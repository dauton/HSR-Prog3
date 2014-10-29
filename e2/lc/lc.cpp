#include <istream>
#include "lc.h"

unsigned int countLines(std::istream &input) {
	unsigned int count{0};
	std::string inputString{};

	while(std::getline(input, inputString)) {
		count++;
	}

	return count;
}
