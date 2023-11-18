#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Product {
    int id;
    std::string name;
    double price;
    int stock;
    std::string category;
};

// Función para generar un nombre de producto aleatorio
std::string generateRandomName() {
    std::string names[5] = {"Producto", "Artículo", "Objeto", "Gadget", "Herramienta"};
    return names[rand() % 5] + std::to_string(rand() % 100);
}

// Función para obtener una categoría aleatoria
std::string getRandomCategory() {
    std::string categories[5] = {"Deporte", "Ropa", "Hogar", "Salud", "Comida"};
    return categories[rand() % 5];
}

// Función para generar un producto aleatorio
Product generateRandomProduct() {
    Product product;
    product.id = rand() % 10000 + 1;
    product.name = generateRandomName();
    product.price = (rand() % 10000) / 100.0;
    product.stock = rand() % 100 + 1;
    product.category = getRandomCategory();
    return product;
}