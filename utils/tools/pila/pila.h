#include <iostream>
#include "../generic/nodo.h"

class Pila {
private:
    Nodo* tope; // Puntero al nodo en la parte superior de la pila

public:
    Pila() : tope(nullptr) {}

    // Empujar un elemento en la parte superior de la pila
    void push(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }

    // Sacar un elemento de la parte superior de la pila
    int pop() {
        if (isEmpty()) {
            std::cerr << "La pila está vacía." << std::endl;
            return -1; // Valor de error
        }

        Nodo* temp = tope;
        int valor = temp->valor;
        tope = temp->siguiente;
        delete temp;
        return valor;
    }

    // Verificar si la pila está vacía
    bool isEmpty() {
        return tope == nullptr;
    }

    // Liberar la memoria de la pila
    ~Pila() {
        while (!isEmpty()) {
            pop();
        }
    }
};