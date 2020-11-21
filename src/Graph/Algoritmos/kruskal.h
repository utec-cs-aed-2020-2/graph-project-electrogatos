#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../Algoritmos/kruskal.h"
#include "../undirectedGraph.h"
#include "../../DisjointSet/disjointSet.h"
#include "../graph.h"

using namespace std;

template <typename TV, typename TE>
class Kruskal {
   public:
    DisjoinSet<TV>* dsgraph;
    UnDirectedGraph<TV, TE> Graph;
    Kruskal(UnDirectedGraph<TV, TE> &Graph) {
        this->Graph = Graph;
        // Graph.total_sets = 2;
    };
    
    /* Función para realizar la comparación al momento de ordenar el array graphedges */
    static bool compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second) {
        return first->weight < second->weight;
    }

    UnDirectedGraph<TV, TE> apply(){
        UnDirectedGraph<TV, TE> BFSGraph;  // MST Graph
        vector<TV> data;                 // Vector para guardar vértices y crear DisjointSet

        // Se llena data y el MST Graph
        for (auto x : this->Graph.vertexes) {
            data.push_back(x.second->data);
            BFSGraph.insertVertex(x.first, x.second->data);
        }
        // Se ordena las aristas de menor a mayor
        this->Graph.graphedges.sort(compare_nocase);
        // Se crea un DisjointSet con los vértices del árbol
        DisjoinSet<TV>* ds = new DisjoinSet<TV>(data);
        ds->MakeSet();

        // Por cada arista en el árbol se aplica una union si es el caso
        for (auto edges_ : this->Graph.graphedges) {
            // cout << edges_->vertexes[0]->data << " -> " << edges_->vertexes[1]->data << endl;
            Edge<TV, TE>* next_edge = edges_;

            int x = ds->Find(this->Graph.findByVertex(next_edge->vertexes[0]) - 1);  // el mismo vertice
            // cout << "ID: " << this->Graph.findByVertex(next_edge->vertexes[1]) << endl;
            int y = ds->Find(this->Graph.findByVertex(next_edge->vertexes[1]) - 1);  // el destino
            // cout << "Index x: " << x << " Index y: " << y << endl;

            // Si tienen diferente parent se realiza la union
            if (x != y) {
                ds->Union(x, y);
                // Se agrega la solución al MST Graph
                BFSGraph.createEdge(this->Graph.findByVertex(next_edge->vertexes[0]),
                                    this->Graph.findByVertex(next_edge->vertexes[1]), next_edge->weight);
            }
        }
        // ds->printSets();
        // cout << "Total Sets: " << ds->sets() << endl;
        // cout << endl;

        Graph.total_sets = ds->sets();

        return BFSGraph;
    }
};

#endif