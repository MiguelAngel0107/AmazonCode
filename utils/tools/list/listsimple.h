#include <iostream>
#include <functional>
#include "../generic/nodo.h"

template <class typeValue>
class ListaEnlazada
{
private:
    NodoComplejo<typeValue> *cabeza; // Puntero al primer nodo de la lista

public:
    ListaEnlazada() : cabeza(nullptr) {}

    // Agregar un elemento al final de la lista
    void agregar(const typeValue &val)
    {
        NodoComplejo<typeValue> *nuevoNodo = new NodoComplejo<typeValue>(val);
        if (!cabeza)
        {
            cabeza = nuevoNodo;
        }
        else
        {
            NodoComplejo<typeValue> *actual = cabeza;
            while (actual->siguiente)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    // Imprimir la lista
    void imprimir()
    {
        NodoComplejo<typeValue> *actual = cabeza;
        while (actual)
        {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    bool imprimirFunction(std::function<bool(const User &)> callback)
    {
        NodoComplejo<typeValue> *actual = cabeza;
        while (actual)
        {
            if (callback(actual->valor)) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    typeValue getCabeza()
    {
        return cabeza->valor;
    }

    // Liberar la memoria de la lista
    ~ListaEnlazada()
    {
        NodoComplejo<typeValue> *actual = cabeza;
        while (actual)
        {
            NodoComplejo<typeValue> *siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};
