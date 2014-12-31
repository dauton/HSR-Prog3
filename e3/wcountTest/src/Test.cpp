#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "wcount.h"

void shouldCountOne() {
	std::istringstream in {"hello"};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL(out.str(), "1");
}

void shouldCountTwo() {
	std::istringstream in {"hello hello"};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL(out.str(), "2");
}

void shouldCountNone() {
	std::istringstream in {"   "};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL(out.str(), "0");
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
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



