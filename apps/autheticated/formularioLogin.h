
#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include "../usuario/controller.h"
#include "../usuario/perfilUsuario.h"
#include "../autheticated/controller.h"
#include "../../utils/router/router.h"
#include "../../utils/tools/generic/nodo.h"

class FormLogin
{
private:
    ListaEnlazada<User> listaUsuarios;

public:
    FormLogin() {}

    bool loginUser(Authentication &sessionAuth, JsonDatabase db, PerfilUsuario &perfil)
    {
        listaUsuarios = db.getUsersDB();

        std::string correo, contraseña;
        std::cout << "Ingrese su correo: ";
        std::cin >> correo;

        auto funcionAuxiliar = [&](const User &usuario)
        {
            // std::cout << "*********************Entre a la Call Funcion**********************" << std::endl;
            // std::cout << usuario.getEmail() << std::endl;
            // std::cout << usuario.getId() << std::endl;
            // std::cout << usuario.getMoney() << std::endl;
            // std::cout << usuario.getName() << std::endl;
            // std::cout << usuario.getPassword() << std::endl;
            // std::cout << usuario.getRole() << std::endl;
            // std::cout << usuario.getState() << std::endl;

            if (usuario.getName() == correo)
            {
                std::cout << "Ingrese su contraseña: ";
                std::cin >> contraseña;

                // Verificar si la contraseña coincide con la del usuario
                if (usuario.getPassword() == contraseña)
                {
                    std::cout << "Inicio de sesión exitoso." << std::endl;
                    return true;
                }
                else
                {
                    std::cout << "Contraseña incorrecta. Ingrese nuevamente." << std::endl;
                    return false;
                }
            }
            return false;
        };

        if (listaUsuarios.imprimirFunction(funcionAuxiliar))
        {
            sessionAuth.login(correo);
            User auxUser = db.getUser(correo);
            perfil.configurarUsuario(auxUser.getId(), auxUser.getEmail(), auxUser.getPassword(), auxUser.getName(), auxUser.getMoney(), auxUser.getRole(), true);
            return true;
        }

        // Si no se encuentra el correo en la lista
        std::cout
            << "El correo no está registrado. Debe registrarse primero." << std::endl;
        return false;
    }
};

#endif
