#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"
using namespace std;

template <typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE> {
   private:
    /* Función para realizar la comparación al momento de ordenar el array graphedges */
    static bool compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second) {
        return first->weight < second->weight;
    }

   public:
    bool insertVertex(int id, TV vertex) {
        // this->vertexes.insert(make_pair(id, vertex));
        Vertex<TV, TE>* v = new Vertex<TV, TE>();
        v->data = vertex;
        this->vertexes[id] = v;

        return true;
    };

    bool createEdge(int id1, int id2, TE w) {
        // Se obtienen los vertices de la lista vertexes
        Vertex<TV, TE>* v1 = this->vertexes.at(id1);
        Vertex<TV, TE>* v2 = this->vertexes.at(id2);

        // Se añade un nuevo edge al vertices con id1
        Edge<TV, TE>* e = new Edge<TV, TE>();
        e->weight = w;
        e->vertexes[0] = v1;
        e->vertexes[1] = v2;
        v1->edges.push_back(e);
        // v1->edges.sort(compare_nocase);

        // Se añade a la lista de aristas del grafo
        this->graphedges.push_front(e);

        // Se añade un nuevo edge al vertices con id2
        Edge<TV, TE>* e2 = new Edge<TV, TE>();
        e2->weight = w;
        e2->vertexes[0] = v2;
        e2->vertexes[1] = v1;
        v2->edges.push_back(e2);
        // v2->edges.sort(compare_nocase);
        return true;
    };

    /* Funcion para mostrar cada vértice del arbol con sus respectivas aristas */
    void display() {
        for (auto x : this->vertexes) {
            Vertex<TV, TE>* tmp = x.second;
            std::cout << tmp->data << ": ";
            for (auto ver : tmp->edges) {
                std::cout << ver->vertexes[1]->data << "(" << ver->weight << ")"
                          << ", ";
            }
            std::cout << std::endl;
        }
    };

    Vertex<TV, TE>* displayVertex(int id) {
        Vertex<TV, TE>* v = this->vertexes.at(id);
        return v;
    };

    /* Funcion para determinar si existe el vértice en el árbol por id */
    bool findById(int id) {
        if (this->vertexes.find(id) == this->vertexes.end())
            return false;
        else
            return true;
    };

    /* Funcion para determinar si existe el vértice en el árbol por el mismo vértice */
    int findByVertex(Vertex<TV, TE>* v) {
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->vertexes.begin(); itr != this->vertexes.end(); itr++) {
            if (itr->second == v) return itr->first;
        }
        return -1;
    }

    void clear() {}
    bool empty() { return true; }
    bool deleteVertex(int id) { return true; }
    bool deleteEdge(int id) { return true; }
    float density() { return 1.0; }
    bool isDense(float threshold = 0.5) { return true; }

    /* Función para hallar el Minimun Spanning Tree */
    UnDirectedGraph<TV, TE> execKruskal() {
        UnDirectedGraph<TV, TE> BFSGraph;  // MST Graph
        vector<char> data;                 // Vector para guardar vértices y crear DisjointSet

        // Se llena data y el MST Graph
        for (auto x : this->vertexes) {
            data.push_back(x.second->data);
            BFSGraph.insertVertex(x.first, x.second->data);
        }
        // Se ordena las aristas de menor a mayor
        this->graphedges.sort(compare_nocase);
        // Se crea un DisjointSet con los vértices del árbol
        DisjoinSet<char>* ds = new DisjoinSet<char>(data);
        ds->MakeSet();

        // Por cada arista en el árbol se aplica una union si es el caso
        for (auto edges_ : this->graphedges) {
            Edge<TV, TE>* next_edge = edges_;

            int x = ds->Find(findByVertex(next_edge->vertexes[0]));  // el mismo vertice
            int y = ds->Find(findByVertex(next_edge->vertexes[1]));  // el destino

            // Si tienen diferente parent se realiza la union
            if (x != y) {
                ds->Union(x, y);
                // Se agrega la solución al MST Graph
                BFSGraph.createEdge(findByVertex(next_edge->vertexes[0]),
                                    findByVertex(next_edge->vertexes[1]), next_edge->weight);
            }
        }
        // ds->printSets();
        // cout << endl;
        this->dsgraph = ds;
        return BFSGraph;
    };

    /* Función para realizar la busqueda en profundidad */
    UnDirectedGraph<TV, TE> execDFS() {
        UnDirectedGraph<TV, TE> BFSGraph;
        unordered_map<Vertex<TV, TE>*, bool> visited;

        // Se coloca todos los vértices como no visitados
        for (auto x : this->vertexes) {
            visited[x.second] = false;
            // Inserta el vértice con su ID al nuevo grafo
            BFSGraph.insertVertex(x.first, x.second->data);
        }

        // Para cada vértice en el árbol
        for (auto itr_new : this->vertexes) {
            if (!visited[itr_new.second]) {
                stack<Vertex<TV, TE>*> stack;
                // Se coloca el vértice actual como visitado y se coloca en la pila
                visited[itr_new.second] = true;
                stack.push(itr_new.second);

                while (!stack.empty()) {
                    // Se saca de la pila el vértice
                    Vertex<TV, TE>* v = stack.top();
                    stack.pop();
                    // Para cada vértice adyacente de v
                    //--> si no ha sido visitado se marca como visitado y se coloca en la pila
                    for (auto edg : v->edges) {
                        // visited[edg->vertexes[1]] << endl;
                        if (!visited[edg->vertexes[1]]) {
                            visited[edg->vertexes[1]] = true;
                            stack.push(edg->vertexes[1]);
                            // Se crea una nueva arista en el nuevo Grafo (Peso no importa)
                            BFSGraph.createEdge(findByVertex(edg->vertexes[0]),
                                                findByVertex(edg->vertexes[1]), 1);
                        }
                    }
                }
            }
        }
        return BFSGraph;
    };

    /* Función para realizar la busqueda en anchura */
    UnDirectedGraph<TV, TE> execBFS() {
        UnDirectedGraph<TV, TE> BFSGraph;
        unordered_map<Vertex<TV, TE>*, bool> visited;

        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->vertexes.begin(); itr != this->vertexes.end(); itr++) {
            // Se marca todos los vértices como no visitados
            visited[itr->second] = false;
            // Inserta el vértice con su ID al nuevo grafo
            BFSGraph.insertVertex(itr->first, itr->second->data);
        }

        // Para cada vértice en el árbol
        for (auto itr_new : this->vertexes) {
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
                            BFSGraph.createEdge(findByVertex(edg->vertexes[0]),
                                                findByVertex(edg->vertexes[1]), 1);
                        }
                    }
                }
            }
        }
        // cout << endl;
        return BFSGraph;
    };

    // saber si el grafo es conexo, se puede usar disjoin set (si existen 2 DS es no conexo)
    bool isConnected() {
        // vector<char> data; // Vector para guardar vértices y crear DisjointSet
        // // Se llena data y el MST Graph
        // for (auto x : this->vertexes){
        //     data.push_back(x.second->data);
        // }
        // // Se crea un DisjointSet con los vértices del árbol
        // DisjoinSet<char>* dsc = new DisjoinSet<char>(data);
        // dsc->MakeSet();

        // // Por cada arista en el árbol se aplica una union si es el caso
        // for (auto edge_ : this->graphedges){
        //     int x = dsc->Find(findByVertex(edge_->vertexes[0])); //el mismo vertice
        //     int y = dsc->Find(findByVertex(edge_->vertexes[1])); //el destino

        //     // Si tienen diferente parent se realiza la union
        //     if (x != y) {
        //         // Se agrega el vértice al DisjointSet
        //         dsc->Union(x, y);
        //     }
        // }
        // // ds->printSets();

        // Si el DisjointSet posee mas de 1 set quiere decir que el grafo es no conexo
        // Si ya se corrio Kruskal se puede obtener del mismo disjoint set
        int sets = this->dsgraph->sets();

        return sets <= 1;
    };
    bool isStronglyConnected() { return true; }
};

#endif