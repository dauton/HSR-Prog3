#ifndef CALC_H_
#define CALC_H_
#include <iosfwd>

int calc(int firstNumber, int secondNumber, char operatorSymbol);

int calc(std::istream &input);

#endif
