
#ifndef CART_H
#define CART_H

#include <string>
#include <iostream>
#include "../producto/controller.h"
#include "../../utils/tools/pila/pila.h"
#include "../../utils/router/router.h"

class Cart
{
private:
    Pila<Product> productosCart;

public:
    void agregarProducto(int id, JsonDatabase db)
    {
        productosCart.push(db.getProduct(id));
    }

    void mostrarCarrito()
    {
        std::cout << "==========================================================" << std::endl;
        std::cout << "Contenido del carrito:" << std::endl;
        auto funcionAuxiliar = [&](const Product &productoAux)
        {
            std::cout << "Nombre: " << productoAux.getName() << ", Precio: " << productoAux.getPrice() << std::endl;
            return false;
        };

        productosCart.mostrarPila(funcionAuxiliar);
    }

    double calcularTotal()
    {
        double total = 0.0;
        // for (const Product &producto : productosCart)
        //{
        //     total += producto.getPrice();
        // }
        return total;
    }
};

#endif