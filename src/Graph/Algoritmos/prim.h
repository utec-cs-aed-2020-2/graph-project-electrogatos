#ifndef PRIM_H
#define PRIM_H

#include <climits>
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
class Prim {
   protected:
    UnDirectedGraph<TV, TE> Graph;
    TV init;
    Vertex<TV, TE>* initvertex;
    UnDirectedGraph<TV, TE> BFSGraph;  // MST Graph

   public:
    Prim(UnDirectedGraph<TV, TE>& Graph, TV init) {
        this->Graph = Graph;
        this->init = init;
        this->initvertex = this->Graph.findByData(this->init);
    };

   protected:
    /* Función para realizar la comparación al momento de ordenar el array graphedges */
    static bool compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second) {
        return first->weight < second->weight;
    }

    /* Function to print the Tree */
    void printMST(unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> par) {
        cout << "Edge \tWeight\n";
        for (auto e : par) {
            cout << e.first->data << " - "
                 << " \t" << e.second->data << " \n";
        }
    }

    /* Function to fill the MSTGraph */
    void fillMST(unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> par) {
        for (auto e : par) {
            int id1 = this->Graph.findByVertex(e.first);
            int id2 = this->Graph.findByVertex(e.second);
            TE w = this->Graph.getweigthEdge(id1, id2);
            this->BFSGraph.createEdge(id1, id2, w);
        }
    }

    /* Function to get the min weight of specific key */
    Vertex<TV, TE>* minKey(unordered_map<Vertex<TV, TE>*, TE> key,
                           unordered_map<Vertex<TV, TE>*, bool> mstSet) {
        // Initialize min value
        TE min = 10000000.0;
        Vertex<TV, TE>* min_index;

        for (auto x : key) {
            Vertex<TV, TE>* v = x.first;
            if (mstSet[v] == false && key[v] < min) {
                min = key[v], min_index = v;
            }
        }
        return min_index;
    }

   public:
    UnDirectedGraph<TV, TE> apply() {
        // Se obtiene el vertice con minimo peso de todos
        // Si no existe un nodo de comienzo
        this->Graph.graphedges.sort(compare_nocase);
        Edge<TV, TE>* minor = this->Graph.graphedges.front();

        // Guarda el MST (vertex <-> vertex)
        unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> parent;

        // Se usa para obtener el minimo valor de peso por cada vertice
        unordered_map<Vertex<TV, TE>*, TE> key;

        // Para ver si los vertices ya han sido visitados o no
        unordered_map<Vertex<TV, TE>*, bool> mstSet;
        // Se coloca todos los vértices como no visitados y el peso como un valor máximo
        for (auto x : this->Graph.vertexes) {
            mstSet[x.second] = false;
            key[x.second] = INT_MAX;
            // Inserta el vértice con su ID al nuevo grafo
            this->BFSGraph.insertVertex(x.first, x.second->data);
        }

        // El vertice por donde se comienza
        // Vertex<TV, TE>* tmp = this->Graph.vertexes.at(1);
        // cout << tmp->data << endl;
        // cout << "Vertex init: " << this->initvertex->data << endl;
        key[this->initvertex] = 0;
        // parent[minor->vertexes[0]] = minor->vertexes[0]; // No es necesario

        // Para cada vertice
        for (auto itr_new : this->Graph.vertexes) {
            // Se obtiene el minino peso de los adyacentes al vertice actual
            Vertex<TV, TE>* u = minKey(key, mstSet);

            // Se coloca como visitado
            mstSet[u] = true;

            // Se actualiza el valor de key(peso) y el parent(MST)
            // Solo se actualiza los que no han sido visitados aun
            for (auto e : u->edges) {
                // cout << " Vecino: " << e->vertexes[1] << endl;
                Vertex<TV, TE>* v = e->vertexes[1];

                if (mstSet[v] == false && e->weight < key[v]) {
                    parent[v] = u, key[v] = e->weight;
                }
            }
        }

        // printMST(parent);
        fillMST(parent);

        return this->BFSGraph;
    }
};

#endif