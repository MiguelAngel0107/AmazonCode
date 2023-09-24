#ifndef REGISTRO_USUARIO_HPP
#define REGISTRO_USUARIO_HPP

#include <iostream>
#include <string>
#include "../../utils/router/router.h"

class FormRegister
{
public:
    FormRegister() {}

    void mostrarFormulario(JsonDatabase db)
    {
        std::string nombreUsuario;
        std::string correoUsuario;
        std::string contrasena;
        std::string confirmarContrasena;

        // Solicitar nombre de usuario
        std::cout << "Ingrese el nombre de usuario: ";
        std::cin >> nombreUsuario;

        // Solicitar correo electrónico
        std::cout << "Ingrese el correo de usuario: ";
        std::cin >> correoUsuario;

        // Solicitar contraseña y confirmar contraseña
        do
        {
            std::cout << "Ingrese la contraseña: ";
            std::cin >> contrasena;

            std::cout << "Confirme la contraseña: ";
            std::cin >> confirmarContrasena;

            if (contrasena != confirmarContrasena)
            {
                std::cout << "Las contraseñas no coinciden. Intente nuevamente.\n";
            }
        } while (contrasena != confirmarContrasena);

        try
        {
            // Código que puede generar una excepción
            db.createUser(correoUsuario, contrasena, nombreUsuario, 0.0, "user", false);
        }
        catch (const std::exception &e)
        {
            // Manejo de la excepción
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "Registro exitoso. Usuario registrado:\n";
        std::cout << "Nombre de usuario: " << nombreUsuario << "\n";
        std::cout << "Correo de usuario: " << correoUsuario << "\n";
        std::cout << std::endl;
    }
};

#endif // REGISTRO_USUARIO_HPP
