#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../../utils/tools/hash/tables.hpp"

// Estructura para representar un producto
struct Producto
{
    int id;
    std::string nombre;
    double precio;
    int stock;
    std::string categoria;
};

class SearchTablaHash
{
private:
    std::unordered_map<std::string, Producto> tablaHash;

    // Método privado para generar datos aleatorios
    Producto generarProductoAleatorio(int clave)
    {
        Producto p;
        p.id = clave;
        p.nombre = "Producto" + std::to_string(clave);
        p.precio = (rand() % 1000) / 100.0;
        p.stock = rand() % 100;
        p.categoria = "Categoria" + std::to_string(rand() % 5);
        return p;
    }

public:
    // Constructor que recibe una clave y genera datos
    SearchTablaHash(int clave)
    {
        srand(time(0)); // Inicializar el generador de números aleatorios
        Producto producto = generarProductoAleatorio(clave);
        tablaHash[producto.nombre] = producto;
    }

    // Método para buscar un producto por nombre
    Producto buscarProducto(const std::string &nombre)
    {
        if (tablaHash.find(nombre) != tablaHash.end())
        {
            return tablaHash[nombre];
        }
        else
        {
            throw std::runtime_error("Producto no encontrado");
        }
    }

    // Método para mostrar información de un producto
    void mostrarProducto(const Producto &producto)
    {
        std::cout << "ID: " << producto.id << "\n"
                  << "Nombre: " << producto.nombre << "\n"
                  << "Precio: " << producto.precio << "\n"
                  << "Stock: " << producto.stock << "\n"
                  << "Categoría: " << producto.categoria << "\n";
    }
};

#endif // PRODUCT_H