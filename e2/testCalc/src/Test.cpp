#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "calc.h"
#include <cmath>

void shouldAddTwoPositiveNumbers() {
	int sum = calc(1, 1, '+');
	ASSERT_EQUAL(2, sum);
}

void shouldAddTwoNegativeNumbers() {
	int sum = calc(-1, -1, '+');
	ASSERT_EQUAL(-2, sum);
}

void shouldAddTwoNumbers() {
	int sum = calc(1, 0, '+');
	ASSERT_EQUAL(1, sum);
}

void shouldSubstractTwoPostiveNumbers() {
	int result = calc(1, 1, '-');
	ASSERT_EQUAL(0, result);
}

void shouldSubstractTwoNegativeNumbers() {
	int result = calc(-1, -1, '-');
	ASSERT_EQUAL(0, result);
}

void shouldSubstractTwoNumbers() {
	int result = calc(-1, 0, '-');
	ASSERT_EQUAL(-1, result);
}

void shouldDivideNonZeroNumber() {
	int result = calc(5, 2, '/');
	ASSERT_EQUAL(2, result); // since integer
}

void shouldDivideNonZeroNegativeNumber() {
	int result = calc(5, -2, '/');
	ASSERT_EQUAL(-2, result); // since integer
}

void shouldDivideByZero() {
	ASSERT_THROWS(calc(5, 0, '/'), std::exception); //also, inline.
}

void shouldMultiplyByZero() {
	int result = calc(5, 0, '*');
	ASSERT_EQUAL(0, result); // since integer
}

void shouldMultiplyTwoNumbers() {
	int result = calc(5, 3, '*');
	ASSERT_EQUAL(15, result); // since integer
}

void shouldMultiplyTwoNegativeNumbers() {
	int result = calc(5, -3, '*');
	ASSERT_EQUAL(-15, result); // since integer
}

void shouldModuloTwoNumbers() {
	int result = calc(5, 3, '%');
	ASSERT_EQUAL(2, result); // since integer
}

void shouldModuloTwoNegativeNumbers() {
	int result = calc(5, -3, '%');
	ASSERT_EQUAL(2, result); // since integer
}

void testUnknownOperator() {
	ASSERT_THROWS(calc(1,1,'_'), std::exception);
}

void testIStreamWay() {
	std::stringstream testStream("32%");
	ASSERT_EQUAL(1, calc(testStream));
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldAddTwoPositiveNumbers));
	s.push_back(CUTE(shouldAddTwoNegativeNumbers));
	s.push_back(CUTE(shouldAddTwoNumbers));
	s.push_back(CUTE(shouldSubstractTwoNumbers));
	s.push_back(CUTE(shouldSubstractTwoNegativeNumbers));
	s.push_back(CUTE(shouldSubstractTwoPostiveNumbers));
	s.push_back(CUTE(shouldDivideNonZeroNumber));
	s.push_back(CUTE(shouldDivideNonZeroNegativeNumber));
	s.push_back(CUTE(shouldDivideByZero));
	s.push_back(CUTE(shouldMultiplyByZero));
	s.push_back(CUTE(shouldMultiplyTwoNegativeNumbers));
	s.push_back(CUTE(shouldMultiplyTwoNumbers));
	s.push_back(CUTE(shouldModuloTwoNumbers));
	s.push_back(CUTE(shouldModuloTwoNegativeNumbers));
	s.push_back(CUTE(testUnknownOperator));
	s.push_back(CUTE(testIStreamWay));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
