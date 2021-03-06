#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "sevenseg.h"

void shouldPrintZero() {
	std::ostringstream out{};
	printLargeDigit(0, out);
	ASSERT_EQUAL(" - \n| |\n   \n| |\n - \n", out.str());
}

void shouldPrintOne() {
	std::ostringstream out{};
	printLargeDigit(1, out);
	ASSERT_EQUAL("   \n  |\n   \n  |\n   \n", out.str());
}

void shouldPrintTwo() {
	std::ostringstream out{};
	printLargeDigit(2, out);
	ASSERT_EQUAL(" - \n  |\n - \n|  \n - \n", out.str());
}

void shouldPrintThree() {
	std::ostringstream out{};
	printLargeDigit(3, out);
	ASSERT_EQUAL(" - \n  |\n - \n  |\n - \n", out.str());
}

void shouldPrintFour() {
	std::ostringstream out{};
	printLargeDigit(4, out);
	ASSERT_EQUAL("   \n| |\n - \n  |\n   \n", out.str());
}

void shouldPrintFive() {
	std::ostringstream out{};
	printLargeDigit(5, out);
	ASSERT_EQUAL(" - \n|  \n - \n  |\n - \n", out.str());
}

void shouldPrintSix() {
	std::ostringstream out{};
	printLargeDigit(6, out);
	ASSERT_EQUAL(" - \n|  \n - \n| |\n - \n", out.str());
}

void shouldPrintSeven() {
	std::ostringstream out{};
	printLargeDigit(7, out);
	ASSERT_EQUAL(" - \n| |\n   \n  |\n   \n", out.str());
}

void shouldPrintEight() {
	std::ostringstream out{};
	printLargeDigit(8, out);
	ASSERT_EQUAL(" - \n| |\n - \n| |\n - \n", out.str());
}

void shouldPrintNine() {
	std::ostringstream out{};
	printLargeDigit(9, out);
	ASSERT_EQUAL(" - \n| |\n - \n  |\n - \n", out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(shouldPrintZero));
	s.push_back(CUTE(shouldPrintOne));
	s.push_back(CUTE(shouldPrintTwo));
	s.push_back(CUTE(shouldPrintThree));
	s.push_back(CUTE(shouldPrintFour));
	s.push_back(CUTE(shouldPrintFive));
	s.push_back(CUTE(shouldPrintSix));
	s.push_back(CUTE(shouldPrintSeven));
	s.push_back(CUTE(shouldPrintEight));
	s.push_back(CUTE(shouldPrintNine));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



