#include <iostream>
#include "wc.h"

unsigned int countWords(std::istream &input) {
	unsigned int count{0};
	std::string word{};

	while(input >> word) {
		std::cout << word;
		count++;
	}

	return count;
}
