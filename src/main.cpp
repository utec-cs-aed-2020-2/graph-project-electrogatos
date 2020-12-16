#include <iostream>

//#include "Parser/parser.h"
#include "Tester/tester.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "================================================" << endl;
    cout << "MENU GRAPH TESTER" << endl;
    cout << "================================================" << endl;

    Tester::executeExamples();
    // Tester::executeParser();

    return EXIT_SUCCESS;
}
