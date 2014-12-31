#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "acount.h"

void shouldCountOne() {
	std::istringstream in {"a"};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL(out.str(), "1");
}

void shouldCountTwo() {
	std::istringstream in1 {"aa"};
	std::istringstream in2 {"a a"};
	std::ostringstream out1 {};
	std::ostringstream out2 {};

	count(in1, out1);
	count(in2, out2);

	ASSERT_EQUAL(out1.str(), "2");
	ASSERT_EQUAL(out2.str(), "2");
}

void shouldCountNone() {
	std::istringstream in {"hello"};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL(out.str(), "0");
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(shouldCountOne));
	s.push_back(CUTE(shouldCountTwo));
	s.push_back(CUTE(shouldCountNone));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



