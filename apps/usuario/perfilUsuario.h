
#ifndef PERFIL_USUARIO_HPP
#define PERFIL_USUARIO_HPP

#include <iostream>
#include <string>

class PerfilUsuario {
public:
    // Constructor
    PerfilUsuario(const std::string& correo, int id, double dinero, const std::string& nombre) 
        : correo(correo), id(id), dinero(dinero), nombre(nombre) {}

    // Función para imprimir el perfil del usuario en la consola
    void imprimirPerfil() const {
        std::cout << "Información del perfil de usuario:" << std::endl;
        std::cout << "Correo: " << correo << std::endl;
        std::cout << "ID de usuario: " << id<< std::endl;
        std::cout << "Dinero de usuario: $" << dinero << std::endl;
        std::cout << "Nombre de usuario: " << nombre << std::endl;
    }

private:
    std::string correo;
    int id;
    double dinero;
    std::string nombre;
};

#endif 
