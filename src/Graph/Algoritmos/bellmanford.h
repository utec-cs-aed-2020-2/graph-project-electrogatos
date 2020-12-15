#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include <iomanip>

#include "../undirectedGraph.h"
#include "../graph.h"

using namespace std;

template <typename TV, typename TE>
class BellmanFord {
   public:
    Graph<TV, TE> *Graph;
    ::Graph<TV, TE> *BFGraph;
    unordered_map<Vertex<TV, TE>*, TE> dist;
    

    BellmanFord(::Graph<TV, TE> &Graph) {//tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->BFGraph = new UnDirectedGraph<TV, TE>();
        } else if (this->Graph->type == 1) {
            this->BFGraph = new DirectedGraph<TV, TE>();
        } else {
            cout << "Error" << endl;
        }
    };

    // ::Graph<TV, TE>* apply(){
    unordered_map<Vertex<TV, TE>*, TE> apply(){
        int s = this->Graph->vertexes.size();
        
        // init distances as infinite (INF)
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            dist[itr->second] = INF;
            // Inserta el vértice con su ID al nuevo grafo
            BFGraph->insertVertex(itr->first, itr->second->data);
        }
        
        Vertex<TV, TE>* init = this->Graph->vertexes.at(1);
        cout << "Incio: " << init->data << endl;
        dist[init] = 0;

        // busca el camino más corto por cada edge en cada vertex
        for (int i = 1; i <= s - 1; i++) { 
            for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
                for (auto edg : itr->second->edges) { 
                // for (auto edg : init->edges) { 
                    Vertex<TV, TE>* u = edg->vertexes[0]; // src
                    Vertex<TV, TE>* v = edg->vertexes[1]; // dest
                    TE weight = edg->weight; 
                    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight; 
                    }
                }
            }
        }

        // Verificar ciclos negativos
        for (auto edg : init->edges) { 
            Vertex<TV, TE>* u = edg->vertexes[0]; 
            Vertex<TV, TE>* v = edg->vertexes[1]; 
            TE weight = edg->weight; 
            if (dist[u] != INF && dist[u] + weight < dist[v]) { 
                cout << "Gráfico contiene un ciclo negativo" << endl; 
                return dist; // If negative cycle is detected, simply return 
            } 
        }
        
        return dist;
    }

    void displayresult(){
        cout << "Vertex   " << "Distance  " << endl;
        for (auto e : dist) {
            // cout << "Vertex: " << e.first->data << " Dist: " << e.second << endl;
            if (e.second == INF) {
                cout << setw(3) << e.first->data << setw(10) << "-" << endl;
            } else {
                cout << setw(3) << e.first->data << setw(10) << e.second << endl;
            }   
        }
    }

};

#endif
