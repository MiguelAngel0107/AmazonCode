#ifndef PRODUCT_I
#define PRODUCT_I

#include <iostream>
#include <vector>
#include <iomanip>
#include "./controller.h"

class InterfaceProduct
{
public:
    static void mostrarListaProductos(const std::vector<Product> &productos)
    {
        std::cout << "======================================" << std::endl;
        std::cout << "|   Nombre   |   Precio   |   Stock   |" << std::endl;
        std::cout << "======================================" << std::endl;

        for (const Product &producto : productos)
        {
            std::cout << "| " << std::left << std::setw(11) << producto.getName()
                      << "| $" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << producto.getPrice()
                      << "| " << std::left << std::setw(8) << producto.getStock() << "|" << std::endl;
        }

        std::cout << "======================================" << std::endl;
    }
};

#endif