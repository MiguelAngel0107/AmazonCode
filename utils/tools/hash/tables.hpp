#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int BUCKET;    // Número de buckets
    list<int> *table; // Puntero a un array que contiene las listas enlazadas

public:
    HashTable(int V) {
        this->BUCKET = V;
        table = new list<int>[BUCKET];
    }

    // Función hash para calcular el índice para la clave
    int hashFunction(int x) {
        return x % BUCKET;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == key)
                break;
        }
        if (i != table[index].end())
            table[index].erase(i);
    }

    void displayHash() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

#endif // NODO_H
