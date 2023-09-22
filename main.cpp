#include <iostream>
#include "utils/router/router.h"
#include "apps/categoria/controller.h"

int main()
{
    // Nombre del archivo JSON
    std::string databaseFilename = "D:\\2023 Proyectos Mas avanzados\\UpcProyects\\AmazonCode\\db.json";

    // Crear una instancia de JsonDatabase
    JsonDatabase database(databaseFilename);

    // Cargar la base de datos desde el archivo JSON
    if (!database.load())
    {
        std::cerr << "No se pudo cargar la base de datos." << std::endl;
        return 1; // Salir con código de error
    }





    Category categoria(1, "primera");

    database.addProduct("Carne Nueva Vaca 225235", 2.99, 50, categoria);

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






    if (!database.save())
    {
        std::cerr << "No se pudo guardar la base de datos." << std::endl;
        return 1; // Salir con código de error
    }


    return 0;
}
