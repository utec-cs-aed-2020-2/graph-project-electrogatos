#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include <iomanip>

#include "../undirectedGraph.h"
#include "../graph.h"

using namespace std;

template <typename TV, typename TE>
class FloydWarshall {
   public:
    Graph<TV, TE> *Graph;
    ::Graph<TV, TE> *DGraph;
    

    FloydWarshall(::Graph<TV, TE> &Graph) {//tambien sobre grafo dirigido
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->DGraph = new UnDirectedGraph<TV, TE>();
        } else if (this->Graph->type == 1) {
            this->DGraph = new DirectedGraph<TV, TE>();
        } else {
            cout << "Error" << endl;
        }
    };

    ::Graph<TV, TE>* apply(){
        int s = this->Graph->vertexes.size();
        cout << "Size: " << s << endl;
        TE dist[s][s];

        // INIT matriz
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                    cout << i << " " << j << " " << 0 << endl;
                } else {
                    TE w = this->Graph->getweigthEdge(i + 1, j + 1);
                    cout << i << " " << j << " " << w << endl;
                    // TE w = -1;
                    if (w != -1) {
                        dist[i][j] = w; 
                    } else {
                        dist[i][j] = 9999;
                    }
                }
            }
        } 

        // corregir
        // for (int k = 0; k < s; k++)  
        // {  
        //     // Pick all vertices as source one by one  
        //     for (int i = 0; i < s; i++)  
        //     {  
        //         // Pick all vertices as destination for the  
        //         // above picked source  
        //         for (int j = 0; j < s; j++)  
        //         {  
        //             // If vertex k is on the shortest path from  
        //             // i to j, then update the value of dist[i][j]  
        //             if (dist[i][k] + dist[k][j] < dist[i][j])  
        //                 dist[i][j] = dist[i][k] + dist[k][j];  
        //         }  
        //     }  
        // }
            
        // print
        for (int i = 0; i < s; i++)  
        {  
            for (int j = 0; j < s; j++)  
            {  
                if (dist[i][j] == 9999)  
                    cout<<"-"<<"     ";  
                else
                    cout<<dist[i][j]<<"     ";  
            }  
            cout<<endl;  
        }  
        
        return DGraph;
    }

    void displayresult(){
        
    }

};

#endif
