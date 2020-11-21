#include "tester.h"

/* First Testes */
void testDirectGraph();
void testUnDirectGraph();

void Tester::executeExamples() {
    cout << "Test UnDirected Graph" << endl;
    testUnDirectGraph();
    cout << endl;

    cout << "Test Directed Graph" << endl;
    testDirectGraph();
    cout << endl;

    // for (int j = 0; j < NUMBER_OF_TESTS; ++j) {
    //     UnDirectedGraph<Data, Data> graph;

    //     float density =
    //         2 * float(NUMBER_OF_EDGES) / (float(NUMBER_OF_VERTEXES) * (NUMBER_OF_VERTEXES - 1));

    //     ASSERT(density == graph.density(), "density function has problems");

    //     bool dense = density >= densityThreshold;
    //     ASSERT(graph.isDense() == dense, "isDense function has problems");

    //     ASSERT(graph.isConnected(), "isConnected function has problems");

    //     ASSERT(graph.isStronglyConnected(), "isStronglyConnected has problems");

    //     testStronglyConnected();
    //     testKruskal();
    //     testPrim();
    //     cout << "All tests passed" << endl;
    // }
}

void Tester::executeParser() {
    cout << "Test Parser" << endl;
    AirportParser airportsparse("/Users/jamesatachagua/Desktop/Ciclo9/Algoritmos/vscode/proyecto/graph-project-electrogatos/src/Parser/Data/pe.json");
    UnDirectedGraph<string, double> airports;
    airportsparse.uGraphMake(airports);
    cout << endl;
    cout << "\nDisplay unDirected Graph\n";
    airports.display();

    cout << "\nfindById(6067 - Huanuco): " << std::boolalpha << airports.findById(6067) << endl;

    cout << "\ndisplayVertex(6067 - Huanuco)\n";
    cout << airports.displayVertex(6067) << endl;

    // cout << "\nexecKruskal()\n";
    // UnDirectedGraph<string, double> mst = airports.execKruskal();
    // mst.display();

    // cout << "isConnected(): " << std::boolalpha << airports.isConnected() << endl;
}

void Tester::testDeleteVertex() {}
void Tester::testDeleteEdge() {}
void Tester::testDensity() {}
void Tester::testConnected() {}
void Tester::testStronglyConnected() {}
void Tester::testKruskal() {}
void Tester::testPrim() {}

/* First Testes */
void testDirectGraph() {
    DirectedGraph<char, float> graph;
    graph.insertVertex(1, 'J');
    graph.insertVertex(2, 'F');
    graph.insertVertex(3, 'C');
    graph.insertVertex(4, 'D');
    graph.insertVertex(5, 'A');
    graph.insertVertex(6, 'H');
    graph.insertVertex(7, 'B');
    graph.insertVertex(8, 'E');
    graph.insertVertex(9, 'G');
    graph.insertVertex(10, 'I');

    graph.createEdge(1, 2, 4);    // J - F | 4
    graph.createEdge(2, 3, 7);    // F - C | 7
    graph.createEdge(3, 4, 11);   // C - D | 11
    graph.createEdge(2, 4, 58);   // F - D | 58
    graph.createEdge(2, 5, 17);   // F - A | 17
    graph.createEdge(1, 5, 14);   // J - A | 14
    graph.createEdge(3, 6, 24);   // C - H | 24
    graph.createEdge(4, 5, 42);   // D - A | 42
    graph.createEdge(1, 8, 5);    // J - E | 5
    graph.createEdge(4, 6, 26);   // D - H | 26
    graph.createEdge(4, 7, 19);   // D - B | 19
    graph.createEdge(5, 7, 5);    // A - B | 5
    graph.createEdge(5, 8, 11);   // A - E | 11
    graph.createEdge(6, 7, 64);   // H - B | 64
    graph.createEdge(8, 10, 29);  // E - I | 29
    graph.createEdge(6, 9, 3);    // H - G | 3
    graph.createEdge(7, 9, 52);   // B - G | 52
    graph.createEdge(7, 10, 51);  // B - I | 51
    graph.createEdge(10, 9, 33);  // I - G | 33

    // display as adjacency list
    /*
     E:  I(29), J(5), A(11)
     J:  A(14), F(4)
    */
    graph.display();

    // True, False
    cout << "\nfindById(6): " << std::boolalpha << graph.findById(6) << endl;

    // display object
    /*
     E:  I(29), J(5), A(11)
    */
    cout << "\ndisplayVertex(6)\n";
    cout << graph.displayVertex(6) << endl;

    cout << "isStronglyConnected(): " << std::boolalpha << graph.isStronglyConnected() << endl;

    cout << "\nDelete Vertex id: 7 (B)\n";
    graph.deleteVertex(7);
    graph.display();

    cout << "\nDelete Edge I - G \n";
    graph.deleteEdge(10, 9);
    graph.display();
}

