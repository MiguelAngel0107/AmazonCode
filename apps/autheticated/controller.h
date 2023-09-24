// Authentication.h
#ifndef AUTHENTICATED_H
#define AUTHENTICATED_H

#include <string>
#include "../usuario/controller.h"

class Authentication
{
public:
    Authentication()
    {
        alerState();
        currentUserEmail = ""; // Inicialmente no hay usuario autenticado
    };

    void login(std::string email)
    {
        currentUserEmail = email;
        stateSession = true;
        alerState();
    }
    void logout()
    {
        currentUserEmail = "";
        stateSession = false;
        alerState();
    };
    bool isLoggedIn() const
    {
        return !currentUserEmail.empty();
    };
    std::string getCurrentUserEmail() const
    {
        return currentUserEmail;
    };
    bool getState()
    {
        alerState();
        return stateSession;
    }
    void alerState()
    {
        //std::cout << "Estado auth:           " << stateSession << "         /////////////////////////" << std::endl;
    }

private:
    std::string currentUserEmail;
    bool stateSession = false;
};

#endif // AUTHENTICATION_H
