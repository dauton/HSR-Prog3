#include <iostream>
#include <stdexcept>
#include "pocketcalculator.h"

void runPocketCalculator(std::istream &in, std::ostream &out) {
	while (in) {
		try {
			int result = calc(in);

			printLargeDigits(result, out);
		} catch (...) {
			printError(out);
			in.clear();
			std::string line{};
			std::getline(in, line);
		}
	}
}
