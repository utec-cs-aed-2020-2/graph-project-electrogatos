#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <string>

#include "edge.h"

using namespace std;

template <typename TV, typename TE>
class Edge;

template <typename TV, typename TE>
struct Vertex {
    TV data;
    list<Edge<TV, TE>*> edges;

    friend ostream& operator<<(ostream& o, const Vertex<TV, TE>* objeto) {
        o << objeto->data << ": ";
        for (auto ver : objeto->edges) {
            o << ver->vertexes[1]->data << "(" << ver->weight << ")"
              << ", ";
        }
        return o;
    }
};

#endif  // VERTEX_H