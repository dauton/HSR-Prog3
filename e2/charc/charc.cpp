#include <iostream>
#include "charc.h"

unsigned int countNonWhitespaceChars(std::istream &input) {
	unsigned int nonWhitespaceChars{0};
	char c{};

	while (input.get(c)) {
		bool isNotWhitespace{!std::isspace(c)};

		if (isNotWhitespace) {
			nonWhitespaceChars++;
		}
	}

	return nonWhitespaceChars;
}
