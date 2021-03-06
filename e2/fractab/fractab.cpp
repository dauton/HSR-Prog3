#include <ostream>
#include <iomanip>
#include "fractab.h"

void print(std::ostream &output, unsigned int maxDiv) {
	for (unsigned int i = 1; i <= maxDiv; i++) {
		for (unsigned int j = 1; j <= maxDiv; j++) {
			output << "\t" << std::setprecision(2) << (float) i / (float) j;
		}
		output << "\n";
	}
}
