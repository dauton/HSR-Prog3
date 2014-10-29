#include <iostream>
#include "sumf.h"

float sumFloat(std::istream &input) {
	float sum{0};
	float number{};

	while(input >> number) {
		sum += number;
	}

	return sum;
}
