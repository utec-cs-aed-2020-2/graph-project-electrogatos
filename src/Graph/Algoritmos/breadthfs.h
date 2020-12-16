#ifndef BREADTHFS_H
#define BREADTHFS_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../graph.h"
#include "../undirectedGraph.h"

using namespace std;

template <typename TV, typename TE>
class BFS {
   public:
    Graph<TV, TE>* Graph;
    ::Graph<TV, TE>* BFSGraph;
    Vertex<TV, TE>* v_init;
    list<TV> rutaBFS;

    BFS(::Graph<TV, TE>& Graph, TV init) {  // tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->BFSGraph = new UnDirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else if (this->Graph->type == 1) {
            this->BFSGraph = new DirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else {
            cout << "Error" << endl;
        }
    };

    ::Graph<TV, TE>* apply() {
        unordered_map<Vertex<TV, TE>*, bool> visited;

        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->Graph->vertexes.begin(); itr != this->Graph->vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            visited[itr->second] = false;
            // Inserta el vértice con su ID al nuevo grafo
            BFSGraph->insertVertex(itr->first, itr->second->data);
        }

        // Create a queue of Vertex
        queue<Vertex<TV, TE>*> queue;

        // Se coloca el vértice actual como visitado y se encola
        cout << "Incio: " << this->v_init->data << endl;
        visited[this->v_init] = true;
        queue.push(this->v_init);

        while (!queue.empty()) {
            Vertex<TV, TE>* v = queue.front();
            // cout << " Nodo pop queque: " << v->data << endl;
            this->rutaBFS.push_back(v->data);
            queue.pop();

            // Para cada vértice adyacente de v
            //--> si no ha sido visitado se marca como visitado y encola
            for (auto edg : v->edges) {
                if (!visited[edg->vertexes[1]]) {
                    // cout << "  Nodo push queque: " << edg->vertexes[1]->data << endl;
                    visited[edg->vertexes[1]] = true;
                    queue.push(edg->vertexes[1]);
                    // Se crea una nueva arista en el nuevo Grafo (Peso no importa)
                    BFSGraph->createEdge(this->Graph->findByVertex(edg->vertexes[0]),
                                         this->Graph->findByVertex(edg->vertexes[1]), 1);
                }
            }
        }
        return BFSGraph;
    }

    void displayresult() {
        cout << "Recorrido BFS: " << endl;
        for (auto e : rutaBFS) {
            cout << " " << e << " ->";
        }
        cout << endl;
    }
};

#endif
