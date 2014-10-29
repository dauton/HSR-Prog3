#include "calc.h"
#include <stdexcept>
#include <istream>

int calc(std::istream &input) {

	int number1{0}, number2{0};
	char calcOperator{};

	if (input >> number1)
		if (input >> calcOperator)
			if (input >> number2) return calc(number1, number2, calcOperator);

	throw std::invalid_argument{"stream input in the wrong format"};
}

int calc(int number1, int number2, char calcOperator) {
	switch (calcOperator) {
		case '+':
			return number1 + number2;
		case '-':
			return number1 - number2;
		case '*':
			return number1 * number2;
		case '/':
			if (number2 == 0) {
				throw std::invalid_argument{"division by zero not allowed"};
			}
			return number1 / number2;
		case '%':
			if (number2 == 0) {
				throw std::invalid_argument{"modulo by zero not allowed"};
			}
			return number1 % number2;
		default:
			throw std::invalid_argument{"unknown calcOperator"};
	}
	return 0;
}





