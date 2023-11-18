#include <iostream>
#include "../generic/nodo.h"

template <class C>
class Pila
{
private:
    NodoComplejo<C> *tope; // Puntero al nodo en la parte superior de la pila

public:
    Pila() : tope(nullptr) {}

    // Empujar un elemento en la parte superior de la pila
    void push(C val)
    {
        NodoComplejo<C> *nuevoNodo = new NodoComplejo<C>(val);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }

    // Sacar un elemento de la parte superior de la pila
    C pop()
    {
        if (isEmpty())
        {
            std::cerr << "La pila está vacía." << std::endl;
            // return C(); // Valor de error
        }

        NodoComplejo<C> *temp = tope;
        C valor = temp->valor;
        tope = temp->siguiente;
        delete temp;
        return valor;
    }

    // Verificar si la pila está vacía
    bool isEmpty()
    {
        return tope == nullptr;
    }

    void mostrarPila(std::function<bool(const Product &)> callback)
    {
        NodoComplejo<C> *actual = tope;
        std::cout << "Elementos en la pila:"<< actual->valor.getName() << std::endl;
        while (actual)
        {
            if (callback(actual->valor))
            {
            };
            actual = actual->siguiente;
        }

        std::cout << std::endl;
    }

    C& top() {
    if (isEmpty()) {
        throw std::runtime_error("La pila está vacía");
    }
    return tope->valor; // Usa 'tope' en lugar de 'frente'
}

    // Liberar la memoria de la pila
    ~Pila()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};