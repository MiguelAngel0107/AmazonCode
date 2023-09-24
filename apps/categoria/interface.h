#ifndef CATEGORIA_I
#define CATEGORIA_I

#include <iostream>
#include <vector>
#include <string>

#include "./controller.h"

// Paso 2: Crear una clase concreta ConsoleCategoryDisplay
class CategoryDisplay {
public:
    void showCategories(const std::vector<Category> &categories)
    {
        std::cout << "======================================" << std::endl;
        std::cout << "Categorías disponibles:" << std::endl;
        std::cout << "======================================" << std::endl;

        for (const Category &category : categories)
        {
            std::cout << " /|\\ " << category.getName() << std::endl;
        }

        std::cout << "======================================" << std::endl;
    }
};

#endif