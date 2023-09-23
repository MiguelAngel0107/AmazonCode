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
        currentUserEmail = ""; // Inicialmente no hay usuario autenticado
    };
    
    void logout()
    {
        currentUserEmail = "";
        stateSession = false; 
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
        return stateSession;
    }
    void setState()
    {
        stateSession = !stateSession;
    }

private:
    std::string currentUserEmail;
    bool stateSession = false;
};

#endif // AUTHENTICATION_H
