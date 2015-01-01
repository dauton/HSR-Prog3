#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "sumi.h"

void shouldCountZero() {
	std::istringstream in {""};
	std::ostringstream out {};

	sum(in, out);

	ASSERT_EQUAL("0", out.str());
}

void shouldCount3() {
	std::istringstream in {"1 2"};
	std::ostringstream out {};

	sum(in, out);

	ASSERT_EQUAL("3", out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(shouldCountZero));
	s.push_back(CUTE(shouldCount3));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



