#include "Word.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <stdexcept>

std::vector<std::vector<std::string>> readInput(std::istream &in) {
	std::vector<std::vector<std::string>> lines {};
	std::string line {};

	while (std::getline(in, line)) {
		std::stringstream is {line};

		std::istream_iterator<std::string> eos {};
		std::istream_iterator<std::string> it(is);

		std::vector<std::string> words {it, eos};

		lines.push_back(words);
	}

	return lines;
}

std::vector<std::vector<Word>> toWord(std::vector<std::vector<std::string>> linesFromInput) {
	std::vector<std::vector<Word>> lines {};

	for (std::vector<std::string> line : linesFromInput) {
		std::vector<Word> wordLine {};

		for (std::string wordCandidate : line) {
			std::stringstream is {wordCandidate};
			Word word {"init"};

			is >> word;

			if (!(word == "init")) {
				wordLine.push_back(word);
			}
		}

		lines.push_back(wordLine);
	}

	return lines;
}

std::vector<std::vector<Word> > prepareLines(std::vector<std::vector<Word>> lines) {
	std::vector<std::vector<Word>> preparedLines { };

	for (std::vector<Word> line : lines) {
		for (unsigned int i = 0; i < line.size(); i++) {
			preparedLines.push_back(line);

			std::rotate(line.begin(), line.begin() + 1, line.end());
		}
	}

	std::sort(preparedLines.begin(), preparedLines.end());

	return preparedLines;
}

void printLines(std::vector<std::vector<Word>> lines, std::ostream &out) {
	for (std::vector<Word> line : lines) {
		for (unsigned int i = 0; i < line.size(); i++) {
			out << line.at(i) << " ";
		}

		out << "\n";
	}
}

void generateKwic(std::istream &in, std::ostream &out) {
	std::vector<std::vector<std::string>> linesFromInput {readInput(in)};

	std::vector<std::vector<Word>> lines {toWord(linesFromInput)};

	std::vector<std::vector<Word>> preparedLines {prepareLines(lines)};

	printLines(preparedLines, out);
}



