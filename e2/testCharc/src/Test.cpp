#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "charc.h"

void shouldCountNoEmptyString() {
	std::stringstream emptyString{""};
	unsigned int count = countNonWhitespaceChars(emptyString);
	ASSERT_EQUAL(0, count);
}

void shouldCountNoWhitespaces() {
	std::stringstream whiteSpaceString{"		   "};
	unsigned int count = countNonWhitespaceChars(whiteSpaceString);
	ASSERT_EQUAL(0, count);
}

void shouldCountOneWord(){
	std::stringstream oneWord{"test"};
	unsigned int count = countNonWhitespaceChars(oneWord);
	ASSERT_EQUAL(4, count);
}

void shouldCountOneWordWithWhitespace(){
	std::stringstream oneWordWithWhtiespace{"test	  "};
	unsigned int count = countNonWhitespaceChars(oneWordWithWhtiespace);
	ASSERT_EQUAL(4, count);
}

void shouldCountTwoLines(){
	std::stringstream threeLines{"fail\nor\nsuccess"};
	unsigned int count = countNonWhitespaceChars(threeLines);
	ASSERT_EQUAL(13, count);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldCountOneWord));
	s.push_back(CUTE(shouldCountNoEmptyString));
	s.push_back(CUTE(shouldCountTwoLines));
	s.push_back(CUTE(shouldCountOneWordWithWhitespace));
	s.push_back(CUTE(shouldCountNoWhitespaces));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc, argv);
}



