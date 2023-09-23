
#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include "../usuario/controller.h"
#include "../../utils/router/router.h"
#include "../../utils/tools/generic/nodo.h"

class FormLogin
{
private:
    std::unordered_map<std::string, std::string> userDatabase;
    ListaEnlazada<User> listaUsuarios;

public:
    FormLogin(JsonDatabase db)
    {
        listaUsuarios = db.getUsersDB();
    }

    bool loginUser()
    {
        std::string correo, contraseña;
        std::cout << "Ingrese su correo: ";
        std::cin >> correo;


        auto funcionAuxiliar = [&](const User &usuario)
        {
            // std::cout << "Entre a la Call Funcion" << std::endl;
            if (usuario.getEmail() == correo)
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
            return true;

        // Si no se encuentra el correo en la lista
        std::cout
            << "El correo no está registrado. Debe registrarse primero." << std::endl;
        return false;
    }
};

#endif
