#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <conio.h>
#include "./controller.h"
#include "../../utils/tools/list/listdouble.h"
#include "../../utils/router/router.h"

class ProductList
{
public:
    ProductList() {}

    void printProductInfo(JsonDatabase db)
    {
        char key;

        productList = db.getProductsDB();

        // Verificar si productList está vacía antes de imprimir
        if (productList.isEmpty())
        {
            std::cout << "La lista de productos está vacía." << std::endl;
            return;
        }

        auto funcionAuxiliar = [&](const std::vector<Product> &productoAux)
        {
            std::cout << "\t" << "\t" << "\t" << "\t" << "\t" << "=====================================" << std::endl;
            std::cout << "\t" << "\t" << "\t" << "\t" << "\t" << "|   NOMBRE   |   PRECIO  |   STOCK   |" << std::endl;
            std::cout << "\t" << "\t" << "\t" << "\t" << "\t" << "=====================================" << std::endl;
            for (const Product &producto : productoAux)
            {
                std::cout << "\t" << "\t" << "\t" << "\t" << "\t" << "| " << std::left << std::setw(11) << producto.getName()
                          << "| $" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << producto.getPrice()
                          << "| " << std::left << std::setw(8) << producto.getStock() << "|" << std::endl;
            }

            return false;
        };

        while (true)
        {
            std::cout << "\t" << "\t" << "\t" << "\t" << "\t" << "Presione A (<--) ó D (-->) ó Q (Salir)  para continuar..." << std::endl;
            key = _getch();
            if (key == 'q')
            {
                // Salir si se presiona la tecla 'q'
                break;
            }
            if (productList.pointControl(funcionAuxiliar, key))
                break;
        }
    }

private:
    ListaEnlazadaDoble<std::vector<Product>> productList;
};

#endif // PRODUCT_LIST_H
