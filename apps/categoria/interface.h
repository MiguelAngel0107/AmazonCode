#ifndef CATEGORIA_I
#define CATEGORIA_I

#include <iostream>
#include <vector>
#include <string>

#include "./controller.h"
#include "../../utils/router/router.h"

// Paso 2: Crear una clase concreta ConsoleCategoryDisplay
class CategoryDisplay
{
private:
    std::vector<Category> categories;

public:
    CategoryDisplay()
    {
    }

    void showCategories(JsonDatabase db)
    {
        categories = db.getCategories();

        std::cout << "======================================" << std::endl;
        std::cout << "Categorías disponibles:" << std::endl;
        std::cout << "======================================" << std::endl;

        for (const Category &category : categories)
        {
            std::cout << " /|\\ " << category.getName() << "  ";
        }

        std::cout << std::endl
                  << "======================================" << std::endl;
    }
};

#endif