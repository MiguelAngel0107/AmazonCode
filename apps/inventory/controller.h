#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "../producto/controller.h"
#include "../../utils/tools/cola/cola.h"

class Inventory
{
public:
    Inventory() {}

    // Agregar un producto al inventario (encolar)
    void addProduct(const Product &product)
    {
        productQueue.enqueue(product);
    }

    // Mostrar productos disponibles (elementos en la cola)
    void showAvailableProducts()
    {
        std::cout << "Productos disponibles en el inventario:" << std::endl;
        // Mostrar productos sin sacarlos de la cola
        productQueue.display();
    }

    std::vector<Product> &obtenerInventario()
    {
        // Crea un vector para almacenar temporalmente los productos mientras se mantienen en la cola
        std::vector<Product> tempVector;

        // Mueve los productos de la cola al vector temporal
        while (!productQueue.isEmpty())
        {
            tempVector.push_back(productQueue.dequeue());
        }

        // Vuelve a encolar los productos desde tempVector a la cola para mantener el orden original
        for (const Product &product : tempVector)
        {
            productQueue.enqueue(product);
        }

        // Devuelve una referencia al vector temporal
        return tempVector;
    }

    // Buscar un producto por nombre
    void searchProductByName(const std::string &productName)
    {
        std::cout << "Buscando producto por nombre: " << productName << std::endl;
        Category myCategory(1, "Electronics");
        Product foundProduct(1, "Laptop", 999.99, 10, myCategory);
        bool found = false;

        // Buscar el producto en la cola sin eliminarlo
        Cola<Product> tempQueue; // Cola temporal para mantener el orden original
        while (!productQueue.isEmpty())
        {
            Product currentProduct = productQueue.dequeue();
            if (currentProduct.getName() == productName)
            {
                foundProduct = currentProduct;
                found = true;
            }
            tempQueue.enqueue(currentProduct);
        }

        // Restaurar la cola original
        while (!tempQueue.isEmpty())
        {
            productQueue.enqueue(tempQueue.dequeue());
        }

        if (found)
        {
            std::cout << "Producto encontrado: ID " << foundProduct.getId() << ", Precio: $" << foundProduct.getPrice() << ", Stock: " << foundProduct.getStock() << std::endl;
        }
        else
        {
            std::cout << "Producto no encontrado." << std::endl;
        }
    }

    // Actualizar el stock de un producto
    void updateStock(int productId, int newStock)
    {
        bool updated = false;

        // Actualizar el stock del producto en la cola
        Cola<Product> tempQueue; // Cola temporal para mantener el orden original
        while (!productQueue.isEmpty())
        {
            Product currentProduct = productQueue.dequeue();
            if (currentProduct.getId() == productId)
            {
                currentProduct.setStock(newStock);
                updated = true;
            }
            tempQueue.enqueue(currentProduct);
        }

        // Restaurar la cola original
        while (!tempQueue.isEmpty())
        {
            productQueue.enqueue(tempQueue.dequeue());
        }

        if (updated)
        {
            std::cout << "Stock actualizado para el producto ID " << productId << ". Nuevo stock: " << newStock << std::endl;
        }
        else
        {
            std::cout << "Producto con ID " << productId << " no encontrado." << std::endl;
        }
    }

private:
    Cola<Product> productQueue; // Utilizar una cola para el inventario
};

#endif