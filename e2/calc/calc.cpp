#include "calc.h"

#include <istream>
#include <stdexcept>

int calc(int firstOperand, int secondOperand, char operatorSymbol)
{
	switch(operatorSymbol) {
		case '+':
			return firstOperand + secondOperand;
		case '-':
			return firstOperand - secondOperand;
		case '*':
			return firstOperand * secondOperand;
		case '/':
			if (secondOperand == 0) {
				throw std::invalid_argument("Division by zero!");
			}

			return firstOperand / secondOperand;
		case '%':
			if (secondOperand == 0) {
				throw std::invalid_argument("Modulo by zero!");
			}

			return firstOperand % secondOperand;
		default:
			throw std::invalid_argument("Unknown operation");
	}
}

int calc(std::istream &input) {
	int firstOperand {};
	int secondOperand {};
	char operatorSymbol {};

	input >> firstOperand;
	input >> operatorSymbol;
	input >> secondOperand;

	return calc(firstOperand, secondOperand, operatorSymbol);
}

