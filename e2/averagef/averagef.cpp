#include <iostream>
#include "averagef.h"

float calculateAverage(std::istream &input) {
	float sum{0};
	float number{0};
	int i{0};

	while (input >> number) {
		sum += number;
		i++;
	}

	return sum / i;
}
