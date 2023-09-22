#include <iostream>

class Nodo {
public:
    int valor;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int val) : valor(val), siguiente(nullptr), anterior(nullptr) {}
};

class ListaEnlazadaDoble {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista
    Nodo* cola;   // Puntero al último nodo de la lista

public:
    ListaEnlazadaDoble() : cabeza(nullptr), cola(nullptr) {}

    // Agregar un elemento al final de la lista
    void agregarAlFinal(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!cabeza) {
            cabeza = cola = nuevoNodo;
        } else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    // Agregar un elemento al principio de la lista
    void agregarAlPrincipio(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!cabeza) {
            cabeza = cola = nuevoNodo;
        } else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    // Imprimir la lista hacia adelante
    void imprimirHaciaAdelante() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Imprimir la lista hacia atrás
    void imprimirHaciaAtras() {
        Nodo* actual = cola;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->anterior;
        }
        std::cout << std::endl;
    }

    // Liberar la memoria de la lista
    ~ListaEnlazadaDoble() {
        while (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};