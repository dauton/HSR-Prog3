#include "Word.h"
#include <algorithm>
#include <stdexcept>
#include <istream>
#include <ostream>
#include <cctype>

bool invalidWord(std::string const &w) {
	return (w.empty()
	       || count_if(w.begin(),w.end(),[](char c){return !isalpha(c);}));
}
Word::Word(std::string const &word):w{word}{
	if (invalidWord(w)) {
		throw std::logic_error{"not a valid word"};
	}
}
std::ostream& Word::print(std::ostream& out) const {
    out << w;
    return out;
}

std::istream& Word::read(std::istream& in) {
    std::string newWord{};

    char c{};

    while (in.good()) {
    	c = in.get();

    	if (isalpha(c)) {
			newWord += tolower(c);
		} else {
			if (newWord.size() > 0) {
				w=newWord;
				break;
			}
		}
    }
    if (newWord.empty()) in.setstate(std::ios::failbit);
    return in;
}

bool Word::stringEqualIgnoreCase(std::string const &w, std::string const &other){
    if (w.size() != other.size()) {
		return false;
	} else {
		return std::equal(w.begin(),w.end(),other.begin(),
                        	[](char l, char r){
                            	return tolower(l) == tolower(r);
                        	});
	}
}
bool Word::stringLessIgnoreCase(std::string const &w, std::string const &other){
    return std::lexicographical_compare(w.begin(),w.end(),
                                        other.begin(),other.end(),
                                        [](char l, char r){
                                            return tolower(l) < tolower(r);
                                        });
}

