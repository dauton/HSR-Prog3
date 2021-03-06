#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "calc.h"

void testAddPositiveNumbers() {
	int result = calc(5, 7, '+');
	ASSERT_EQUAL(12, result);
}
void testAddNegativeNumbers() {
	int result = calc(-5, -7, '+');
	ASSERT_EQUAL(-12, result);
}
void testAddNegativeAndPositiveNumber() {
	int result = calc(-5, 7, '+');
	ASSERT_EQUAL(2, result);
}
void testAddDecimalNumbers() {
	int result = calc(5.4, 8.7, '+');
	ASSERT_EQUAL(13, result);
}
void testAddNegativeDecimalNumbers() {
	int result = calc(-5.4, -8.7, '+');
	ASSERT_EQUAL(-13, result);
}
void testSubstractPositiveNumbers() {
	int result = calc(15, 6, '-');
	ASSERT_EQUAL(9, result);
}
void testSubstractNegativeNumbers() {
	int result = calc(-15, -3, '-');
	ASSERT_EQUAL(-12, result);
}
void testSubstractNegativeAndPositiveNumber() {
	int result = calc(-7, 9, '-');
	ASSERT_EQUAL(-16, result);
}
void testSubstractDecimalNumbers() {
	int result = calc(5.4, 8.7, '-');
	ASSERT_EQUAL(-3, result);
}
void testSubstractNegativeDecimalNumbers() {
	int result = calc(-5.4, -8.7, '-');
	ASSERT_EQUAL(3, result);
}
void testMultiplyPositiveNumbers() {
	int result = calc(5, 7, '*');
	ASSERT_EQUAL(35, result);
}
void testMultiplyNegativeNumbers() {
	int result = calc(-5, -7, '*');
	ASSERT_EQUAL(35, result);
}
void testMultiplyNegativeAndPositiveNumber() {
	int result = calc(-4, 7, '*');
	ASSERT_EQUAL(-28, result);
}
void testMultiplyDecimalNumbers() {
	int result = calc(5.4, 8.7, '*');
	ASSERT_EQUAL(40, result);
}
void testMultiplyNegativeDecimalNumbers() {
	int result = calc(-5.4, -8.7, '*');
	ASSERT_EQUAL(40, result);
}
void testMultiplyNegativeAndPositiveDecimalNumbers() {
	int result = calc(-3.4, 9.7, '*');
	ASSERT_EQUAL(-27, result);
}
void testDividePositiveNumbers() {
	int result = calc(10, 5, '/');
	ASSERT_EQUAL(2, result);
}
void testDividePositiveNumbersRest() {
	int result = calc(10, 3, '/');
	ASSERT_EQUAL(3, result);
}
void testDivideNegativeNumbers() {
	int result = calc(-8, -4, '/');
	ASSERT_EQUAL(2, result);
}
void testDivideNegativeNumbersRest() {
	int result = calc(-8, -5, '/');
	ASSERT_EQUAL(1, result);
}
void testDivideNegativeAndPositiveNumber() {
	int result = calc(-12, 6, '/');
	ASSERT_EQUAL(-2, result);
}
void testDivideDecimalNumbers() {
	int result = calc(5.4, 8.7, '/');
	ASSERT_EQUAL(0, result);
}
void testDivideNegativeDecimalNumbers() {
	int result = calc(-6.4, -2.7, '/');
	ASSERT_EQUAL(3, result);
}
void testDivideNegativeAndPositiveDecimalNumbers() {
	int result = calc(-9.4, 9.7, '/');
	ASSERT_EQUAL(-1, result);
}
void testDivideByPositiveZero() {
	ASSERT_THROWS(calc(-9.4,0,'/'), std::exception);
}
void testDivideByNegativeZero() {
	ASSERT_THROWS(calc(8,-0,'/'), std::exception);
}
void testModuloPositiveNumbers() {
	int result = calc(10, 5, '%');
	ASSERT_EQUAL(0, result);
}
void testModuloPositiveNumbersRest() {
	int result = calc(10, 3, '%');
	ASSERT_EQUAL(1, result);
}
void testModuloNegativeNumbers() {
	int result = calc(-8, -4, '%');
	ASSERT_EQUAL(0, result);
}
void testModuloNegativeNumbersRest() {
	int result = calc(-8, -5, '%');
	ASSERT_EQUAL(-3, result);
}
void testModuloNegativeAndPositiveNumber() {
	int result = calc(-12, 6, '%');
	ASSERT_EQUAL(0, result);
}
void testModuloDecimalNumbers() {
	int result = calc(5.4, 8.7, '%');
	ASSERT_EQUAL(5, result);
}
void testModuloNegativeDecimalNumbers() {
	int result = calc(-6.4, -2.7, '%');
	ASSERT_EQUAL(0, result);
}
void testModuloNegativeAndPositiveDecimalNumbers() {
	int result = calc(-9.9, 9.7, '%');
	ASSERT_EQUAL(0, result);
}
void testModuloByPositiveZero() {
	ASSERT_THROWS(calc(-9.4,0,'%'), std::exception);
}
void testModuloByNegativeZero() {
	ASSERT_THROWS(calc(8,-0,'%'), std::exception);
}
void testUnknownOperator() {
	ASSERT_THROWS(calc(1,1,'x'), std::exception);
}
void testStreamVariantAdd() {
	std::stringstream operation{" 2 +   7"};
	int result = calc(operation);
	ASSERT_EQUAL(9, result);
}
void testStreamVariantSubtract() {
	std::stringstream operation{" -2 --3"};
	int result = calc(operation);
	ASSERT_EQUAL(1, result);
}
void testStreamVariantMultiply() {
	std::stringstream operation{"    -2 *    -3"};
	int result = calc(operation);
	ASSERT_EQUAL(6, result);
}
void testStreamVariantDivision() {
	std::stringstream operation{"-15/3"};
	int result = calc(operation);
	ASSERT_EQUAL(-5, result);
}
void testStreamVariantModulo() {
	std::stringstream operation{" -2 % 3"};
	int result = calc(operation);
	ASSERT_EQUAL(-2, result);
}
void testStreamVariantDivisionZero() {
	std::stringstream operation{" -0 /     0"};
	ASSERT_THROWS(calc(operation), std::exception);
}
void testStreamVariantModuloZero() {
	std::stringstream operation{" -10 %     0"};
	ASSERT_THROWS(calc(operation), std::exception);
}
void testStreamVariantUnknownOperator() {
	std::stringstream operation{" -10 ö     0"};
	ASSERT_THROWS(calc(operation), std::exception);
}
void testStreamVariantWrongFormat() {
	std::stringstream operation{" z 5 * 7"};
	ASSERT_THROWS(calc(operation), std::exception);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testAddPositiveNumbers));
	s.push_back(CUTE(testAddNegativeNumbers));
	s.push_back(CUTE(testAddNegativeAndPositiveNumber));
	s.push_back(CUTE(testAddDecimalNumbers));
	s.push_back(CUTE(testAddNegativeDecimalNumbers));
	s.push_back(CUTE(testSubstractPositiveNumbers));
	s.push_back(CUTE(testSubstractNegativeNumbers));
	s.push_back(CUTE(testSubstractNegativeAndPositiveNumber));
	s.push_back(CUTE(testSubstractDecimalNumbers));
	s.push_back(CUTE(testSubstractNegativeDecimalNumbers));
	s.push_back(CUTE(testMultiplyPositiveNumbers));
	s.push_back(CUTE(testMultiplyNegativeNumbers));
	s.push_back(CUTE(testMultiplyNegativeAndPositiveNumber));
	s.push_back(CUTE(testMultiplyDecimalNumbers));
	s.push_back(CUTE(testMultiplyNegativeDecimalNumbers));
	s.push_back(CUTE(testMultiplyNegativeAndPositiveDecimalNumbers));
	s.push_back(CUTE(testDividePositiveNumbers));
	s.push_back(CUTE(testDividePositiveNumbersRest));
	s.push_back(CUTE(testDivideNegativeNumbers));
	s.push_back(CUTE(testDivideNegativeNumbersRest));
	s.push_back(CUTE(testDivideNegativeAndPositiveNumber));
	s.push_back(CUTE(testDivideDecimalNumbers));
	s.push_back(CUTE(testDivideNegativeDecimalNumbers));
	s.push_back(CUTE(testDivideNegativeAndPositiveDecimalNumbers));
	s.push_back(CUTE(testDivideByPositiveZero));
	s.push_back(CUTE(testDivideByNegativeZero));
	s.push_back(CUTE(testUnknownOperator));
	s.push_back(CUTE(testModuloPositiveNumbers));
	s.push_back(CUTE(testModuloPositiveNumbersRest));
	s.push_back(CUTE(testModuloNegativeNumbers));
	s.push_back(CUTE(testModuloNegativeNumbersRest));
	s.push_back(CUTE(testModuloNegativeAndPositiveNumber));
	s.push_back(CUTE(testModuloDecimalNumbers));
	s.push_back(CUTE(testModuloNegativeDecimalNumbers));
	s.push_back(CUTE(testModuloNegativeAndPositiveDecimalNumbers));
	s.push_back(CUTE(testModuloByPositiveZero));
	s.push_back(CUTE(testModuloByNegativeZero));
	s.push_back(CUTE(testStreamVariantAdd));
	s.push_back(CUTE(testStreamVariantSubtract));
	s.push_back(CUTE(testStreamVariantMultiply));
	s.push_back(CUTE(testStreamVariantDivision));
	s.push_back(CUTE(testStreamVariantModulo));
	s.push_back(CUTE(testStreamVariantDivisionZero));
	s.push_back(CUTE(testStreamVariantModuloZero));
	s.push_back(CUTE(testStreamVariantUnknownOperator));
	s.push_back(CUTE(testStreamVariantWrongFormat));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}

