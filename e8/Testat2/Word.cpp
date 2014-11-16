#include "Word.h"
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <cctype>

Word::Word(std::string const &inputString)
{
	if (inputString.empty()) {
		throw std::invalid_argument("empty string supplied");
	}

    copy_if(inputString.cbegin(), inputString.cend(), std::back_inserter(rep), [](char const character) {
    	if (!std::isalpha(character)) {
    		throw std::invalid_argument("invalid character in input");
        }

    	return true;
    });
}

std::string Word::lowerCaseRep() const
{
	std::string lcr {};

	transform(rep.cbegin(), rep.cend(), std::back_inserter(lcr), (int(*)(int))std::tolower);

	return lcr;
}

std::istream& Word::read(std::istream &inputStream) {
    std::string readBuffer {};

    while (!std::isalpha(inputStream.peek()) && inputStream) {
    	inputStream.ignore(1);
    }

    if (!inputStream) {
    	return inputStream;
    }

    while (std::isalpha(inputStream.peek())) {
    	readBuffer += inputStream.get();
    }

    rep = readBuffer;

    if (!inputStream) {
    	inputStream.clear(std::ios_base::eofbit);
    }

    return inputStream;
}
