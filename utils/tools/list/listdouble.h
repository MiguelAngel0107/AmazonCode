#ifndef LISTDOUBLE_H
#define LISTDOUBLE_H

#include <iostream>

template <class Ca>
class Nodo
{
public:
    Ca valor;
    Nodo<Ca> *siguiente;
    Nodo<Ca> *anterior;

    Nodo<Ca>(Ca val) : valor(val), siguiente(nullptr), anterior(nullptr) {}
};

template <class C>
class ListaEnlazadaDoble
{
private:
    Nodo<C> *cabeza; // Puntero al primer nodo de la lista
    Nodo<C> *cola;   // Puntero al último nodo de la lista
    Nodo<C> *nodoActual;

public:
    ListaEnlazadaDoble() : cabeza(nullptr), cola(nullptr), nodoActual(nullptr) {}

    // Agregar un elemento al final de la lista
    void agregarAlFinal(C val)
    {
        Nodo<C> *nuevoNodo = new Nodo<C>(val);
        if (!cabeza)
        {
            cabeza = cola = nuevoNodo;
            //std::cout << "Se agrego Datos Cabeza" << std::endl;
        }
        else
        {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
            //std::cout << "Se agrego Datos" << std::endl;
        }
    }

    // Agregar un elemento al principio de la lista
    void agregarAlPrincipio(C val)
    {
        Nodo<C> *nuevoNodo = new Nodo<C>(val);
        if (!cabeza)
        {
            cabeza = cola = nuevoNodo;
        }
        else
        {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    // Imprimir la lista hacia adelante
    void imprimirHaciaAdelante()
    {
        Nodo<C> *actual = cabeza;
        while (actual)
        {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Imprimir la lista hacia atrás
    void imprimirHaciaAtras()
    {
        Nodo<C> *actual = cola;
        while (actual)
        {
            std::cout << actual->valor << " ";
            actual = actual->anterior;
        }
        std::cout << std::endl;
    }

    // Control Paginacion
    bool pointControl(std::function<bool(const std::vector<Product> &)> callback, char key)
    {
        if (!nodoActual && cabeza)
        {
            nodoActual = cabeza;

            // Llamar al callback con el nodo actual
            if (callback(nodoActual->valor))
            {
                return true;
            };
        }


        if (!nodoActual)
        {
            // La lista está vacía, no se puede navegar
            std::cout << "La lista está vacía." << std::endl;
            return false;
        }

        if (key == 'd')
        {
            // Tecla derecha: avanzar al siguiente nodo
            if (nodoActual->siguiente)
            {
                // Llamar al callback con el nodo actual
                if (callback(nodoActual->valor))
                {
                    return true;
                };

                nodoActual = nodoActual->siguiente;

                // Llamar al callback con el nodo actual
                if (callback(nodoActual->valor))
                {
                    return true;
                };
            }
            else
            {
                std::cout << "No hay siguiente nodo." << std::endl;
            }
        }
        else if (key == 'a')
        {
            // Tecla izquierda: retroceder al nodo anterior
            if (nodoActual->anterior)
            {
                nodoActual = nodoActual->anterior;

                // Llamar al callback con el nodo actual
                if (callback(nodoActual->valor))
                {
                    return true;
                };
            }
            else
            {
                std::cout << "No hay nodo anterior." << std::endl;
            }
        }
        else
        {
            std::cout << "Tecla no reconocida." << std::endl;
        }

        return false;
    }

    bool isEmpty() const
    {
        return cabeza == nullptr; // Si cabeza es nullptr, la lista está vacía
    }

    // Liberar la memoria de la lista
    ~ListaEnlazadaDoble()
    {
        while (cabeza)
        {
            Nodo<C> *temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif // LISTDOUBLE_H