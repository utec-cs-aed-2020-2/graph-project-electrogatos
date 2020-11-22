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
    virtual bool insertVertex(int id, TV vertex) = 0;
    virtual bool createEdge(int id1, int id2, TE w) = 0;
    virtual bool deleteVertex(int id) = 0;
    virtual bool deleteEdge(int start, int end) = 0;
    // TE& operator()(string start, string end);
    virtual float density() = 0;
    virtual bool isDense(float threshold = 0.5) = 0;
    virtual bool isConnected() = 0;
    virtual bool isStronglyConnected() = 0;
    virtual bool empty() = 0;
    virtual void clear() = 0;

    virtual Vertex<TV, TE>* displayVertex(int id) = 0;
    virtual bool findById(int id) = 0;
    virtual void display() = 0;
};

#endif