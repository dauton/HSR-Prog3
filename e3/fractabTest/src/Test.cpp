#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "fractab.h"

void shouldPrintSimpleTable() {
	std::ostringstream out{};
	fractab(out, 2);
	ASSERT_EQUAL( "1\t2\t\n2\t4\t\n", out.str() );
}

void shouldLookLikeLoopGenerated(){
	std::ostringstream out{};
	fractab(out, 20);

	std::string compare{};
	for(int line = 1; line <= 20; line++) {
		for( int col = 1; col <= 20; col++) {
			compare.append( std::to_string( line*col ) );
			if ( col == 20 ) {
				compare.append("\t\n");
			} else {
				compare.append("\t");
			}
		}
	}
	ASSERT_EQUAL( compare, out.str() );
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(shouldPrintSimpleTable));
	s.push_back(CUTE(shouldLookLikeLoopGenerated));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



