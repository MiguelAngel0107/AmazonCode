#include <iostream>
#include "../generic/nodo.h"

class Cola {
private:
    Nodo* frente; // Puntero al nodo en el frente de la cola
    Nodo* final;  // Puntero al nodo en el final de la cola

public:
    Cola() : frente(nullptr), final(nullptr) {}

    // Agregar un elemento al final de la cola
    void enqueue(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!frente) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    // Sacar un elemento del frente de la cola
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "La cola está vacía." << std::endl;
            return -1; // Valor de error
        }

        Nodo* temp = frente;
        int valor = temp->valor;
        frente = frente->siguiente;
        delete temp;
        return valor;
    }

    // Verificar si la cola está vacía
    bool isEmpty() {
        return frente == nullptr;
    }

    // Liberar la memoria de la cola
    ~Cola() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};