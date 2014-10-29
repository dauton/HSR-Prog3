#include <iostream>
#include "sumi.h"

int sumInt(std::istream &input) {
	int sum{0};
	int number{};

	while(input >> number) {
		sum += number;
	}

	return sum;
}
