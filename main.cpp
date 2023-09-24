#include <iostream>
#include "utils/router/router.h"
#include "apps/categoria/controller.h"
#include "apps/menu/menu.h"
#include "apps/autheticated/controller.h"
#include "apps/autheticated/formularioRegistrar.h"
#include "apps/autheticated/formularioLogin.h"

int main()
{
    // Nombre del archivo JSON
    std::string databaseFilename = "D:\\2023 Proyectos Mas avanzados\\UpcProyects\\AmazonCode\\db.json";
    // Crear una instancia de JsonDatabase
    JsonDatabase database(databaseFilename);

    std::cout << "Algo paso 1";

    int opcion;
    Menu menuBar;
    Authentication authSession;
    FormLogin loginInstance(database);
    FormRegister registerInstance;

    while (true)
    {
        // Cargar la base de datos desde el archivo JSON
        if (!database.load())
        {
            std::cerr << "No se pudo cargar la base de datos." << std::endl;
            return 1; // Salir con código de error
        }

        if (authSession.getState())
        {
            menuBar.mostrarMenuAuthenticated();
        }
        else
        {
            menuBar.mostrarMenu();
        }

        opcion = menuBar.ingresarOpcion();

        switch (opcion)
        {
        case 1:
            if (authSession.getState())
            {
                loginInstance.loginUser();
                break;
            }
            else
            {
                loginInstance.loginUser();
                break;
            }
            break;
        case 2:
            if (authSession.getState())
            {
                registerInstance.mostrarFormulario(database);
                break;
            }
            else
            {
                registerInstance.mostrarFormulario(database);
                break;
            }
            break;
        case 3:
            // Lógica para buscar productos
            std::cout << "Opción 3 seleccionada: Buscar Producto" << std::endl;
            break;
        case 4:
            // Lógica para ver categoría de productos
            std::cout << "Opción 4 seleccionada: Ver Categoría de Productos" << std::endl;
            break;
        case 5:
            if (authSession.getState())
            {
                authSession.logout();
                break;
            }
            else
            {
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
            }
        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }

        // Pausa para que el usuario vea el resultado antes de mostrar el menú nuevamente
        std::cout << "Presione Enter para continuar..." << std::endl
                  << std::endl;
        std::cin.ignore(); // Limpia el búfer del teclado
        std::cin.get();    // Espera a que el usuario presione Enter
    }

    return 0;
}
