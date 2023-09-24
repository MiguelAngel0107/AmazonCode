#ifndef ROUTER
#define ROUTER

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#include "../gen/generateId.h"
#include "../../apps/usuario/controller.h"
#include "../../apps/producto/controller.h"
#include "../../apps/categoria/controller.h"
#include "../tools/list/listsimple.h"

using json = nlohmann::json;

class JsonDatabase
{
public:
    JsonDatabase(const std::string &filename) : filename(filename){};

    bool load()
    {
        std::ifstream file;
        if (!openFileForReading(file))
        {
            return false;
        }

        file >> database;
        file.close();
        std::cout << std::endl
                  << "-----------------Se Cargo Nuevo Datos------------------------" << std::endl;
        return true;
    };
    bool save()
    {
        std::ofstream file;
        if (!openFileForWriting(file))
        {
            return false;
        }

        file << std::setw(4) << database << std::endl;
        file.close();
        std::cout << std::endl
                  << "-----------------Se Guardo Nuevo Datos------------------------" << std::endl;
        return true;
    };

    // Métodos para acceder y manipular los datos en la base de datos JSON //

    bool addProduct(const std::string &name, double price, int stock, Category category)
    {
        // Genera un ID único para el nuevo producto
        int productId = UniqueIdGenerator::generateUniqueId();

        Product newProduct(productId, name, price, stock, category);

        json newProductJson = newProduct.toJson();
        std::string jsonString = newProductJson.dump();
        std::cout << "Contenido de newProduct.toJson(): " << jsonString << std::endl;

        try
        {
            // Intenta agregar un objeto JSON al arreglo
            database["db"]["tables"]["products"].push_back({{"name", name},
                                                            {"price", price},
                                                            {"stock", stock}});

            // Si no se produce ninguna excepción, el objeto JSON se agregó con éxito
            std::cout << "El objeto JSON se agregó correctamente." << std::endl;
        }
        catch (const json::exception &e)
        {
            // Captura y maneja la excepción
            std::cerr << "Error al agregar el objeto JSON: " << e.what() << std::endl;
        }

        return true;
    };

    bool createUser(const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state)
    {
        std::cout << "Entre a la funcion Create 1" << std::endl;
        if (!userExists(email))
        {
            // Genera un ID único para el nuevo producto
            int userId = UniqueIdGenerator::generateUniqueId();

            User newUser(userId, email, password, name, money, role, state);

            database["db"]["tables"]["users"].push_back({{"id", userId},
                                                         {"email", email},
                                                         {"password", password},
                                                         {"name", name},
                                                         {"money", money},
                                                         {"role", role},
                                                         {"state", state}});
            std::cout << "Entre a la funcion Create 2" << std::endl;

            // Después de agregar el usuario, guarda los cambios en la base de datos JSON.
            if (!save())
            {
                std::cerr << "No se pudo guardar la base de datos." << std::endl;
                return false;
            }

            return true;
        }
        return false; // El usuario ya existe
    }

    User getUser(const std::string &email)
    {
        // Busca el usuario por su correo electrónico
        for (const auto &userJson : database["db"]["tables"]["users"])
        {
            if (userJson["email"] == email)
            {
                std::cout << "User: " << userJson["email"];
                User user(userJson["id"], userJson["email"], userJson["password"], userJson["name"], userJson["money"], userJson["role"], userJson["state"]);
                return user;
            }
        }

        // Si no se encuentra el usuario, devuelve un usuario vacío
        return User(0, "", "", "", 0.0, "", false);
    }

    ListaEnlazada<User> getUsersDB()
    {
        ListaEnlazada<User> listaUsuarios;

        std::cout << "Algo paso getUsers 2.1" << std::endl;
        for (const auto &userJson : database["db"]["tables"]["users"])
        {
            std::cout << "Algo paso 2.2" << std::endl;
            User user(
                userJson["id"],
                userJson["email"],
                userJson["password"],
                userJson["name"],
                userJson["money"],
                userJson["role"],
                userJson["state"]);

            listaUsuarios.agregar(user);
        }
        std::cout << "Algo paso getUsers 2.3" << std::endl;
        return listaUsuarios;
    }

private:
    std::string filename;
    json database;

    // Métodos privados
    bool openFileForReading(std::ifstream &file)
    {
        file.open(filename);
        if (!file.is_open())
        {
            std::cerr << "No se pudo abrir el archivo JSON para lectura." << std::endl;
            return false;
        }
        return true;
    };
    bool openFileForWriting(std::ofstream &file)
    {
        file.open(filename);
        if (!file.is_open())
        {
            std::cerr << "No se pudo abrir el archivo JSON para escritura." << std::endl;
            return false;
        }
        return true;
    };
    bool userExists(const std::string &email) const
    {
        for (const auto &user : database["db"]["tables"]["users"])
        {
            if (user["email"] == email)
            {
                return true;
            }
        }
        return false;
    }
    bool productExists(const std::string &name) const
    {
        for (const auto &product : database["db"]["tables"]["products"])
        {
            if (product["name"] == name)
            {
                return true;
            }
        }
        return false;
    }
};

#endif // JSON_DATABASE_H