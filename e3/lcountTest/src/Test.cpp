#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "lcount.h"

void shouldCountOne() {
	std::istringstream in {"hello\n"};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL("1", out.str());
}

void shouldCountTwo() {
	std::istringstream in {"hello\nhello\n"};
	std::ostringstream out {};

	count(in, out);

	ASSERT_EQUAL("2", out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(shouldCountOne));
	s.push_back(CUTE(shouldCountTwo));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



