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
    unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> parent;

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
        unordered_map<Vertex<TV, TE>*, bool> visited;

        // iPair ==>  distancia - vertex
        typedef pair<TE, Vertex<TV, TE>*> iPair;
        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

        // init distances as infinite (INF)
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            dist[itr->second] = INF;
            parent[itr->second] = itr->second;
            // Inserta el vértice con su ID al nuevo grafo
            DGraph->insertVertex(itr->first, itr->second->data);
        }

        // inserta el vertex inicial en la cola de prioridad y se inizia su distancia como 0
        pq.push(make_pair(0, v_init));
        dist[v_init] = 0;

        while (!pq.empty()) {
            // sacas el vertex con menor distancia
            Vertex<TV, TE>* u = pq.top().second;
            pq.pop();

            // Para cada vértice adyacente de v
            for (auto edg : u->edges) {
                // obtiene el vertex adyacente y su peso del vertex actual
                Vertex<TV, TE>* v = edg->vertexes[1];
                TE weight = edg->weight;

                double heur = calculateDistance(v_dest->lat, v->lat, v_dest->lng, v->lng);

                // si hay un camino más corto a v por u
                if (dist[v] > dist[u] + weight + heur) {
                    // Updating distance of v
                    dist[v] = dist[u] + weight + heur;
                    pq.push(make_pair(dist[v], v));
                    parent[v] = u;
                }
            }
        }
        cout << "\r";

        // displayParents();
        displayPath();
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

    void displayparents() {
        /* print parents */
        cout << "Vertex  "
             << "Parent  " << endl;
        for (auto p : parent) {
            cout << setw(3) << p.first->data << setw(10) << p.second->data << endl;
        }
    }

    void displayPath() {
        cout << "Path: ";
        cout << setw(3) << this->v_dest->data << setw(3);
        Vertex<TV, TE>* tmp = parent.at(this->v_dest);
        for (auto p : parent) {
            cout << setw(3) << " <- " << tmp->data << setw(3);
            tmp = parent.at(tmp);
            if (tmp == this->v_init) break;
        }
        cout << setw(3) << " <- " << this->v_init->data << endl;
    }

   private:
    typedef enum { EUCLIDEAN, MANHATTAN, CHEBYSHEV } Heuristic;
    double calculateDistance(double x1, double x2, double y1, double y2,
                             Heuristic heuristic = EUCLIDEAN) {
        double distance;

        switch (heuristic) {
            case EUCLIDEAN:
                distance = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
                break;
            case MANHATTAN:
                distance = abs(x2 - x1) + abs(y2 - y1);
                break;
            case CHEBYSHEV:
                distance = max(abs(x2 - x1), abs(y2 - y1));
                break;
            default:
                break;
        }
        return distance;
    }
};

#endif
