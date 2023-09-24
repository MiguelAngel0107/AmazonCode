#ifndef INTERFACE_H
#define INTERFACE_H

#include "product.h"
#include <iostream>

class ProductList
{
public:
    // Constructor
    ProductList()
    {
        // Inicializar la cabeza y la cola de la lista como nulos
        head = nullptr;
        tail = nullptr;

        // Agregar 10 productos de ejemplo a la lista
        for (int i = 1; i <= 10; ++i)
        {
            addProduct(Product(i, "Producto " + std::to_string(i), i * 10.0, i * 5, Category("Categoría " + std::to_string(i))));
        }
    }

    // Destructor para liberar la memoria de la lista
    ~ProductList()
    {
        // Eliminar todos los nodos de la lista
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Función para agregar un producto a la lista
    void addProduct(const Product &product)
    {
        Node *newNode = new Node(product);
        if (head == nullptr)
        {
            // Si la lista está vacía, establecer el nuevo nodo como la cabeza y la cola
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Agregar el nuevo nodo al final de la lista
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Función para imprimir la información de un producto en función de su índice
    void printProductInfo(int index)
    {
        Node *current = head;
        int currentIndex = 1;

        while (current != nullptr && currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr)
        {
            // Imprimir la información del producto
            const Product &product = current->data;
            std::cout << "Producto: " << product.getName() << std::endl;
            std::cout << "Precio: " << product.getPrice() << std::endl;
            std::cout << "Stock Disponible: " << product.getStock() << std::endl;
        }
        else
        {
            std::cout << "Índice no válido. Debe estar entre 1 y 10." << std::endl;
        }
    }

private:
    // Nodo para la lista doblemente enlazada
    struct Node
    {
        Product data;
        Node *prev;
        Node *next;

        Node(const Product &product) : data(product), prev(nullptr), next(nullptr) {}
    };

    Node *head; // Puntero a la cabeza de la lista
    Node *tail; // Puntero a la cola de la lista
};

#endif // PRODUCT_LIST_H
