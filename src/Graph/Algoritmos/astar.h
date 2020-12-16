#ifndef ASTAR_H
#define ASTAR_H

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
class AStar {
   public:
    Graph<TV, TE>* Graph;
    ::Graph<TV, TE>* DGraph;
    Vertex<TV, TE>* v_init;
    Vertex<TV, TE>* v_dest;
    unordered_map<Vertex<TV, TE>*, TE> dist;

    AStar(::Graph<TV, TE>& Graph, TV init, TV dest) {  // tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->DGraph = new UnDirectedGraph<TV, TE>();
            cout << "Inicio: " << init << " ---> Destino: " << dest << endl;
            this->v_init = this->Graph->findByData(init);
            this->v_dest = this->Graph->findByData(dest);
            if (this->v_init == nullptr || this->v_dest == nullptr) {
                throw "Init or Dest not in a graph";
            }
        } else if (this->Graph->type == 1) {
            this->DGraph = new DirectedGraph<TV, TE>();
            cout << "Inicio: " << init << " ---> Destino: " << dest << endl;
            this->v_init = this->Graph->findByData(init);
            this->v_dest = this->Graph->findByData(dest);
            if (this->v_init == nullptr || this->v_dest == nullptr) {
                throw "Init or Dest not in a graph";
            }
        } else {
            cout << "Error" << endl;
        }
    };

    // ::Graph<TV, TE>* apply(){
    unordered_map<Vertex<TV, TE>*, TE> apply() {
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
        cout << "Incio: " << v_init->data << endl;
        
        pq.push(make_pair(0, v_init));
        dist[this->Graph->vertexes.begin()->second] = 0;

        // For test
        // cout << "Incio: " << this->Graph->vertexes.at(1) << endl;
        // pq.push(make_pair(0, this->Graph->vertexes.at(1)));
        // dist[this->Graph->vertexes.at(1)] = 0;

        while (!pq.empty()) {
            // sacas el vertex con menor distancia
            Vertex<TV, TE>* u = pq.top().second;
            pq.pop();

            // Para cada vértice adyacente de v
            for (auto edg : u->edges) {
                // obtiene el vertex adyacente y su peso del vertex actual
                Vertex<TV, TE>* v = edg->vertexes[1];
                TE weight = edg->weight;

                double heur = sqrt(pow((v_dest->lat - v->lat), 2.0) +
                                   pow((v_dest->lng - v->lng), 2.0));

                // si hay un camino más corto a v por u
                if (dist[v] > dist[u] + weight + heur) {
                    // Updating distance of v
                    // cout << "Update " << endl;
                    dist[v] = dist[u] + weight + heur;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }

    void displayresult() {
        // cout << "Result of AStar" << endl;
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
