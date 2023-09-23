#ifndef NODO_H
#define NODO_H

#include <iostream>

template <typename T>
class NodoNormal
{
public:
    T valor;
    NodoNormal<T> *siguiente;

    NodoNormal<T>(T val) : valor(val), siguiente(nullptr) {}
};

template <class C>
class NodoComplejo
{
public:
    C valor;
    NodoComplejo<C> *siguiente;

    NodoComplejo<C>(C val) : valor(val), siguiente(nullptr) {}
};

#endif // NODO_H