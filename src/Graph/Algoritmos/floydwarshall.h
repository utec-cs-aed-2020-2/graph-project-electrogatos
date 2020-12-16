#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <iomanip>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../graph.h"
#include "../undirectedGraph.h"

using namespace std;

#define MATRIX_INIT_ZERO 0
#define MATRIX_INIT_INF  9999

template <typename TV, typename TE>
class FloydWarshall {
   private:
    TE** weights;
    TE** routes;
    int s;

   public:
    Graph<TV, TE>* Graph;
    ::Graph<TV, TE>* DGraph;

    FloydWarshall(::Graph<TV, TE>& Graph) {  // tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->DGraph = new UnDirectedGraph<TV, TE>();
        } else if (this->Graph->type == 1) {
            this->DGraph = new DirectedGraph<TV, TE>();
        } else {
            cout << "Error" << endl;
        }
        this->s = this->Graph->vertexes.size();
        cout << "Size: " << s << endl;

        this->weights = initializeWeightsMatrix(s);
        this->routes = initializeRoutesMatrix(s);
    };

    ::Graph<TV, TE>* apply() {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                for (int k = 0; k < s; k++) {
                    if (weights[j][i] == MATRIX_INIT_INF || weights[i][k] == MATRIX_INIT_INF) {
                        continue;
                    }

                    if (weights[j][i] + weights[i][k] < weights[j][k]) {
                        weights[j][k] = weights[j][i] + weights[i][j];
                        routes[j][k] = i;
                    }
                }
            }
        }

        return DGraph;
    }

    void displayresult() {
        cout << "\n Pesos: \n";
        printMatrix(weights, s);
        cout << "\n Rutas: \n";
        printMatrix(routes, s);
    }

    ~FloydWarshall() {
        destroyMatrix(weights, s);
        destroyMatrix(routes, s);
    }

   private:
    TE** initializeMatrix(int size) {
        TE** matrix;
        matrix = new TE*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new TE[size];
        }

        return matrix;
    }

    TE** initializeRoutesMatrix(int size) {
        TE** matrix = initializeMatrix(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    matrix[i][j] = MATRIX_INIT_ZERO;
                } else {
                    matrix[i][j] = j;
                }
            }
        }
        return matrix;
    }

    TE** initializeWeightsMatrix(int size) {
        TE** matrix = initializeMatrix(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    matrix[i][j] = MATRIX_INIT_ZERO;
                } else {
                    TE w = this->Graph->getweigthEdge(i + 1, j + 1);

                    matrix[i][j] = (w != -1) ? w : MATRIX_INIT_INF;
                }
            }
        }
        return matrix;
    }

    void printMatrix(TE** matrix, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == MATRIX_INIT_INF)
                    cout << "INF";
                else
                    cout << matrix[i][j];
                cout << "\t";
            }
            cout << endl;
        }
    }

    void destroyMatrix(TE** matrix, int size) {
        for (int i = 0; i < size; i++) {
            delete[] matrix[i];  // deletes an inner array of integer;
        }
        delete[] matrix;  // delete pointer holding array of pointers;
    }
};

#endif
