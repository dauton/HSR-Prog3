#include <iostream>
#include <iterator>
#include <vector>

#include "sevensegment.h"

const std::vector<std::string> zero 	{{" - "}, {"| |"}, {"   "}, {"| |"}, {" - "}};
const std::vector<std::string> one 		{{"   "}, {"  |"}, {"   "}, {"  |"}, {"   "}};
const std::vector<std::string> two 		{{" - "}, {"  |"}, {" - "}, {"|  "}, {" - "}};
const std::vector<std::string> three 	{{" - "}, {"  |"}, {" - "}, {"  |"}, {" - "}};
const std::vector<std::string> four 	{{"   "}, {"| |"}, {" - "}, {"  |"}, {"   "}};
const std::vector<std::string> five 	{{" - "}, {"|  "}, {" - "}, {"  |"}, {" - "}};
const std::vector<std::string> six 		{{" - "}, {"|  "}, {" - "}, {"| |"}, {" - "}};
const std::vector<std::string> seven 	{{" - "}, {"| |"}, {"   "}, {"  |"}, {"   "}};
const std::vector<std::string> eight 	{{" - "}, {"| |"}, {" - "}, {"| |"}, {" - "}};
const std::vector<std::string> nine 	{{" - "}, {"| |"}, {" - "}, {"  |"}, {" - "}};
const std::vector<std::vector<std::string>> numbers {zero, one, two, three, four, five, six, seven, eight, nine};

void printLargeDigits(int result, std::ostream &out) {
	//std::istream_iterator<int> inputIterator{in};
	std::istream_iterator<int> eos;

	std::vector<int> digits;

	int input = result;

			while (input > 9) {
				digits.insert(digits.begin(), input % 10);
				input /= 10;
			}

			digits.insert(digits.begin(), input);

	std::vector<int>::iterator digitIterator {digits.begin()};
	std::vector<std::vector<std::string>::iterator> sevenDigits;

	std::vector<std::string> sevenDigit {};

	for (unsigned int i = 0; i < 5; i++) {
		while(digitIterator != digits.end()) {
			sevenDigit = numbers.at(*digitIterator);
			out << sevenDigit.at(i) << " ";
			//std::cout << *digitIterator << " ";
			//sevenDigits.push_back(numbers.at(*digitIterator).begin());
			//sevenDigits.insert(sevenDigits.end(), numbers.at(*digitIterator).begin());
			digitIterator++;
		}
		out << "\n";
		digitIterator = digits.begin();
	}
}

const std::vector<std::vector<std::string>> error {
	{{" - "}, {"   "}, {"   "}, {"   "}, {"   "}},
	{{"|  "}, {"   "}, {"   "}, {"   "}, {"   "}},
	{{" - "}, {" - "}, {" - "}, {" - "}, {" - "}},
	{{"|  "}, {"|  "}, {"|  "}, {"| |"}, {"|  "}},
	{{" - "}, {"   "}, {"   "}, {" - "}, {"   "}}
};

void printError(std::ostream &out) {
	std::vector<std::vector<std::string>>::const_iterator digitIt {};
	std::vector<std::string>::const_iterator lineIt {};

	for (digitIt = error.begin(); digitIt != error.end(); ++digitIt) {
		for (lineIt = digitIt->begin(); lineIt != digitIt->end(); ++lineIt++) {
			out << *lineIt << " ";
		}
		out << "\n";
	}
}
