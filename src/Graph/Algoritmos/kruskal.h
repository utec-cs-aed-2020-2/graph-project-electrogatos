#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../../DisjointSet/disjointSet.h"
#include "../Algoritmos/kruskal.h"
#include "../graph.h"
#include "../undirectedGraph.h"

using namespace std;

template <typename TV, typename TE>
class Kruskal {
   public:
    DisjoinSet<TV>* dsgraph;
    UnDirectedGraph<TV, TE> Graph;
    Kruskal(UnDirectedGraph<TV, TE>& Graph) {
        this->Graph = Graph;

        UnDirectedGraph<TV, TE> BFSGraph = apply();
        Graph.total_sets = this->Graph.total_sets;
    };

    /* Función para realizar la comparación al momento de ordenar el array graphedges */
   protected:
    static bool compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second) {
        return first->weight < second->weight;
    }

   public:
    UnDirectedGraph<TV, TE> apply() {
        UnDirectedGraph<TV, TE> BFSGraph;  // MST Graph
        vector<TV> data;                   // Vector para guardar vértices y crear DisjointSet
        unordered_map<TV, int> vtx;        // Para acomodar los indices

        // Se llena data y el MST Graph
        int index = 0;
        for (auto x : this->Graph.vertexes) {
            data.push_back(x.second->data);
            BFSGraph.insertVertex(x.first, x.second->data);
            // cout << "Index: " << x.second->data << endl;
            vtx[x.second->data] = index;
            index++;
        }

        // Se ordena las aristas de menor a mayor segun su peso
        this->Graph.graphedges.sort(compare_nocase);

        // Se crea un DisjointSet con los vértices del árbol
        DisjoinSet<TV>* ds = new DisjoinSet<TV>(data);
        ds->MakeSet();

        // Por cada arista en el árbol se aplica una union si es el caso
        for (auto edges_ : this->Graph.graphedges) {
            Edge<TV, TE>* next_edge = edges_;
            int x = ds->Find(vtx[next_edge->vertexes[0]->data]);  // el mismo vertice
            int y = ds->Find(vtx[next_edge->vertexes[1]->data]);  // el destino

            // Si tienen diferente parent se realiza la union
            if (x != y) {
                ds->Union(x, y);
                // Se agrega la solución al MST Graph
                BFSGraph.createEdge(this->Graph.findByVertex(next_edge->vertexes[0]),
                                    this->Graph.findByVertex(next_edge->vertexes[1]),
                                    next_edge->weight);
            }
        }

        this->Graph.total_sets = ds->sets();

        return BFSGraph;
    }
};

#endif