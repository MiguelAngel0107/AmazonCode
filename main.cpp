#include <iostream>
#include "utils/router/router.h"

int main() {
    // Nombre del archivo JSON
    std::string databaseFilename = "C:\\Users\\Miguel\\Desktop\\AmazonCode\\db.json";

    // Crear una instancia de JsonDatabase
    JsonDatabase database(databaseFilename);

    // Cargar la base de datos desde el archivo JSON
    if (!database.load()) {
        std::cerr << "No se pudo cargar la base de datos." << std::endl;
        return 1; // Salir con código de error
    }

    // Agregar un producto a la base de datos
    database.addProduct("Leche", 2.99, 50);

    // Guardar la base de datos actualizada en el archivo JSON
    if (!database.save()) {
        std::cerr << "No se pudo guardar la base de datos." << std::endl;
        return 1; // Salir con código de error
    }

    // Imprimir la base de datos para verificar
    std::cout << "Base de datos actualizada:\n";
    std::cout << std::setw(4) << database.load() << std::endl;

    return 0;
}
