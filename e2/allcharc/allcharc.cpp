#include <iostream>
#include "allcharc.h"

unsigned int countAllChars(std::istream &input) {
	int count{0};
	char c{};

	while (input.get(c)) {
		count++;
	}

	return count;
}
