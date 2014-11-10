#include "Word.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>

void generateKwic(std::istream &in, std::ostream &out) {
	std::vector<std::string> lines{};

	while (!in.eof() && in.good()) {
		std::string line{};

		std::getline(in, line);

		std::stringstream iss{};

		iss << line;

		std::vector<Word> words{};

		while (!iss.eof() && iss.good()) {
			Word w{"init"};

			iss >> w;

			/*if (Word::) {
				words.push_back(w);
			}*/

			words.push_back(w);
		}

		for (std::vector<Word>::iterator itLine = words.begin(); itLine != words.end(); itLine++) {
			std::stringstream oss{};

			for (std::vector<Word>::iterator itRotation = words.begin(); itRotation != words.end(); itRotation++) {
				oss << *itRotation << " ";
			}

			lines.push_back(oss.str());
			std::rotate(words.begin(), words.begin() + 1, words.end());
		}

		std::sort(lines.begin(), lines.end());
	}

	for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++) {
		out << *it << "\n";
	}
}

