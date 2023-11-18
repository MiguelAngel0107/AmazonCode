
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
        std::cout << "\t" << "\t" << "=================================================================================================" << std::endl;
        std::cout << "\t" << "\t" << "\t"  << "\t" << "\t" << "\t" << "INFORMACION DE PERFIL DE USUARIO" << std::endl;
        std::cout << "\t" << "\t" << "=================================================================================================" << std::endl;
        std::cout << "\n" << "\n" << "\t" << "\t" << "\t" << "Correo: " << user.getEmail() << std::endl;
        std::cout << "\n" << "\n" << "\t" << "\t" << "\t" << "ID de usuario: " << user.getId() << std::endl;
        std::cout << "\n" << "\n" << "\t" << "\t" << "\t" << "Dinero de usuario: $" << user.getMoney() << std::endl;
        std::cout << "\n" << "\n" << "\t" << "\t" << "\t" <<"Nombre de usuario: " << user.getName() << std::endl;
        std::cout << "\t" << "\t" << "=================================================================================================" << std::endl;
        }

    User& obtenerUsuario() {
        return user;
    }
private:
    User user;
};

#endif
