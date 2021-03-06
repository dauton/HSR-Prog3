#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "allcharc.h"

void shouldCountOneWord() {
	std::stringstream testString{"test"};
	unsigned int count = countAllChars(testString);
	ASSERT_EQUAL(4, count);
}

void shouldCountEmptyString() {
	std::stringstream emptyString{""};
	unsigned int count = countAllChars(emptyString);
	ASSERT_EQUAL(0, count);
}

void shouldCountTwoWords() {
	std::stringstream twoWordString{"Hello World"};
	unsigned int count = countAllChars(twoWordString);
	ASSERT_EQUAL(11, count);
}

void shouldCountWhitespace() {
	std::stringstream whitespace{"   "};
	unsigned int count = countAllChars(whitespace);
	ASSERT_EQUAL(3, count);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldCountOneWord));
	s.push_back(CUTE(shouldCountEmptyString));
	s.push_back(CUTE(shouldCountTwoWords));
	s.push_back(CUTE(shouldCountWhitespace));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
}



