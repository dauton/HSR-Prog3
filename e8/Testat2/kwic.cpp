#include "Word.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <stdexcept>

std::vector<std::vector<Word>> readLines(std::istream &in)
{
	std::vector<std::vector<Word>> lines {};
	std::string line {};

	while(std::getline(in, line)) {
		std::istringstream is {line};

		using isIt = std::istream_iterator<Word>;

		lines.push_back(std::vector<Word> {isIt {is}, isIt {}});
	}

	return lines;
}

std::vector<std::vector<Word>> prepareLines(std::vector<std::vector<Word>> lines)
{
	std::vector<std::vector<Word>> preparedLines {};

	for_each(lines.begin(), lines.end(), [&preparedLines](std::vector<Word> line) {
		generate_n(std::back_inserter(preparedLines), line.size(), [&line] {
			std::rotate(line.begin(), line.begin() + 1, line.end());

			return line;
		});
	});

	std::sort(preparedLines.begin(), preparedLines.end());

	return preparedLines;
}

void printLines(std::vector<std::vector<Word>> lines, std::ostream &out)
{
	for_each(lines.begin(), lines.end(), [&out](std::vector<Word> line) {
		using osIt = std::ostream_iterator<Word>;

		copy(line.begin(), line.end(), osIt{out, " "});
		out << "\n";
	});
}

void generateKwic(std::istream &in, std::ostream &out)
{
	std::vector<std::vector<Word>> lines {readLines(in)};
	std::vector<std::vector<Word>> preparedLines {prepareLines(lines)};

	printLines(preparedLines, out);
}
