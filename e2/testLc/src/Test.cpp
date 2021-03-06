#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "lc.h"
#include <iostream>

void shouldCountNewlineAsFirstCharater() {
	std::stringstream emptySpace{"\n"};

	unsigned int numberOfLines = countLines(emptySpace);

	ASSERT_EQUAL(2, numberOfLines);
}

void shouldNotCountEmptySpace() {
	std::stringstream emptySpace{"  "};

	unsigned int numberOfLines = countLines(emptySpace);

	ASSERT_EQUAL(1, numberOfLines);
}

void shouldCountTwoLines(){
	std::stringstream twoLines{"  \nLine2"};

	unsigned int numberOfLines = countLines(twoLines);

	ASSERT_EQUAL(2, numberOfLines);
}


void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldNotCountEmptySpace));
	s.push_back(CUTE(shouldCountTwoLines));
	//s.push_back(CUTE(shouldCountNewlineAsFirstCharater));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
