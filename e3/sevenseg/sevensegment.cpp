#include <iterator>
#include <ostream>
#include <typeinfo>
#include <vector>

#include "sevensegment.h"

void printLargeDigit(unsigned int i, std::ostream &out) {
	std::vector<std::string> zero 	{{" - "}, {"| |"}, {"   "}, {"| |"}, {" - "}};
	std::vector<std::string> one 	{{"   "}, {"  |"}, {"   "}, {"  |"}, {"   "}};
	std::vector<std::string> two 	{{" - "}, {"  |"}, {" - "}, {"|  "}, {" - "}};
	std::vector<std::string> three 	{{" - "}, {"  |"}, {" - "}, {"  |"}, {" - "}};
	std::vector<std::string> four 	{{"   "}, {"| |"}, {" - "}, {"  |"}, {"   "}};
	std::vector<std::string> five 	{{" - "}, {"|  "}, {" - "}, {"  |"}, {" - "}};
	std::vector<std::string> six 	{{" - "}, {"|  "}, {" - "}, {"| |"}, {" - "}};
	std::vector<std::string> seven 	{{" - "}, {"| |"}, {"   "}, {"  |"}, {"   "}};
	std::vector<std::string> eight 	{{" - "}, {"| |"}, {" - "}, {"| |"}, {" - "}};
	std::vector<std::string> nine 	{{" - "}, {"| |"}, {" - "}, {"  |"}, {" - "}};
	std::vector<std::vector<std::string>> numbers {zero, one, two, three, four, five, six, seven, eight, nine};

	std::vector<std::string> number = numbers.at(i);
	auto iterator = number.begin();

	while (iterator != number.end()) {
		out << *iterator << "\n";
		++iterator;
	}
}
