#include "tester.h"

/* First Testes */
void testDirectGraph();
void testUnDirectGraph();

void Tester::executeExamples() {
    cout << "================================================" << endl;
    cout << "Test UnDirected Graph" << endl;
    cout << "================================================" << endl;
    testUnDirectGraph();
    cout << endl;

    cout << "================================================" << endl;
    cout << "Test Directed Graph" << endl;
    cout << "================================================" << endl;
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
    cout << "================================================" << endl;
    cout << "Test Parser" << endl;
    cout << "================================================" << endl;

    AirportParser airportsparse(
        "D:\\Documentos\\AED-graph-project-electrogatos\\src\\Parser\\Data\\pe.json");
    cout << endl;
    cout << "================================================" << endl;
    cout << "uGraphMake" << endl;
    cout << "================================================" << endl;
    // uGraphMake
    UnDirectedGraph<string, double> airports;
    airportsparse.uGraphMake(airports);
    // cout << endl;
    cout << "\nDisplay unDirected Graph\n";
    airports.display();

    cout << "\nfindById(6067 - Huanuco): " << std::boolalpha << airports.findById(6067) << endl;

    cout << "\ndisplayVertex(6067 - Huanuco)\n";
    cout << airports.displayVertex(6067) << endl;

    cout << "\nexecKruskal()\n";
    Kruskal<string, double> kruskal(airports);
    UnDirectedGraph<string, double> mst = kruskal.apply();
    mst.display();

    cout << "\nisConnected(): " << std::boolalpha << airports.isConnected() << endl;

    cout << "\nexecPrim()\n";
    Prim<string, double> Prim(airports, "2789");
    UnDirectedGraph<string, double> mstp = Prim.apply();
    mstp.display();

    cout << "\nexecDFS()\n";
    DFS<string, double> DFS(airports);
    Graph<string, double>* dsf = new UnDirectedGraph<string, double>();
    // UnDirectedGraph<string, float> dsf = DFS.apply();
    dsf = DFS.apply();
    dsf->display();

    cout << "\nexecBFS()\n";
    BFS<string, double> BFS(airports);
    Graph<string, double>* bfs = new UnDirectedGraph<string, double>();
    // UnDirectedGraph<string, float> bfs = BFS.apply();
    bfs = BFS.apply();
    bfs->display();

    cout << "\nDensity: \n";
    cout << airports.density();

    cout << "\nisDense(): " << std::boolalpha << airports.isDense() << endl;

    cout << "\nempty(): " << std::boolalpha << airports.empty() << endl;

    cout << "\nDelete Vertex id: 2789 (Lima)\n";
    airports.deleteVertex(2789);
    airports.display();

    cout << "\nDelete Edge Pucallpa - Iquitos \n";
    airports.deleteEdge(2781, 2801);
    airports.display();

    cout << endl;
    cout << "================================================" << endl;
    cout << "dGraphMake" << endl;
    cout << "================================================" << endl;
    // dGraphMake
    DirectedGraph<string, double> airports_d;
    airportsparse.dGraphMake(airports_d);
    // cout << endl;
    cout << "\nDisplay Directed Graph\n";
    airports_d.display();
}

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

    // // test dijkstra geekforgeeks
    // graph.insertVertex(1, '0');
    // graph.insertVertex(2, '1');
    // graph.insertVertex(3, '2');
    // graph.insertVertex(4, '3');
    // graph.createEdge(1, 3, 4);//0-2
    // graph.createEdge(3, 1, 5);//2-0
    // graph.createEdge(1, 2, 4);//0-1
    // graph.createEdge(2, 3, 4);//1-2
    // graph.createEdge(3, 4, 4);//2-3
    // graph.createEdge(4, 4, 4);//3-3

    // // test bellmanford geekforgeeks
    // graph.insertVertex(1, 'A');
    // graph.insertVertex(2, 'B');
    // graph.insertVertex(3, 'C');
    // graph.insertVertex(4, 'D');
    // graph.insertVertex(5, 'E');
    // graph.createEdge(1, 2, -1);//A-B
    // graph.createEdge(1, 3, 4);//A-C
    // graph.createEdge(2, 3, 3);//B-C
    // graph.createEdge(4, 3, 5);//D-C
    // graph.createEdge(4, 2, 1);//D-B
    // graph.createEdge(2, 4, 2);//B-D
    // graph.createEdge(5, 4, -3);//E-D
    // graph.createEdge(2, 5, 2);//B-E

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

    cout << "\nexecDFS()\n";
    DFS<char, float> DFS(graph);
    Graph<char, float>* dsf = new DirectedGraph<char, float>();
    dsf = DFS.apply();
    dsf->display();

    cout << "\nexecBFS()\n";
    BFS<char, float> BFS(graph);
    Graph<char, float>* bfs = new DirectedGraph<char, float>();
    bfs = BFS.apply();
    bfs->display();

    cout << "\nexecDijkstra()\n";
    Dijkstra<char, float> Dijkstra(graph);
    // Graph<char, float> *dijs = new DirectedGraph<char, float>();
    unordered_map<Vertex<char, float>*, float> rd = Dijkstra.apply();
    Dijkstra.displayresult();

    cout << "\nexecBellmanFord()\n";
    BellmanFord<char, float> BellmanFord(graph);
    // Graph<char, float> *bf = new DirectedGraph<char, float>();
    unordered_map<Vertex<char, float>*, float> rb = BellmanFord.apply();
    BellmanFord.displayresult();

    cout << "\nDelete Vertex id: 7 (B)\n";
    graph.deleteVertex(7);
    graph.display();

    cout << "\nDelete Edge I - G \n";
    graph.deleteEdge(10, 9);
    graph.display();

    cout << "\nDensity: \n";
    cout << graph.density();

    cout << "\nisDense(): " << std::boolalpha << graph.isDense() << endl;

    cout << "\nempty(): " << std::boolalpha << graph.empty() << endl;

    // // corregir
    // cout << "\nexecFloydWarshall()\n";
    // FloydWarshall<char, float> FloydWarshall(graph);
    // Graph<char, float> *dsf = new DirectedGraph<char, float>();
    // dsf = FloydWarshall.apply();
}

