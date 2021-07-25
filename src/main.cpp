#include <iostream>

//#include "Parser/parser.h"
#include "Tester/tester.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "================================================" << endl;
    cout << "MENU GRAPH TESTER" << endl;
    cout << "================================================" << endl;

    // Tester::executeExamples();
    // Tester::executeParser();

    Tester::testTSP();
    Tester::testTSP_Parser1();
    Tester::testTSP_Parser2();

    return EXIT_SUCCESS;
}
