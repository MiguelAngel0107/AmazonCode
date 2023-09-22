
#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <vector>
#include <string>

#include "../producto/controller.h"
#include "../usuario/controller.h"

class CajaDeCobranza
{
private:
    std::vector<Product> inventario;

public:
    CajaDeCobranza(const std::vector<Product> &inventario) : inventario(inventario) {}

    bool procesarCompra(User &usuario, const std::string &nombreProducto, int cantidad)
    {
        // Buscar el producto en el inventario
        for (Product &producto : inventario)
        {
            if (producto.getName() == nombreProducto)
            {
                // Verificar si hay suficiente stock
                if (producto.getStock() >= cantidad)
                {
                    // Calcular el costo total de los productos
                    double costoTotal = producto.getPrice() * cantidad;

                    // Verificar si el usuario tiene suficiente dinero
                    if (usuario.getMoney() >= costoTotal)
                    {
                        double aux = usuario.getMoney();
                        int temp = producto.getStock();
                        // Realizar la compra y descontar el dinero del usuario y el stock del producto
                        aux -= costoTotal;
                        temp -= cantidad;

                        usuario.setMoney(aux);
                        producto.setStock(temp);

                        std::cout << "Compra exitosa. Nuevo saldo del usuario: $" << usuario.getMoney() << std::endl;
                        return true;
                    }
                    else
                    {
                        std::cout << "El usuario no tiene suficiente dinero para comprar estos productos." << std::endl;
                        return false;
                    }
                }
                else
                {
                    std::cout << "No hay suficiente stock de " << nombreProducto << " para realizar la compra." << std::endl;
                    return false;
                }
            }
        }

        std::cout << "Producto no encontrado en el inventario." << std::endl;
        return false;
    }
};

#endif