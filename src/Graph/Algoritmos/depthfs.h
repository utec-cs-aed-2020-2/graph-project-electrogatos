#ifndef DEPTHFS_H
#define DEPTHFS_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../graph.h"
#include "../undirectedGraph.h"

using namespace std;

template <typename TV, typename TE>
class DFS {
   public:
    Graph<TV, TE>* Graph;
    ::Graph<TV, TE>* DFSGraph;
    Vertex<TV, TE>* v_init;
    list<TV> RecorridoDFS;

    DFS(::Graph<TV, TE>& Graph, TV init) {
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->DFSGraph = new UnDirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else if (this->Graph->type == 1) {
            this->DFSGraph = new DirectedGraph<TV, TE>();
            this->v_init = this->Graph->findByData(init);
        } else {
            cout << "Error" << endl;
        }
    };

    ::Graph<TV, TE>* apply() {
        // UnDirectedGraph<TV, TE> DFSGraph;
        unordered_map<Vertex<TV, TE>*, bool> visited;

        // Se coloca todos los vértices como no visitados
        for (auto x : this->Graph->vertexes) {
            visited[x.second] = false;
            // Inserta el vértice con su ID al nuevo grafo
            DFSGraph->insertVertex(x.first, x.second->data);
        }

        // Para cada vértice en el árbol
        stack<Vertex<TV, TE>*> stack;

        // Se coloca el vértice actual como visitado y se coloca en la pila
        cout << "Incio: " << this->v_init->data << endl;
        visited[this->v_init] = true;
        stack.push(this->v_init);

        while (!stack.empty()) {
            // Se saca de la pila el vértice
            Vertex<TV, TE>* v = stack.top();
            cout << " Nodo pop stack: " << v->data << endl;
            this->RecorridoDFS.push_back(v->data);
            stack.pop();

            // Para cada vértice adyacente de v
            //--> si no ha sido visitado se marca como visitado y se coloca en la pila
            for (auto edg : v->edges) {
                if (!visited[edg->vertexes[1]]) {
                    cout << "  Nodo push stack: " << edg->vertexes[1]->data << endl;
                    visited[edg->vertexes[1]] = true;
                    stack.push(edg->vertexes[1]);
                    // Se crea una nueva arista en el nuevo Grafo (Peso no importa)
                    DFSGraph->createEdge(this->Graph->findByVertex(edg->vertexes[0]),
                                         this->Graph->findByVertex(edg->vertexes[1]), 1);
                }
            }
        }
        return DFSGraph;
    }

    void displayresult() {
        cout << "Recorrido DFS: " << endl;
        for (auto e : RecorridoDFS) {
            cout << " " << e << " ->";
        }
        cout << endl;
    }
};

#endif
