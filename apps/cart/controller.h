
#ifndef CART_H
#define CART_H

#include <string>
#include <iostream>
#include "../producto/controller.h"
#include "../../utils/tools/pila/pila.h"
#include "../../utils/router/router.h"
#include "../../utils/tools/tree/binary.hpp"
#include "../payment/controller.h"

class Cart
{
private:
    Pila<Product> productosCart;
    BinaryTree<Product> arbolProductos;

public:
    void agregarProducto(int id, JsonDatabase db)
    {
        productosCart.push(db.getProduct(id));
        arbolProductos.insert(db.getProduct(id));
    }

    void mostrarCarrito(User &usuario, CajaDeCobranza &caja)
    {
        std::cout << "==========================================================" << std::endl;
        std::cout << "Contenido del carrito:" << std::endl;
        auto funcionAuxiliar = [&](const Product &productoAux)
        {
            std::cout << "Nombre: " << productoAux.getName() << ", Precio: " << productoAux.getPrice() << std::endl;
            return false;
        };

        productosCart.mostrarPila(funcionAuxiliar);

        // Pregunta al usuario si desea ver los productos ordenados
        std::cout << "¿Desea ver los productos ordenados? (s/n): ";
        char opcion;
        std::cin >> opcion;

        if (opcion == 's' || opcion == 'S')
        {
            std::string tipoOrdenamiento;
            std::cout << "Ingrese el tipo de ordenamiento (preorden/postorden): ";
            std::cin >> tipoOrdenamiento;
            mostrarProductosOrdenados(tipoOrdenamiento);
        }

        // Pregunta al usuario si desea proceder con la compra
        std::cout << "¿Desea proceder con la compra? (s/n): ";
        char opcionCompra;
        std::cin >> opcionCompra;

        if (opcionCompra == 's' || opcionCompra == 'S')
        {
            proceedToCheckout(usuario, caja);
        }
    }

    void mostrarProductosOrdenados(const std::string &tipoOrdenamiento)
    {
        if (tipoOrdenamiento == "preorden")
        {
            arbolProductos.preOrderTraversal([](const Product &producto)
                                             { std::cout << "Nombre: " << producto.getName() << ", Precio: " << producto.getPrice() << std::endl; });
        }
        else if (tipoOrdenamiento == "postorden")
        {
            arbolProductos.postOrderTraversal([](const Product &producto)
                                              { std::cout << "Nombre: " << producto.getName() << ", Precio: " << producto.getPrice() << std::endl; });
        }
        else
        {
            std::cout << "Tipo de ordenamiento no reconocido." << std::endl;
        }
    }

    void proceedToCheckout(User &usuario, CajaDeCobranza &caja) {
        std::cout << "Procesando compra..." << std::endl;
        
        double totalCost = 0.0;
        while (!productosCart.isEmpty()) {
            Product producto = productosCart.top();
            productosCart.pop();

            if (caja.procesarCompra(usuario, producto.getName(), 1)) {
                totalCost += producto.getPrice();
            } else {
                std::cerr << "No se pudo procesar la compra del producto: " << producto.getName() << std::endl;
            }
        }

        std::cout << "Compra total: $" << totalCost << std::endl;
    }

    double calcularTotal()
    {
        double total = 0.0;
        arbolProductos.accumulate([](const Product &producto, double &acumulador)
                                  { acumulador += producto.getPrice(); },
                                  total);
        return total;
    }
};

#endif