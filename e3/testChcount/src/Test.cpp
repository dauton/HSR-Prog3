#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "chcount.h"

void testSimpleString() {
	std::istringstream in{"abc"};
	std::ostringstream out{};
	count(in, out);

	ASSERT_EQUAL("3", out.str());
}

void testStringWithSpaces(){
	std::istringstream in{"a b c"};
	std::ostringstream out{};
	count(in, out);

	ASSERT_EQUAL("3", out.str());
}

void testStringWithLotsOfWhitespaces(){
	std::istringstream in{"      a           b              c            "};
	std::ostringstream out{};
	count(in, out);

	ASSERT_EQUAL("3", out.str());
}

void testEmptyString(){
	std::istringstream in{""};
	std::ostringstream out{};
	count(in, out);

	ASSERT_EQUAL("0", out.str());
}

void testNumber(){
	std::istringstream in{"123"};
	std::ostringstream out{};
	count(in, out);

	ASSERT_EQUAL("3", out.str());
}

void testSpecialChars(){
	std::istringstream in{"|@#%&/-]}´~'^?`:."};
	std::ostringstream out{};
	count(in, out);

	ASSERT_EQUAL("18", out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testSimpleString));
	s.push_back(CUTE(testStringWithSpaces));
	s.push_back(CUTE(testStringWithLotsOfWhitespaces));
	s.push_back(CUTE(testEmptyString));
	s.push_back(CUTE(testNumber));
	s.push_back(CUTE(testSpecialChars));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}


