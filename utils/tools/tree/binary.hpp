
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;

    // Función auxiliar para insertar de manera recursiva
    BinaryTreeNode<T>* insert(BinaryTreeNode<T>* node, T data) {
        if (node == nullptr) {
            return new BinaryTreeNode<T>(data);
        }
        if (compareProducts(data, node->data)) { // Utiliza una función de comparación
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    bool compareProducts(const Product& a, const Product& b) {
        // Comparar basado en un atributo específico
        return a.getId() < b.getId(); // Por ejemplo, comparar por ID
    }

    // Función auxiliar para realizar un recorrido inorden
    void inOrderTraversal(BinaryTreeNode<T>* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(BinaryTreeNode<T>* node, std::function<void(T)> func) {
        if (node != nullptr) {
            func(node->data);
            preOrderTraversal(node->left, func);
            preOrderTraversal(node->right, func);
        }
    }

    void postOrderTraversal(BinaryTreeNode<T>* node, std::function<void(T)> func) {
        if (node != nullptr) {
            postOrderTraversal(node->left, func);
            postOrderTraversal(node->right, func);
            func(node->data);
        }
    }

    void accumulate(BinaryTreeNode<T>* node, std::function<void(T, double&)> func, double& accumulator) {
        if (node != nullptr) {
            accumulate(node->left, func, accumulator);
            func(node->data, accumulator); // Procesar y acumular
            accumulate(node->right, func, accumulator);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data) {
        root = insert(root, data);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    void preOrderTraversal(std::function<void(T)> func) {
        preOrderTraversal(root, func);
    }

    void postOrderTraversal(std::function<void(T)> func) {
        postOrderTraversal(root, func);
    }

    void accumulate(std::function<void(T, double&)> func, double& accumulator) {
        accumulate(root, func, accumulator);
    }

    // Puedes agregar aquí más funciones, como búsqueda, eliminación, etc.
};


#endif 