#ifndef ROUTER
#define ROUTER

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#include "apps/usuario/controller.h"

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
    void addProduct(const std::string &name, double price, int stock)
    {
        // Agregar un nuevo producto a la base de datos
        json newProduct = {
            {"name", name},
            {"price", price},
            {"stock", stock}};

        database["db"]["tables"]["products"].push_back(newProduct);
    };

    bool createUser(const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state)
    {
        // Verificar si el usuario ya existe (puedes implementar esta verificación)
        // Si el usuario no existe, crear una instancia de User y agregarlo a la base de datos JSON
        if (!userExists(email))
        {
            User newUser(email, password, name, money, role, state);
            database["db"]["tables"]["users"].push_back(newUser.toJson());
            save();
            return true;
            save();
            return true;
        }
        return false; // El usuario ya existe
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
};

#endif // JSON_DATABASE_H