void testUnDirectGraph() {
    // // PPT Grafos Kruskal and Prim ejm
    //      1
    //  0 ------ 1 \-
    //  |      / |   \1
    // 6|   4/   |3   - 4
    //  |  /     |   /1
    //   2 ----- 3 /
    //      1
    UnDirectedGraph<string, float> graph;
    graph.insertVertex(1, "0");
    graph.insertVertex(2, "1");
    graph.insertVertex(3, "2");
    graph.insertVertex(4, "3");
    graph.insertVertex(5, "4");
    graph.createEdge(1, 3, 6);  // 0 - 2 | 6
    graph.createEdge(1, 2, 1);  // 0 - 1 | 1
    graph.createEdge(3, 2, 4);  // 2 - 1 | 4
    graph.createEdge(3, 4, 1);  // 2 - 3 | 1
    graph.createEdge(2, 4, 3);  // 1 - 3 | 3
    graph.createEdge(2, 5, 1);  // 1 - 4 | 1
    graph.createEdge(4, 5, 1);  // 3 - 4 | 1

    // For test
    // graph.insertVertex(1, "A");
    // graph.insertVertex(2, "B");
    // graph.insertVertex(3, "C");
    // graph.insertVertex(4, "D");
    // graph.insertVertex(5, "E");
    // graph.insertVertex(6, "F");
    // graph.insertVertex(7, "G");
    // graph.insertVertex(8, "H");
    // graph.insertVertex(9, "I");
    // graph.createEdge(1, 2, 6); //A-B
    // graph.createEdge(1, 5, 6); //A-E
    // graph.createEdge(1, 3, 6); //A-C
    // graph.createEdge(2, 3, 6); //B-C
    // graph.createEdge(2, 4, 6); //B-D
    // graph.createEdge(4, 3, 6); //D-C
    // graph.createEdge(3, 5, 6); //C-E
    // graph.createEdge(3, 6, 6); //C-F
    // graph.createEdge(5, 8, 6); //E-H
    // graph.createEdge(5, 7, 6); //E-G
    // graph.createEdge(7, 9, 6); //G-I
    // graph.createEdge(8, 9, 6); //H-I

    // display as adjacency list
    /*
     4: 1(1), 3(1),
     3: 2(1), 1(3), 4(1),
     2: 0(6), 1(4), 3(1),
     1: 0(1), 2(4), 3(3), 4(1),
     0: 2(6), 1(1),
    */
    graph.display();

    // True, False
    cout << "\nfindById(3): " << std::boolalpha << graph.findById(3) << endl;

    // display object
    /*
     2: 0(6), 1(4), 3(1)
    */
    cout << "\ndisplayVertex(3)\n";
    cout << graph.displayVertex(3) << endl;

    // For Prim and Kruskal
    /*
     0: 1(1),
     1: 4(1), 0(1),
     2: 3(1),
     3: 2(1), 4(1),
     4: 3(1), 1(1),
    */
    cout << "\nexecKruskal()\n";
    Kruskal<string, float> kruskal(graph);
    UnDirectedGraph<string, float> mstk = kruskal.apply();
    mstk.display();

    cout << "\nexecPrim()\n";
    Prim<string, float> Prim(graph, "0");
    UnDirectedGraph<string, float> mstp = Prim.apply();
    mstp.display();

    /*
     0: 2(1),
     1: 4(1),
     2: 3(1), 0(1),
     3: 4(1), 2(1),
     4: 1(1), 3(1),
    */
    cout << "\nexecDFS()\n";
    DFS<string, float> DFS(graph);
    Graph<string, float>* dsf = new UnDirectedGraph<string, float>();
    dsf = DFS.apply();
    dsf->display();

    /*
     0: 1(1),
     1: 4(1), 0(1), 2(1),
     2: 1(1),
     3: 4(1),
     4: 1(1), 3(1),
    */
    cout << "\nexecBFS()\n";
    BFS<string, float> BFS(graph);
    Graph<string, float>* bfs = new UnDirectedGraph<string, float>();
    bfs = BFS.apply();
    bfs->display();

    cout << "\nexecDijkstra()\n";
    Dijkstra<string, float> Dijkstra(graph);
    // Graph<string, float> *dijs = new UnDirectedGraph<string, float>();
    unordered_map<Vertex<string, float>*, float> result = Dijkstra.apply();
    Dijkstra.displayresult();

    cout << "\nisConnected(): " << std::boolalpha << graph.isConnected() << endl;

    cout << "\nDensity: \n";
    cout << graph.density();

    cout << "\nisDense(): " << std::boolalpha << graph.isDense() << endl;

    cout << "\nDelete Vertex id: 5 (4)\n";
    graph.deleteVertex(5);
    graph.display();

    cout << "\nDelete Edge 2 - 1 \n";
    graph.deleteEdge(3, 2);
    graph.display();

    cout << "\nempty(): " << std::boolalpha << graph.empty() << endl;
}
