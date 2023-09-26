#ifndef CATEGORIA_I
#define CATEGORIA_I

#include <iostream>
#include <vector>
#include <string>

#include "./controller.h"
#include "../../utils/router/router.h"
#include "../producto/controller.h"
#include "../../utils/algorithms/algorithms.h"
#include "../cart/controller.h"

// Paso 2: Crear una clase concreta ConsoleCategoryDisplay
class CategoryDisplay
{
private:
    std::vector<Category> categories;
    std::vector<Product> productoByCategory;
    int option;
    std::string catSelect;
    int optionOrd;
    SortingAlgorithms algorithms;

public:
    CategoryDisplay()
    {
    }

    void showCategories(JsonDatabase db, Cart &cart)
    {
        categories = db.getCategories();

        std::cout << "=================================================================================================" << std::endl;
        std::cout << "Categorías disponibles:" << std::endl;
        std::cout << "=================================================================================================" << std::endl;

        for (const Category &category : categories)
        {
            std::cout << " | " << category.getId() << ". " << category.getName() << "  ";
        }

        std::cout << std::endl
                  << "=================================================================================================" << std::endl
                  << std::endl;
        std::cout << "Tu opcion es -->    ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            catSelect = "Deporte";
            break;
        case 2:
            catSelect = "Ropa";
            break;
        case 3:
            catSelect = "Hogar";
            break;
        case 4:
            catSelect = "Salud";
            break;
        case 5:
            catSelect = "Comida";
            break;

        default:
            break;
        }

        productoByCategory = db.getProductsByCategory(catSelect);

        std::cout
            << "=================================================================================================" << std::endl;
        std::cout << "Formas de Orden disponibles:" << std::endl;
        std::cout << "=================================================================================================" << std::endl;

        std::vector<std::string> ord = {"MejorPrecio", "MasPopular", "Alfabeticamente"};

        for (int i = 0; i < 3; i++)
        {
            std::cout << " | " << i << ". " << ord[i] << "  ";
        }

        std::cout << std::endl
                  << "=================================================================================================" << std::endl
                  << std::endl;
        std::cout << "Tu opcion es -->    ";
        std::cin >> optionOrd;

        auto funcionAuxiliar = [&](const std::vector<Product> &productoAux)
        {
            std::cout << "===================================================" << std::endl;
            std::cout << "|   Nombre   |   Precio   |   Stock   |   ID   |" << std::endl;
            std::cout << "===================================================" << std::endl;
            for (const Product &producto : productoAux)
            {
                std::cout << "| " << std::left << std::setw(11) << producto.getName()
                          << "| $" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << producto.getPrice()
                          << "| " << std::left << std::setw(8) << producto.getStock()
                          << "| " << std::left << std::setw(8) << producto.getId() << "|" << std::endl;
            }

            return false;
        };

        int op;

        switch (optionOrd)
        {
        case 0:
            algorithms.ordenarPorPrecio(productoByCategory);
            funcionAuxiliar(productoByCategory);
            std::cin >> op;
            cart.agregarProducto(op, db);
            break;
        case 1:
            algorithms.ordenarPorStock(productoByCategory);
            funcionAuxiliar(productoByCategory);
            std::cin >> op;
            cart.agregarProducto(op, db);
            break;
        case 2:
            algorithms.ordenarAlfabeticamente(productoByCategory);
            funcionAuxiliar(productoByCategory);
            std::cin >> op;
            cart.agregarProducto(op, db);
            break;
        default:
            break;
        }
    }
};

#endif