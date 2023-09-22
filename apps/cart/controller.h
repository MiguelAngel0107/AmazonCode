
#ifndef CART_H
#define CART_H

#include <string>
#include <iostream>
#include "../producto/controller.h"

class Cart {
private:
    std::vector<Product> productos;

public:
    void agregarProducto(const Product &producto) {
        productos.push_back(producto);
    }

    void mostrarCarrito() {
        if (productos.empty()) {
            std::cout << "El carrito está vacío." << std::endl;
        } else {
            std::cout << "Contenido del carrito:" << std::endl;
            for (const Product &producto : productos) {
                std::cout << "Nombre: " << producto.getName() << ", Precio: " << producto.getPrice() << std::endl;
            }
        }
    }

    double calcularTotal() {
        double total = 0.0;
        for (const Product &producto : productos) {
            total += producto.getPrice();
        }
        return total;
    }
};

#endif