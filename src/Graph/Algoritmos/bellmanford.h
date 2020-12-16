#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <iomanip>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../graph.h"
#include "../undirectedGraph.h"

using namespace std;

template <typename TV, typename TE>
class BellmanFord {
   public:
    Graph<TV, TE>* Graph;
    ::Graph<TV, TE>* BFGraph;
    Vertex<TV, TE>* v_init;
    unordered_map<Vertex<TV, TE>*, TE> dist;

    BellmanFord(::Graph<TV, TE>& Graph, TV init) {  // tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->BFGraph = new UnDirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else if (this->Graph->type == 1) {
            this->BFGraph = new DirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else {
            cout << "Error" << endl;
        }
    };

    // ::Graph<TV, TE>* apply(){
    unordered_map<Vertex<TV, TE>*, TE> apply() {
        int s = this->Graph->vertexes.size();

        // init distances as infinite (INF)
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            dist[itr->second] = INF;
            // Inserta el vértice con su ID al nuevo grafo
            BFGraph->insertVertex(itr->first, itr->second->data);
        }

        cout << "Incio: " << this->v_init->data << endl;
        dist[this->v_init] = 0;

        // busca el camino más corto por cada edge en cada vertex
        for (int i = 1; i <= s - 1; i++) {
            for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
                for (auto edg : itr->second->edges) {
                    Vertex<TV, TE>* u = edg->vertexes[0];  // src
                    Vertex<TV, TE>* v = edg->vertexes[1];  // dest
                    TE weight = edg->weight;
                    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Verificar ciclos negativos
        for (auto edg : this->v_init->edges) {
            Vertex<TV, TE>* u = edg->vertexes[0];
            Vertex<TV, TE>* v = edg->vertexes[1];
            TE weight = edg->weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Gráfico contiene un ciclo negativo" << endl;
                return dist;  // If negative cycle is detected, simply return
            }
        }

        return dist;
    }

    void displayresult() {
        cout << "Vertex   "
             << "Distance  " << endl;
        for (auto e : dist) {
            if (e.second == INF) {
                cout << setw(3) << e.first->data << setw(10) << "-" << endl;
            } else {
                cout << setw(3) << e.first->data << setw(10) << e.second << endl;
            }
        }
    }
};

#endif
