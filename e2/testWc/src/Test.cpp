#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "wc.h"
#include <istream>

void shouldCountTwoWords() {
	std::stringstream twoWords{"two words"};
	unsigned int count = countWords(twoWords);
	ASSERT_EQUAL(2, count);
}

void shouldCountTwoWordsWithExtraSpaces() {
	std::stringstream twoWords{"two   words"};
	unsigned int count = countWords(twoWords);
	ASSERT_EQUAL(2, count);
}

void shouldCountOneWord() {
	std::stringstream twoWords{"one"};
	unsigned int count = countWords(twoWords);
	ASSERT_EQUAL(1, count);
}

void shouldCountNoWords() {
	std::stringstream twoWords{"        "};
	unsigned int count = countWords(twoWords);
	ASSERT_EQUAL(0, count);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldCountTwoWords));
	s.push_back(CUTE(shouldCountTwoWordsWithExtraSpaces));
	s.push_back(CUTE(shouldCountOneWord));
	s.push_back(CUTE(shouldCountNoWords));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
}



