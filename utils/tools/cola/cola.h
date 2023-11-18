#include <iostream>
#include "../generic/nodo.h"

template <class C>
class Cola {
private:
    NodoComplejo<C>* frente; // Puntero al nodo en el frente de la cola
    NodoComplejo<C>* final;  // Puntero al nodo en el final de la cola

public:
    Cola() : frente(nullptr), final(nullptr) {}

    // Agregar un elemento al final de la cola
    void enqueue(const C& val) {
        NodoComplejo<C>* nuevoNodo = new NodoComplejo<C>(val);
        if (!frente) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    // Sacar un elemento del frente de la cola
    C dequeue() {
        if (isEmpty()) {
            std::cerr << "La cola está vacía." << std::endl;
            return C(); // Retornar un objeto C por defecto
        }

        NodoComplejo<C>* temp = frente;
        C valor = temp->valor;
        frente = frente->siguiente;
        delete temp;
        return valor;
    }

    // Verificar si la cola está vacía
    bool isEmpty() {
        return frente == nullptr;
    }

    // Buscar un producto en la cola por un criterio (sin desencolar)
    C search(const std::string& criteria, bool& found) {
        NodoComplejo<C>* actual = frente;
        while (actual != nullptr) {
            if (actual->valor.getName() == criteria) { // Asumiendo que C tiene el método getName()
                found = true;
                return actual->valor;
            }
            actual = actual->siguiente;
        }
        found = false;
        return C(); // Retornar un objeto C por defecto si no se encuentra
    }

    // Actualizar el stock de un producto en la cola
    bool updateStock(int productId, int newStock) {
        NodoComplejo<C>* actual = frente;
        while (actual != nullptr) {
            if (actual->valor.getId() == productId) { // Asumiendo que C tiene el método getId() y setStock()
                actual->valor.setStock(newStock);
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Método para mostrar todos los elementos en la cola
    void display() const {
        NodoComplejo<C>* actual = frente;
        while (actual != nullptr) {
            std::cout << actual->valor << std::endl; // Asumiendo que C tiene un operador de salida sobrecargado
            actual = actual->siguiente;
        }
    }

    ~Cola() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};