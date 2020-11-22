#ifndef TESTER_H
#define TESTER_H

#include <assert.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "../Graph/directedGraph.h"
#include "../Graph/undirectedGraph.h"
#include "../Parser/parser.h"
#include "../Graph/Algoritmos/kruskal.h"
#include "../Graph/Algoritmos/prim.h"
#include "../Graph/Algoritmos/depthfs.h"
#include "../Graph/Algoritmos/breadthfs.h"

using namespace std;

#define ASSERT(condition, message)                                                       \
    do {                                                                                 \
        if (!(condition)) {                                                              \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ << " line " \
                      << __LINE__ << ": " << message << std::endl;                       \
            std::terminate();                                                            \
        }                                                                                \
    } while (false)

class Tester {
   private:
    static void testDeleteVertex();
    static void testDeleteEdge();
    static void testDensity();
    static void testConnected();
    static void testStronglyConnected();
    static void testKruskal();
    static void testPrim();

   public:
    static void executeExamples();
    static void executeParser();
};

#endif