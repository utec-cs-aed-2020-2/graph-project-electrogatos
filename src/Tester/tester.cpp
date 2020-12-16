#include "tester.h"

/* First Testes */
void testDirectGraph();
void testUnDirectGraph();

void Tester::executeExamples() {
    cout << "================================================" << endl;
    cout << "Test UnDirected Graph" << endl;
    cout << "================================================" << endl;
    // testUnDirectGraph();
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

    // AirportParser airportsparse(
    //     "D:\\Documentos\\AED-graph-project-electrogatos\\src\\Parser\\Data\\pe.json");
    AirportParser airportsparse(
        "/Users/jamesatachagua/Desktop/Ciclo9/Algoritmos/vscode/proyecto/graph-project-electrogatos/src/Parser/Data/pe.json");
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
    DFS<string, double> DFS(airports, "2789");
    Graph<string, double>* dsf = new UnDirectedGraph<string, double>();
    // UnDirectedGraph<string, float> dsf = DFS.apply();
    dsf = DFS.apply();
    dsf->display();

    cout << "\nexecBFS()\n";
    BFS<string, double> BFS(airports, "2789");
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

    // // test BFS Y DFS geekforgeeks
    // // DFS: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
    // graph.insertVertex(1, '0');
    // graph.insertVertex(2, '1');
    // graph.insertVertex(3, '2');
    // graph.insertVertex(4, '3');
    // graph.createEdge(1, 3, 4);// 0-2
    // graph.createEdge(3, 1, 4);// 2-0
    // graph.createEdge(1, 2, 4);// 0-1
    // graph.createEdge(2, 3, 4);// 1-2
    // graph.createEdge(2, 4, 4);// 1-3
    // graph.createEdge(3, 3, 4);// 3-3

    // // Floyd–Warshall
    graph.insertVertex(1, '1');
    graph.insertVertex(2, '2');
    graph.insertVertex(3, '3');
    graph.insertVertex(4, '4');
    graph.createEdge(2, 1, 4);  // 2 - 1 | 4
    graph.createEdge(1, 3, -2);  // 1 - 3 | -2
    graph.createEdge(2, 3, 3);  // 2 - 3 | 3
    graph.createEdge(4, 2, -1);  // 4 - 2 | -1
    graph.createEdge(3, 4, 2);  // 3 - 4 | 2

    // // display as adjacency list
    // /*
    //  E:  I(29), J(5), A(11)
    //  J:  A(14), F(4)
    // */
    // graph.display();

    // // True, False
    // cout << "\nfindById(6): " << std::boolalpha << graph.findById(6) << endl;

    // // display object
    // /*
    //  E:  I(29), J(5), A(11)
    // */
    // cout << "\ndisplayVertex(6)\n";
    // cout << graph.displayVertex(6) << endl;

    // cout << "isStronglyConnected(): " << std::boolalpha << graph.isStronglyConnected() << endl;

    // cout << "\nexecDFS()\n";
    // DFS<char, float> DFS(graph, '2');
    // Graph<char, float>* dsf = new DirectedGraph<char, float>();
    // dsf = DFS.apply();
    // dsf->display();
    // DFS.displayresult();

    // cout << "\nexecBFS()\n";
    // BFS<char, float> BFS(graph, '2');
    // Graph<char, float>* bfs = new DirectedGraph<char, float>();
    // bfs = BFS.apply();
    // bfs->display();
    // BFS.displayresult();

    // cout << "\nexecDijkstra()\n";
    // Dijkstra<char, float> Dijkstra(graph, '2');
    // // Graph<char, float> *dijs = new DirectedGraph<char, float>();
    // unordered_map<Vertex<char, float>*, float> rd = Dijkstra.apply();
    // Dijkstra.displayresult();

    // cout << "\nexecBellmanFord()\n";
    // BellmanFord<char, float> BellmanFord(graph, '2');
    // // Graph<char, float> *bf = new DirectedGraph<char, float>();
    // unordered_map<Vertex<char, float>*, float> rb = BellmanFord.apply();
    // BellmanFord.displayresult();

    // cout << "\nDelete Vertex id: 4 (3)\n";
    // graph.deleteVertex(4);
    // graph.display();

    // cout << "\nDelete Edge 0 - 2 \n";
    // graph.deleteEdge(1, 3);
    // graph.display();

    // cout << "\nDensity: \n";
    // cout << graph.density();

    // cout << "\nisDense(): " << std::boolalpha << graph.isDense() << endl;

    // cout << "\nempty(): " << std::boolalpha << graph.empty() << endl;

    // corregir
    cout << "\nexecFloydWarshall()\n";
    FloydWarshall<char, float> FloydWarshall(graph);
    Graph<char, float> *dsf = new DirectedGraph<char, float>();
    dsf = FloydWarshall.apply();
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
    // graph.insertVertex(1, "0");
    // graph.insertVertex(2, "1");
    // graph.insertVertex(3, "2");
    // graph.insertVertex(4, "3");
    // graph.insertVertex(5, "4");
    // graph.createEdge(1, 3, 6);  // 0 - 2 | 6
    // graph.createEdge(1, 2, 1);  // 0 - 1 | 1
    // graph.createEdge(3, 2, 4);  // 2 - 1 | 4
    // graph.createEdge(3, 4, 1);  // 2 - 3 | 1
    // graph.createEdge(2, 4, 3);  // 1 - 3 | 3
    // graph.createEdge(2, 5, 1);  // 1 - 4 | 1
    // graph.createEdge(4, 5, 1);  // 3 - 4 | 1

    // // A* test : https://www.101computing.net/a-star-search-algorithm/
    graph.insertVertex(1, "A");
    graph.insertVertex(2, "B");
    graph.insertVertex(3, "C");
    graph.insertVertex(4, "D");
    graph.insertVertex(5, "E");
    graph.insertVertex(6, "F");
    graph.insertVertex(7, "Z");
    graph.createEdge(1, 3, 3); //A-C
    graph.createEdge(1, 2, 4); //A-B
    graph.createEdge(2, 6, 5); //B-F
    graph.createEdge(2, 5, 12); //B-E
    graph.createEdge(3, 4, 7); //C-D
    graph.createEdge(3, 5, 10); //C-E
    graph.createEdge(4, 5, 2); //D-E
    graph.createEdge(5, 7, 5); //E-Z
    graph.createEdge(6, 7, 16); //F-Z

    // display as adjacency list
    /*
     4: 1(1), 3(1),
     3: 2(1), 1(3), 4(1),
     2: 0(6), 1(4), 3(1),
     1: 0(1), 2(4), 3(3), 4(1),
     0: 2(6), 1(1),
    */
    graph.display();

    // // True, False
    // cout << "\nfindById(3): " << std::boolalpha << graph.findById(3) << endl;

    // // display object
    // /*
    //  2: 0(6), 1(4), 3(1)
    // */
    // cout << "\ndisplayVertex(3)\n";
    // cout << graph.displayVertex(3) << endl;

    // cout << "\nexecKruskal()\n";
    // Kruskal<string, float> kruskal(graph);
    // UnDirectedGraph<string, float> mstk = kruskal.apply();
    // mstk.display();

    // cout << "\nexecPrim()\n";
    // Prim<string, float> Prim(graph, "0");
    // UnDirectedGraph<string, float> mstp = Prim.apply();
    // mstp.display();

    // cout << "\nexecDFS()\n";
    // DFS<string, float> DFS(graph, "0");
    // Graph<string, float>* dsf = new UnDirectedGraph<string, float>();
    // dsf = DFS.apply();
    // dsf->display();
    // DFS.displayresult();

    // cout << "\nexecBFS()\n";
    // BFS<string, float> BFS(graph, "0");
    // Graph<string, float>* bfs = new UnDirectedGraph<string, float>();
    // bfs = BFS.apply();
    // bfs->display();
    // BFS.displayresult();

    // cout << "\nexecDijkstra()\n";
    // Dijkstra<string, float> Dijkstra(graph, "0");
    // // Graph<string, float> *dijs = new UnDirectedGraph<string, float>();
    // unordered_map<Vertex<string, float>*, float> result = Dijkstra.apply();
    // Dijkstra.displayresult();

    cout << "\nexecAStar()\n";
    AStar<string, float> AStar(graph, "A", "Z");
    // Graph<char, float> *bf = new DirectedGraph<char, float>();
    unordered_map<Vertex<string, float>*, float> ra = AStar.apply();
    AStar.displayresult();

    // cout << "\nisConnected(): " << std::boolalpha << graph.isConnected() << endl;

    // cout << "\nDensity: \n";
    // cout << graph.density();

    // cout << "\nisDense(): " << std::boolalpha << graph.isDense() << endl;

    // cout << "\nDelete Vertex id: 5 (4)\n";
    // graph.deleteVertex(5);
    // graph.display();

    // cout << "\nDelete Edge 2 - 1 \n";
    // graph.deleteEdge(3, 2);
    // graph.display();

    // cout << "\nempty(): " << std::boolalpha << graph.empty() << endl;
}
