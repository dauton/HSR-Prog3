#include <iostream>
#include <stdexcept>
#include "pocketcalculator.h"
#include "calc.h"

void runPocketCalculator() {
	while (std::cin) {
		try {
			std::cout << calc(std::cin) << "\n";
			//int result = calc(cin);
			//istringstream in (to_string(calc(cin)));
			//printLargeDigits(result, cout);
		} catch (...) {
			//printError(out);
			std::cout << "ERROR";
			std::cin.clear();
			std::string line{};
			std::getline(std::cin, line);
		}
	}
}
