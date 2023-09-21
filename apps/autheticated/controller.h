// Authentication.h
#ifndef CONTROLLER
#define CONTROLLER

#include <string>
#include "apps/usuario/controller.h"

class Authentication
{
public:
    Authentication()
    {
        currentUserEmail = ""; // Inicialmente no hay usuario autenticado
    };

    bool login(const std::string &email, const std::string &password)
    {
        // Verifica si el usuario existe en la base de datos y si la contraseña proporcionada coincide
        // Implementa la lógica real de autenticación aquí

        // Ejemplo simplificado (debes implementar la lógica real)
        if (email == "usuario@example.com" && password == "contrasena123")
        {
            currentUserEmail = email; // Autenticación exitosa
            return true;
        }

        return false; // Autenticación fallida
    };
    void logout()
    {
        currentUserEmail = ""; // Cierra la sesión
    };
    bool isLoggedIn() const
    {
        return !currentUserEmail.empty();
    };
    std::string getCurrentUserEmail() const
    {
        return currentUserEmail;
    };

private:
    std::string currentUserEmail;
};

#endif // AUTHENTICATION_H
