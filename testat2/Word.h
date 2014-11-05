#ifndef WORD_H_
#define WORD_H_
#include <iosfwd>
#include <string>

class Word {
public:
    Word(std::string const &word);
    bool operator==(Word const &other) const {
        return stringEqualIgnoreCase(w,other.w);
    }
    bool operator==(char const *otherptr) const {
    	std::string other{otherptr};
        return stringEqualIgnoreCase(w,other);
    }
    bool operator<(Word const &other) const {
        return stringLessIgnoreCase(w,other.w);
    }
    bool operator<(char const *otherptr) const {
    	std::string other{otherptr};
    	return stringLessIgnoreCase(w,other);
    }
    std::ostream& print(std::ostream& out) const;
    std::istream& read(std::istream& in);

    static bool stringEqualIgnoreCase(std::string const &w, std::string const &other);
    static bool stringLessIgnoreCase(std::string const &w, std::string const &other);
    std::string w;
};
inline std::ostream &operator<<(std::ostream &out, Word const &w){
    return w.print(out);
}
inline std::istream &operator>>(std::istream &in, Word &w){
    return w.read(in);
}
#endif