void testUnDirectGraph() {
    UnDirectedGraph<string, float> graph;
    graph.insertVertex(1, "J");
    graph.insertVertex(2, "F");
    graph.insertVertex(3, "C");
    graph.insertVertex(4, "D");
    graph.insertVertex(5, "A");
    graph.insertVertex(6, "H");
    graph.insertVertex(7, "B");
    graph.insertVertex(8, "E");
    graph.insertVertex(9, "G");
    graph.insertVertex(10, "I");

    graph.createEdge(1, 2, 4);    // J - F | 4
    graph.createEdge(2, 3, 7);    // F - C | 7
    graph.createEdge(1, 3, 10);    // F - C | 7
    // graph.createEdge(3, 2, 10);    // C - F | 7 // Test to existe edge
    graph.createEdge(3, 4, 11);   // C - D | 11
    graph.createEdge(2, 4, 58);   // F - D | 58
    graph.createEdge(2, 5, 17);   // F - A | 17
    graph.createEdge(1, 5, 14);   // J - A | 14
    graph.createEdge(3, 6, 24);   // C - H | 24
    graph.createEdge(4, 5, 42);   // D - A | 42
    graph.createEdge(1, 8, 5);    // J - E | 5
    graph.createEdge(4, 6, 26);   // D - H | 26
    graph.createEdge(4, 7, 19);   // D - B | 19
    graph.createEdge(5, 7, 5);    // A - B | 5
    graph.createEdge(5, 8, 11);   // A - E | 11
    graph.createEdge(6, 7, 64);   // H - B | 64
    graph.createEdge(8, 10, 29);  // E - I | 29
    graph.createEdge(6, 9, 3);    // H - G | 3
    graph.createEdge(7, 9, 52);   // B - G | 52
    graph.createEdge(7, 10, 51);  // B - I | 51
    graph.createEdge(10, 9, 33);  // I - G | 33

    // display as adjacency list
    /*
     E:  I(29), J(5), A(11)
     J:  A(14), F(4)
    */
    graph.display();

    // True, False
    cout << "\nfindById(6): " << std::boolalpha << graph.findById(6) << endl;

    // display object
    /*
     E:  I(29), J(5), A(11)
    */
    cout << "\ndisplayVertex(6)\n";
    cout << graph.displayVertex(6) << endl;

    cout << "\nexecKruskal()\n";
    Kruskal<string, float> kruskal(graph);
    UnDirectedGraph<string, float> mst = kruskal.apply();
    // UnDirectedGraph<string, float> mst = graph.execKruskal();
    mst.display();

    cout << "\nexecDFS()\n";
    DFS<string, float> DFS(graph);
    UnDirectedGraph<string, float> dsf = DFS.apply();
    // UnDirectedGraph<char, float> dsf = graph.execDFS();
    dsf.display();

    cout << "\nexecBFS()\n";
    BFS<string, float> BFS(graph);
    UnDirectedGraph<string, float> bfs = BFS.apply();
    // UnDirectedGraph<char, float> bfs = graph.execBFS();
    bfs.display();

    cout << "\nisConnected(): " << std::boolalpha << graph.isConnected() << endl;

    cout << "\nDelete Vertex id: 7 (B)\n";
    graph.deleteVertex(7);
    graph.display();

    cout << "\nDelete Edge I - G \n";
    graph.deleteEdge(10, 9);
    graph.display();
}