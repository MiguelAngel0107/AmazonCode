#include <iostream>
#include "../generic/nodo.h"

class ListaEnlazada {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista

public:
    ListaEnlazada() : cabeza(nullptr) {}

    // Agregar un elemento al final de la lista
    void agregar(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    // Imprimir la lista
    void imprimir() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Liberar la memoria de la lista
    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};
