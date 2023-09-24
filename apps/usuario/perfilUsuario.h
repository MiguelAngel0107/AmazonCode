
#ifndef PERFIL_USUARIO_HPP
#define PERFIL_USUARIO_HPP

#include <iostream>
#include <string>
#include "./controller.h"

class PerfilUsuario
{
public:
    // Constructor
    PerfilUsuario(int id, const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state) : user(id, email, password, name, money, role, state) {}

    // Función para configurar el objeto User
    void configurarUsuario(int id, const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state)
    {
        user.setId(id);
        user.setEmail(email);
        user.setPassword(password);
        user.setName(name);
        user.setMoney(money);
        user.setRole(role);
        user.setState(state);
    }
    
    // Función para imprimir el perfil del usuario en la consola
    void imprimirPerfil() const
    {
        std::cout << "Información del perfil de usuario:" << std::endl;
        std::cout << "Correo: " << user.getEmail() << std::endl;
        std::cout << "ID de usuario: " << user.getId() << std::endl;
        std::cout << "Dinero de usuario: $" << user.getMoney() << std::endl;
        std::cout << "Nombre de usuario: " << user.getName() << std::endl;
    }

private:
    User user;
};

#endif
