#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "sumi.h"
#include <iostream>

void shouldSumZeroes() {
	std::stringstream zeroes{"0 0"};

	int sum = sumInt(zeroes);

	ASSERT_EQUAL(0, sum);
}

void shouldSumOneNumber(){
	std::stringstream oneNumber{"1"};

	int sum = sumInt(oneNumber);

	ASSERT_EQUAL(1, sum);
}

void shouldSumTwoNumbers(){
	std::stringstream oneNumber{"1 2 3"};

	int sum = sumInt(oneNumber);

	ASSERT_EQUAL(6, sum);
}

void shouldSumTwoNumbersOnTwoLines(){
	std::stringstream oneNumber{"1 2 3\n3"};

	int sum = sumInt(oneNumber);

	ASSERT_EQUAL(9, sum);
}

void shouldSumOneNegativeNumber(){
	std::stringstream oneNegativeNumber{"-1"};

	int sum = sumInt(oneNegativeNumber);

	ASSERT_EQUAL(-1, sum);
}

void shouldSumTwoNegativeNumbers(){
	std::stringstream negativeNumbers{"-1 -2"};

	int sum = sumInt(negativeNumbers);

	ASSERT_EQUAL(-3, sum);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldSumZeroes));
	s.push_back(CUTE(shouldSumOneNumber));
	s.push_back(CUTE(shouldSumTwoNumbersOnTwoLines));
	s.push_back(CUTE(shouldSumTwoNumbers));
	s.push_back(CUTE(shouldSumOneNegativeNumber));
	s.push_back(CUTE(shouldSumTwoNegativeNumbers));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
