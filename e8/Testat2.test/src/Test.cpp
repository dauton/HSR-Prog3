#include "Word.h"
#include "kwic.h"

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void createWord() {
    Word w {"Hammer"};
    ASSERT_EQUAL(w, "Hammer");
}
void emptyWord() {
    ASSERT_THROWS(Word{""}, std::logic_error);
}
void nonAlphaWord(){
    ASSERT_THROWS(Word{"89"}, std::logic_error);
}
void wordEqual() {
	 Word w1 {"SUMMER"};
	 Word w2 {"SuMmer"};

	 ASSERT(w1 == w2);
	 ASSERT_EQUAL(w1, "summer");
	 ASSERT_EQUAL(w1, w2);
}

void wordNotEqual() {
	 Word w1 {"kamm"};
	 Word w2 {"kammer"};
	 ASSERT(!(w1 == w2));
	 ASSERT(!(w1 == "komm"));
}

void wordLessThan(){
    Word w1{"Hammer"};
    Word w2{"Hammerschlag"};
    ASSERT(w1 < w2);
    ASSERT(w2 < "Schlaghammer");
}

void wordNotLessThan(){
    Word w1{"Zug"};
    Word w2{"Zack"};
    ASSERT(!(w1 < w2));
    ASSERT(!(w1 < w1));
    ASSERT_EQUAL(w1, w1);
}

void wordOutput(){
    std::ostringstream out;
    Word w{"Servus"};
    out << w;
    ASSERT_EQUAL("Servus",out.str());
}

void wordStreamInput(){
	std::istringstream in {"Servus alle/2?miteinander! Gruss"};
	Word w{"init"}; // Word can not be blank!

	in >> w;
	ASSERT_EQUAL(w, "servus");
	in >> w;
	ASSERT_EQUAL(w, "alle");
	in >> w;
	ASSERT_EQUAL(w, "miteinander");
	in >> w;
	ASSERT_EQUAL(w, "gruss");
}

void wordStreamInputInvalid(){
	std::istringstream inEmpty{""};
	std::istringstream inNonAlpha {"78/[]"};
	Word w{"init"}; // Word can not be blank!

	inEmpty >> w;
	ASSERT(inEmpty.fail());

	inNonAlpha >> w;
	ASSERT(inNonAlpha.fail());

	ASSERT_EQUAL(w, "init"); // w not overridden
}

void oneLine() {
	std::istringstream in {"hi ho"};
	std::ostringstream out {};

	generateKwic(in, out);
	ASSERT_EQUAL(out.str(), "hi ho \n"
							"ho hi \n");
}

void twoLine() {
	std::istringstream in {	"this is a test\n"
							"this is another test"};
	std::ostringstream out {};

	generateKwic(in, out);
	ASSERT_EQUAL(out.str(), "a test this is \n"
							"another test this is \n"
							"is a test this \n"
							"is another test this \n"
							"test this is a \n"
							"test this is another \n"
							"this is a test \n"
							"this is another test \n");
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(createWord));
	s.push_back(CUTE(emptyWord));
	s.push_back(CUTE(nonAlphaWord));
	s.push_back(CUTE(wordLessThan));
	s.push_back(CUTE(wordEqual));
	s.push_back(CUTE(wordNotEqual));
	s.push_back(CUTE(wordNotLessThan));
	s.push_back(CUTE(wordOutput));
	s.push_back(CUTE(wordStreamInput));
	s.push_back(CUTE(wordStreamInputInvalid));
	s.push_back(CUTE(oneLine));
	s.push_back(CUTE(twoLine));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}


