#ifndef ROUTER
#define ROUTER

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "utils/gen/generateId.h"
#include "apps/usuario/controller.h"
#include "apps/producto/controller.h"
#include "apps/categoria/controller.h"

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
        return true;
    };

    // Métodos para acceder y manipular los datos en la base de datos JSON
    bool addProduct(const std::string &name, double price, int stock, Category category)
    {
        // Genera un ID único para el nuevo producto
        int productId = UniqueIdGenerator::generateUniqueId();

        Product newProduct(productId, name, price, stock, category);
        database["db"]["tables"]["products"].push_back(newProduct.toJson());
        save();
        return true;
    };

    bool createUser(const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state)
    {
        // Verificar si el usuario ya existe (puedes implementar esta verificación)
        // Si el usuario no existe, crear una instancia de User y agregarlo a la base de datos JSON
        if (!userExists(email))
        {
            // Genera un ID único para el nuevo producto
            int userId = UniqueIdGenerator::generateUniqueId();

            User newUser(userId, email, password, name, money, role, state);
            database["db"]["tables"]["users"].push_back(newUser.toJson());
            save();
            return true;
        }
        return false; // El usuario ya existe
    }

    std::vector<User> getUsers() const
    {
        std::vector<User> usersList;

        for (const auto &userJson : database["db"]["tables"]["users"])
        {
            // Lee los datos del usuario desde el objeto JSON y crea una instancia de User
            User user(
                userJson["id"], // Asegúrate de que la clase User tenga un constructor que acepte el ID
                userJson["email"],
                userJson["password"],
                userJson["name"],
                userJson["money"],
                userJson["role"],
                userJson["state"]);

            usersList.push_back(user);
        }

        return usersList;
    }

    // Agregar más métodos según tus necesidades

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