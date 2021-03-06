#include <ostream>
#include <map>
#include <iomanip>
#include "bcs.h"

void print(std::ostream &output) {
	std::map<std::string, float> drinks{
		{"Beer", 4.65}, {"Moass", 9.15}, {"Schnapps", 3.85}, {"Soda", 2.95}
	};
	std::map<std::string, float>::iterator it;

	for (it = drinks.begin(); it != drinks.end(); ++it) {
		output << std::setw(10) << it->first;
			for (int i = 1; i <= 10; i++) {
				output << std::setw(8) << it->second * i;
			}
			output << "\n";
	}
}
