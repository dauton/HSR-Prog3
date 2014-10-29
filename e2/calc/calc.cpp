#include "calc.h"
#include <istream>
#include <stdexcept>

int calc(int firstNumber, int secondNumber, char operatorSymbol){

	//Could also be a switch-case
	if(operatorSymbol == '+'){
		return firstNumber + secondNumber;
	}else if(operatorSymbol == '-'){
		return firstNumber - secondNumber;
	}else if(operatorSymbol == '*'){
		return firstNumber*secondNumber;
	}else if(operatorSymbol == '%'){
		return firstNumber % secondNumber;
	}else if(operatorSymbol == '/'){
		// special case
		if(secondNumber == 0){
			throw std::invalid_argument("Cannot divide by zero"); //like this.
		}
		return firstNumber / secondNumber;
	}else{
		throw std::invalid_argument("Unknown operator!");
	}
}


int calc(std::istream &input){
	int firstNumber{0};
	int secondNumber{0};
	char operatorSymbol { };

	input >> firstNumber;
	input >> secondNumber;
	input >> operatorSymbol;

	return calc(firstNumber, secondNumber, operatorSymbol);

}
