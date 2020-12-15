#ifndef DEPTHFS_H
#define DEPTHFS_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../undirectedGraph.h"
#include "../graph.h"

using namespace std;

template <typename TV, typename TE>
class DFS {
   public:
    // UnDirectedGraph<TV, TE> Graph;
    Graph<TV, TE> *Graph;
    ::Graph<TV, TE> *DFSGraph;
    DFS(::Graph<TV, TE> &Graph) {//Tambien funciona para grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->DFSGraph = new UnDirectedGraph<TV, TE>();
        } else if (this->Graph->type == 1) {
            this->DFSGraph = new DirectedGraph<TV, TE>();
        } else {
            cout << "Error" << endl;
        }
    };

    ::Graph<TV, TE>*apply(){
        // UnDirectedGraph<TV, TE> DFSGraph;
        unordered_map<Vertex<TV, TE>*, bool> visited;

        // Se coloca todos los vértices como no visitados
        for (auto x : this->Graph->vertexes) {
            visited[x.second] = false;
            // Inserta el vértice con su ID al nuevo grafo
            DFSGraph->insertVertex(x.first, x.second->data);
        }

        // Para cada vértice en el árbol
        // for (auto itr_new : this->Graph.vertexes) {
            // if (!visited[itr_new.second]) {
                stack<Vertex<TV, TE>*> stack;
                // Se coloca el vértice actual como visitado y se coloca en la pila
                 cout << "Incio: " << this->Graph->vertexes.begin()->second->data << endl;
                stack.push(this->Graph->vertexes.begin()->second);
                visited[this->Graph->vertexes.begin()->second] = true;
                

                while (!stack.empty()) {
                    // Se saca de la pila el vértice
                    Vertex<TV, TE>* v = stack.top();
                    stack.pop();
                    // if (!visited[v]) {
                    //     visited[v] = true;
                    // }
                    // Para cada vértice adyacente de v
                    //--> si no ha sido visitado se marca como visitado y se coloca en la pila
                    for (auto edg : v->edges) {
                        // visited[edg->vertexes[1]] << endl;
                        if (!visited[edg->vertexes[1]]) {
                            stack.push(edg->vertexes[1]);
                            visited[edg->vertexes[1]] = true;
                            // Se crea una nueva arista en el nuevo Grafo (Peso no importa)
                            DFSGraph->createEdge(this->Graph->findByVertex(edg->vertexes[0]),
                                                this->Graph->findByVertex(edg->vertexes[1]), 1);
                        }
                    }
                }
            // }
        // }
        return DFSGraph;
    }

};

#endif
