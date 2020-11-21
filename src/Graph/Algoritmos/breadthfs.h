#ifndef BREADTHFS_H
#define BREADTHFS_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../undirectedGraph.h"
#include "../graph.h"

using namespace std;

template <typename TV, typename TE>
class BFS {
   public:
    UnDirectedGraph<TV, TE> Graph;
    BFS(UnDirectedGraph<TV, TE> &Graph) {
        this->Graph = Graph;
    };

    UnDirectedGraph<TV, TE> apply(){
        UnDirectedGraph<TV, TE> BFSGraph;
        unordered_map<Vertex<TV, TE>*, bool> visited;

        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->Graph.vertexes.begin(); itr != this->Graph.vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            visited[itr->second] = false;
            // Inserta el vértice con su ID al nuevo grafo
            BFSGraph.insertVertex(itr->first, itr->second->data);
        }

        // Para cada vértice en el árbol
        for (auto itr_new : this->Graph.vertexes) {
            if (!visited[itr_new.second]) {
                // Create a queue of Vertex
                queue<Vertex<TV, TE>*> queue;
                // Se coloca el vértice actual como visitado y se encola
                visited[itr_new.second] = true;
                queue.push(itr_new.second);

                while (!queue.empty()) {
                    Vertex<TV, TE>* v = queue.front();
                    queue.pop();

                    // Para cada vértice adyacente de v
                    //--> si no ha sido visitado se marca como visitado y encola
                    for (auto edg : v->edges) {
                        if (!visited[edg->vertexes[1]]) {
                            visited[edg->vertexes[1]] = true;
                            queue.push(edg->vertexes[1]);
                            // Se crea una nueva arista en el nuevo Grafo (Peso no importa)
                            BFSGraph.createEdge(this->Graph.findByVertex(edg->vertexes[0]),
                                                this->Graph.findByVertex(edg->vertexes[1]), 1);
                        }
                    }
                }
            }
        }
        // cout << endl;
        return BFSGraph;
    }

};

#endif