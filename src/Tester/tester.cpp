#include "tester.h"

void Tester::executeExamples() {
    UnDirectedGraph<char, float> graph;
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

    cout << "\nexecKruskal()\n";
    UnDirectedGraph<char, float> mst = graph.execKruskal();
    mst.display();

    cout << "\nexecDFS()\n";
    UnDirectedGraph<char, float> dsf = graph.execDFS();
    dsf.display();

    cout << "\nexecBFS()\n";
    UnDirectedGraph<char, float> bfs = graph.execBFS();
    bfs.display();

    cout << "isConnected(): " << std::boolalpha << graph.isConnected() << endl;

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
    // UnDirectedGraph<char, float> graph;
    City lima;
    UnDirectedGraph<City, double> cities;
    cities.insertVertex(lima.id, lima);
    cities.findById(lima.id);

    ifstream i("/Users/jamesatachagua/Desktop/Ciclo9/Algoritmos/vscode/proyecto/graph-project-electrogatos/src/Parser/Data/pe.json");
    // ifstream i("../Parser/Data/pe.json");
    json j;
    i >> j;

    Airport jorgechaves, a2;
    UnDirectedGraph<Airport, double> airports;

    // se necesita cambiar ID de string a int (python3)
    // latitud y longitud lo mismo
    for (int i = 0; i < 3; i++) {
        Airport a1;
        a1.id = j[i]["Airport ID"];
        cout << a1.id << endl;
        airports.insertVertex(a1.id, a1);
    }
    jorgechaves.id = j[0]["Airport ID"];
    a2.id = j[1]["Airport ID"];
    cout << jorgechaves.id << endl;
    cout << a2.id << endl;
    airports.insertVertex(jorgechaves.id, jorgechaves);
    airports.insertVertex(a2.id, a2);
    airports.createEdge(jorgechaves.id, a2.id, 250);
    // airports.display(); // falta sobrecargar el operador << para Airport y City
}

void Tester::testDeleteVertex() {}
void Tester::testDeleteEdge() {}
void Tester::testDensity() {}
void Tester::testConnected() {}
void Tester::testStronglyConnected() {}
void Tester::testKruskal() {}
void Tester::testPrim() {}