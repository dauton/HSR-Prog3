#include <iostream>
#include "averagei.h"

int calculateAverage(std::istream &input) {
	int sum{0};
	int number{0};
	int i{0};

	while (input >> number) {
		sum += number;
		i++;
	}

	return sum / i;
}
