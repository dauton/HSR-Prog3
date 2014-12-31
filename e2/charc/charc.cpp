#include <iostream>
#include "charc.h"

unsigned int countNonWhitespaceChars(std::istream &input) {
	unsigned int nonWhitespaceChars{0};
	char c{};

	while (input >> c) {
		nonWhitespaceChars++;
	}

	return nonWhitespaceChars;
}
