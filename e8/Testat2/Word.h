#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

struct Word
{
	Word() = default;
    explicit Word(std::string const &inputString);

    inline bool operator>(Word const &rhs) const { return lowerCaseRep() > rhs.lowerCaseRep(); }
    inline bool operator<(Word const &rhs) const { return rhs > *this; }
    inline bool operator==(Word const &rhs) const { return !(*this < rhs || *this > rhs ); }
    inline bool operator!=(Word const &rhs) const { return !(*this == rhs); }
    inline bool operator>=(Word const &rhs) const { return !(*this < rhs); }
    inline bool operator<=(Word const &rhs) const { return !(*this > rhs); }

    operator std::string() { return rep; }

    std::ostream& print(std::ostream &outputStream) const { return (outputStream << rep); }
    std::istream& read(std::istream &inputStream);

    private:
    	std::string rep{};
    	std::string lowerCaseRep() const;
};

inline std::ostream &operator<<(std::ostream &outputStream, Word const& inputWord) { return inputWord.print(outputStream); }
inline std::istream &operator>>(std::istream &inputStream, Word& outputWord) { return outputWord.read(inputStream); }

#endif
