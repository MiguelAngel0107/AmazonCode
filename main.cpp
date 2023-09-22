#include <iostream>
#include "utils/router/router.h"

int main()
{
    // Nombre del archivo JSON
    std::string databaseFilename = "C:\\Users\\Miguel\\Desktop\\AmazonCode\\db.json";

    // Crear una instancia de JsonDatabase
    JsonDatabase database(databaseFilename);

    // Cargar la base de datos desde el archivo JSON
    if (!database.load())
    {
        std::cerr << "No se pudo cargar la base de datos." << std::endl;
        return 1; // Salir con código de error
    }

    // Crear un nuevo usuario
    std::string email = "usuario@example.com";
    std::string password = "contrasena123";
    std::string name = "Nombre del Usuario";
    double money = 1000.0;
    std::string role = "usuario";
    bool state = true;

    bool createUserResult = database.createUser(email, password, name, money, role, state);

    if (createUserResult)
    {
        std::cout << "Usuario creado con éxito." << std::endl;
    }
    else
    {
        std::cerr << "No se pudo crear el usuario. El usuario ya existe." << std::endl;
    }

    // Leer la lista de usuarios desde la base de datos
    std::vector<User> usersList = database.getUsers();

    // Mostrar la lista de usuarios
    std::cout << "Lista de usuarios:" << std::endl;
    for (const User &user : usersList)
    {
        std::cout << "ID: " << user.getId() << std::endl;
        std::cout << "Email: " << user.getEmail() << std::endl;
        std::cout << "Nombre: " << user.getName() << std::endl;
        std::cout << "Saldo: " << user.getMoney() << std::endl;
        std::cout << "Rol: " << user.getRole() << std::endl;
        std::cout << "Estado: " << (user.getState() ? "Activo" : "Inactivo") << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    // Imprimir la base de datos para verificar
    std::cout << "Base de datos actualizada:\n";
    std::cout << std::setw(4) << database.load() << std::endl;

    return 0;
}
