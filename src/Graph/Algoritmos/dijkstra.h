#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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
class Dijkstra {
   public:
    Graph<TV, TE>* Graph;
    ::Graph<TV, TE>* DGraph;
    Vertex<TV, TE>* v_init;
    unordered_map<Vertex<TV, TE>*, TE> dist;

    Dijkstra(::Graph<TV, TE>& Graph, TV init) {  // tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->DGraph = new UnDirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else if (this->Graph->type == 1) {
            this->DGraph = new DirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else {
            cout << "Error" << endl;
        }
    };

    // ::Graph<TV, TE>* apply(){
    unordered_map<Vertex<TV, TE>*, TE> apply() {
        unordered_map<Vertex<TV, TE>*, bool> visited;

        // iPair ==>  distancia - vertex
        typedef pair<TE, Vertex<TV, TE>*> iPair;

        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

        // init distances as infinite (INF)
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            dist[itr->second] = INF;
            // Inserta el vértice con su ID al nuevo grafo
            DGraph->insertVertex(itr->first, itr->second->data);
        }

        // inserte el vertex inicial en la cola de prioridad y se inizia su distancia como 0
        cout << "Incio: " << this->v_init->data << endl;
        pq.push(make_pair(0, this->v_init));
        dist[this->v_init] = 0;

        /* print actual table */
        cout << "          ";
        for (auto e : dist) {
            cout << setw(10) << e.first->data << setw(10);
        }
        cout << endl; /* print actual table */

        while (!pq.empty()) {
            // sacas el vertex con menor distancia
            Vertex<TV, TE>* u = pq.top().second;

            pq.pop();

            // Para cada vértice adyacente de v
            for (auto edg : u->edges) {
                // obtiene el vertex adyacente y su peso del vertex actual
                Vertex<TV, TE>* v = edg->vertexes[1];
                TE weight = edg->weight;

                // si hay un camino más corto a v por u
                if (dist[v] > dist[u] + weight) {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));

                    /* Construyo el nuevo grafo resultante */
                    Vertex<TV, TE>* tp = DGraph->findByData(
                        edg->vertexes[1]->data);  // busco el nodo en el nuevo grafo
                    // si no esta vacio su lista de edges quiere decir que ya colocamos un camino
                    // sin embargo se encontró uno más corto hay que eliminarlo
                    if (!tp->edges.empty()) {
                        Edge<TV, TE>* tmp = tp->edges.back();
                        // se elimina el edge que existe
                        DGraph->deleteEdge(DGraph->findByVertex(tmp->vertexes[0]),
                                           DGraph->findByVertex(tmp->vertexes[1]));
                    }
                    DGraph->createEdge(this->Graph->findByVertex(edg->vertexes[0]),
                                       this->Graph->findByVertex(edg->vertexes[1]), weight);
                }
            }

            /* print actual table */
            if (!visited[u]) {
                cout << u->data << setw(10);
                for (auto e : dist) {
                    if (e.second == INF) {
                        cout << setw(10) << "INF" << setw(10);
                    } else {
                        cout << setw(10) << e.second << setw(10);
                    }
                }
                cout << endl;
            }
            visited[u] = true; /* print actual table */
        }

        cout << "\r";

        return dist;
    }

    void displayresult() {
        cout << "Result of Dijkstra" << endl;
        DGraph->display();
        cout << endl;

        cout << "Vertex   "
             << "Distance  " << endl;
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
