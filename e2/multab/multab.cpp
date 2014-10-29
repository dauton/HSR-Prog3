#include <ostream>
#include "multab.h"

void print(std::ostream &output, unsigned int maxFactor) {
	for (unsigned int i = 1; i <= maxFactor; i++) {
		for (unsigned int j = 1; j <= maxFactor; j++) {
			output << "\t" << i * j;
		}
		output << "\n";
	}
}
