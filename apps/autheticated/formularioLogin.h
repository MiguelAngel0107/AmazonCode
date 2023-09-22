
#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include <unordered_map>

class formLogin {
private:
    std::unordered_map<std::string, std::string> userDatabase;

public:
    formLogin() {
        // Simulamos una base de datos de usuarios con correos y contraseñas.
        // Puedes reemplazar esto con una base de datos real en tu aplicación.
        userDatabase["usuario1@example.com"] = "contraseña1";
        userDatabase["usuario2@example.com"] = "contraseña2";
        userDatabase["usuario3@example.com"] = "contraseña3";
    }

    bool loginUser() {
        std::string correo, contraseña;
        std::cout << "Ingrese su correo: ";
        std::cin >> correo;

        // Verificar si el correo está en la base de datos.
        if (userDatabase.find(correo) == userDatabase.end()) {
            std::cout << "El correo no está registrado. Debe registrarse primero." << std::endl;
            return false;
        }

        std::cout << "Ingrese su contraseña: ";
        std::cin >> contraseña;

        // Verificar si la contraseña coincide con la de la base de datos.
        if (userDatabase[correo] != contraseña) {
            std::cout << "Contraseña incorrecta. Ingrese nuevamente." << std::endl;
            return false;
        }

        std::cout << "Inicio de sesión exitoso." << std::endl;
        return true;
    }
};

#endif
