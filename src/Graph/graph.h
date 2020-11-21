#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../DisjointSet/disjointSet.h"
#include "edge.h"
#include "vertex.h"

using namespace std;

template <typename TV, typename TE>
class Graph {
   public:
    unordered_map<int, Vertex<TV, TE>*> vertexes;
    list<Edge<TV, TE>*> graphedges;
    // DisjoinSet<string>* dsgraph;
    int total_sets = -1;

   public: // need to be virtual??? 
    bool insertVertex(int id, TV vertex);
    bool createEdge(int id1, int id2, TE w);
    bool deleteVertex(int id);
    bool deleteEdge(int id);
    // TE& operator()(string start, string end);
    float density();
    bool isDense(float threshold = 0.5);
    bool isConnected();
    bool isStronglyConnected();
    bool empty();
    void clear();

    Vertex<TV, TE>* displayVertex(int id);
    bool findById(int id);
    void display();
};

#endif