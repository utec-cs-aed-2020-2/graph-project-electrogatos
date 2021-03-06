#ifndef DSARRAY_H
#define DSARRAY_H

#include <iomanip>
#include <ios>
#include <map>
#include <vector>
using namespace std;

template <typename T>
class DisjoinSet {
   private:
    int* rank;
    int* parent;
    int n;
    T* dat;
    int succUnions;

   public:
    DisjoinSet(vector<T> data) {
        this->n = data.size();
        this->succUnions = 0;
        this->rank = new int[this->n];
        this->parent = new int[this->n];
        this->dat = new T[this->n];
        for (int i = 0; i < this->n; i++) {
            this->dat[i] = data[i];
        }
    }

    ~DisjoinSet() {
        delete[] dat;
        delete[] parent;
        delete[] rank;
    }

    void MakeSet(int x) {
        this->parent[x] = x;
        this->rank[x] = 0;
    }

    void MakeSet() {
        for (int i = 0; i < n; i++) {
            this->parent[i] = i;
            this->rank[i] = 0;
        }
    }

    int Find(int x) {  // O(Log(n))
        if (x == this->parent[x]) {
            return x;
        }
        return Find(this->parent[x]);
    }

    void Union(int x, int y) {  // O(Log(n)) + O(1)
        // int xset = Find(x);
        // int yset = Find(y);
        int xset = x;
        int yset = y;

        if (xset == yset) return;

        if (this->rank[xset] < this->rank[yset]) {
            this->parent[xset] = yset;
        } else if (this->rank[xset] > this->rank[yset]) {
            this->parent[yset] = xset;
        }

        else {
            this->parent[xset] = yset;
            this->rank[yset] = this->rank[yset] + 1;
        }
        this->succUnions++;
    }

    bool isConnected(int x, int y) { return Find(x) == Find(y); }

    int size() { return this->n; }

    int sets() { return this->n - this->succUnions; }

    int size(int x) {
        // recorrer todo el array y preguntar uno por uno por su padre
        // si son iguales sumas uno a s
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (x == this->parent[i]) s++;
        }
        return s;
    }

    map<int, int> CountSets() {
        map<int, int> setsbycount;
        for (int i = 0; i < sets(); ++i) {
            setsbycount.insert(pair<int, int>(i, size(i)));
        }
        return setsbycount;
    }

    void Add(T element, int x) {
        // resize del array ?
        this->dat[x] = element;
        this->parent[x] = x;
        Union(Find(x), Find(element));
    }

    vector<T> getElementsSet(int x) {
        vector<T> elements;
        for (int i = 0; i < n; ++i) {
            if (x == this->parent[i]) {
                elements.push_back(this->dat[i]);
            }
        }
        return elements;
    }

    void printSets() {
        cout << "-----------------------" << endl;
        cout << "-------PRINTSETS-------" << endl;
        cout << "Total Sets: " << sets() << endl;

        cout << setw(10);
        cout << "Index:  " << setw(10);
        for (int i = 0; i < n; ++i) {
            cout << i << setw(10);
        }
        cout << endl;

        cout << "Data:   " << setw(10);
        for (int i = 0; i < n; ++i) {
            cout << this->dat[i] << setw(10);
        }
        cout << endl;

        cout << "Parent: " << setw(10);
        for (int i = 0; i < n; ++i) {
            cout << this->parent[i] << setw(10);
        }
        cout << endl;

        cout << "Rank:   " << setw(10);
        for (int i = 0; i < n; ++i) {
            cout << this->rank[i] << setw(10);
        }
        cout << endl;
        cout << "-----------------------" << endl;
    }
};

#endif