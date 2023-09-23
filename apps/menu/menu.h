#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <iomanip>

class Menu
{
public:
    Menu() {}

    void mostrarMenu()
    {
        std::cout << "***********************" << std::endl;
        std::cout << "     Bienvenido a" << std::endl;
        std::cout << "        Amazon" << std::endl;
        std::cout << "***********************" << std::endl;
        std::cout << std::setw(2) << "1. " << std::left << std::setw(20) << "Iniciar Sesión" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "2. " << std::left << std::setw(20) << "Registrarse" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "3. " << std::left << std::setw(20) << "Buscar Producto" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "4. " << std::left << std::setw(20) << "Ver Categoría de Productos" << std::setw(5) << "->" << std::endl;
    }

    void mostrarMenuAuthenticated()
    {
        std::cout << "***********************" << std::endl;
        std::cout << "     Bienvenido a" << std::endl;
        std::cout << "        Amazon" << std::endl;
        std::cout << "***********************" << std::endl;
        std::cout << std::setw(2) << "1. " << std::left << std::setw(20) << "Perfil" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "2. " << std::left << std::setw(20) << "Carrito de Compras" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "3. " << std::left << std::setw(20) << "Buscar Producto" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "4. " << std::left << std::setw(20) << "Ver Categoría de Productos" << std::setw(5) << "->" << std::endl;
        std::cout << std::setw(2) << "5. " << std::left << std::setw(20) << "Cerrar Sesion" << std::setw(5) << "->" << std::endl;
    }

    int ingresarOpcion()
    {
        std::cout << "***********************" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        return opcion;
    }

private:
    int opcion;
};

#endif
