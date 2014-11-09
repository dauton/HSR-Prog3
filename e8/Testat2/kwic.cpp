#include "Word.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>

void generateKwic() {
	std::vector<std::string> lines{};

	while(!std::cin.eof() && std::cin.good()) {
		std::string line{};

		std::getline(std::cin, line);

		std::stringstream iss{};
		std::vector<Word> words{};

		iss << line;

		while(!iss.eof() && iss.good()) {
			Word w{"init"};

			iss >> w;

			/*if (Word::) {
				words.push_back(w);
			}*/

			words.push_back(w);
		}

		for (unsigned int i = 0; i < words.size(); i++) {
			std::stringstream oss{};

			for (unsigned int j = 0; j < words.size(); j++) {
				oss << words[j] << " ";
			}

			lines.push_back(oss.str());
			std::rotate(words.begin(), words.begin() + 1, words.end());
		}

		std::sort(lines.begin(), lines.end());

		for (unsigned int i = 0; i < lines.size(); i++) {
			std::cout << lines[i] << "\n";
		}

		std::cout << "\n";
	}
}

