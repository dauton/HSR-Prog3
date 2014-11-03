#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Word.h"


void createWord() {
    Word w {"hoi"};
    ASSERT_EQUAL(w, "hoi");
}
void emptyWord() {
    ASSERT_THROWS(Word{""}, std::logic_error);
}
void nonAlphaWord(){
    ASSERT_THROWS(Word{"a12"}, std::logic_error);
}


void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(createWord));
	s.push_back(CUTE(emptyWord));
	s.push_back(CUTE(nonAlphaWord));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}


