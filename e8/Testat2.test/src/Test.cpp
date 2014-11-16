#include "Word.h"
#include "kwic.h"

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void createWord()
{
	std::istringstream iss {"Hammer"};
	std::ostringstream oss {};
	Word w {};

    iss >> w;
    w.print(oss);

    ASSERT_EQUAL("Hammer", oss.str());
}

void nonAlphaWord()
{
	std::istringstream iss {"89"};
	std::ostringstream oss {};
	Word w {};

	iss >> w;
	w.print(oss);

    ASSERT_EQUAL("", oss.str());
}

void wordEqual()
{
	std::istringstream iss {"SUMMER suMmer"};
	std::ostringstream oss {};
	Word w {};
	Word w2 {};

	iss >> w;
	iss >> w2;

	w.print(oss);

	ASSERT(w == w2);
	ASSERT_EQUAL(w, w2);
	ASSERT_EQUAL("SUMMER", oss.str());
}

void wordNotEqual() {
	std::istringstream iss {"kamm kammer"};
	std::ostringstream oss {};
	Word w {};
	Word w2 {};

	iss >> w;
	iss >> w2;

	w.print(oss);

	ASSERT(!(w == w2));
	ASSERT(!(oss.str() == "komm"));
}

void wordLessThan()
{
	std::istringstream iss {"Hammer Hammerschlag"};
	std::ostringstream oss {};
	Word w {};
	Word w2 {};

	iss >> w;
	iss >> w2;

	ASSERT(w < w2);
}

void wordNotLessThan()
{
	std::istringstream iss {"Zug Zack"};
	std::ostringstream oss {};
	Word w {};
	Word w2 {};

	iss >> w;
	iss >> w2;

	ASSERT(!(w < w2));
}

void wordOutput()
{
	std::istringstream iss {"Servus"};
	std::ostringstream oss {};
	Word w {};

	iss >> w;
	w.print(oss);

    ASSERT_EQUAL("Servus", oss.str());
}

void wordStreamInput()
{
	std::istringstream iss {"Servus alle/2?miteinander! Gruss"};
	std::ostringstream oss {};
	Word w {};

	iss >> w;
	w.print(oss);

	ASSERT_EQUAL("Servus", oss.str());
}

void wordStreamInputInvalid()
{
	std::istringstream iss {"78/[]"};
	std::ostringstream oss {};
	Word w{};

	iss >> w;
	w.print(oss);

	ASSERT_EQUAL("", oss.str());
}

void emptyInput()
{
	std::istringstream in {""};
	std::ostringstream out {};

	generateKwic(in, out);
	ASSERT_EQUAL(out.str(), "");
}

void oneLine()
{
	std::istringstream in {"hi ho"};
	std::ostringstream out {};

	generateKwic(in, out);
	ASSERT_EQUAL(out.str(), "hi ho \n"
							"ho hi \n");
}

void twoLine()
{
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

void ignoreEmptyLines()
{
	std::istringstream in {	"this is a test\n"
							"\n"
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

void ignoreInvalidInput()
{
	std::istringstream in {	"this is a test\n"
							"hiäho\n"
							"this is another test"};
	std::ostringstream out {};

	generateKwic(in, out);
	ASSERT_EQUAL(out.str(), "a test this is \n"
							"another test this is \n"
							"hi ho \n"
							"ho hi \n"
							"is a test this \n"
							"is another test this \n"
							"test this is a \n"
							"test this is another \n"
							"this is a test \n"
							"this is another test \n");
}

void differentLineLenghts()
{
	std::istringstream in {	"this is a test\n"
							"this is a second test"};
	std::ostringstream out {};

	generateKwic(in, out);
	ASSERT_EQUAL(out.str(), "a second test this is \n"
							"a test this is \n"
							"is a second test this \n"
							"is a test this \n"
							"second test this is a \n"
							"test this is a \n"
							"test this is a second \n"
							"this is a second test \n"
							"this is a test \n");
}

void runAllTests(int argc, char const *argv[])
{
	cute::suite s;
	s.push_back(CUTE(createWord));
	s.push_back(CUTE(nonAlphaWord));
	s.push_back(CUTE(wordEqual));
	s.push_back(CUTE(wordNotEqual));
	s.push_back(CUTE(wordLessThan));
	s.push_back(CUTE(wordNotLessThan));
	s.push_back(CUTE(wordOutput));
	s.push_back(CUTE(wordStreamInput));
	s.push_back(CUTE(wordStreamInputInvalid));
	s.push_back(CUTE(oneLine));
	s.push_back(CUTE(twoLine));
	s.push_back(CUTE(emptyInput));
	s.push_back(CUTE(differentLineLenghts));
	s.push_back(CUTE(ignoreEmptyLines));
	s.push_back(CUTE(ignoreInvalidInput));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[])
{
    runAllTests(argc, argv);
}


