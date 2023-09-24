#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "utils/router/router.h"
#include "apps/categoria/controller.h"
#include "apps/menu/menu.h"
#include "apps/autheticated/controller.h"
#include "apps/autheticated/formularioRegistrar.h"
#include "apps/autheticated/formularioLogin.h"
#include "apps/usuario/perfilUsuario.h"
#include "apps/categoria/interface.h"
#include "apps/producto/interface.h"

int main()
{
    // Nombre del archivo JSON
    std::string databaseFilename = "D:\\2023 Proyectos Mas avanzados\\UpcProyects\\AmazonCode\\db.json";
    // Crear una instancia de JsonDatabase
    JsonDatabase database(databaseFilename);

    std::cout << "Algo paso 1";

    std::srand(std::time(0));
    int opcion;
    std::string txt;
    Menu menuBar;
    Authentication authSession;
    FormLogin loginInstance;
    FormRegister registerInstance;

    CategoryDisplay categorias;
    ProductList listaProductos;

    PerfilUsuario perfil(1, "", "", "", 0.0, "", false);

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
                perfil.imprimirPerfil();
                break;
            }
            else
            {
                loginInstance.loginUser(authSession, database, perfil);
                break;
            }
            break;
        case 2:
            if (authSession.getState())
            {
                // Aca va el Carrito
                // registerInstance.mostrarFormulario(database);
                break;
            }
            else
            {
                registerInstance.mostrarFormulario(database);
                break;
            }
            break;
        case 3:
            std::cout << "Tiene en mente el nombre de algun producto --> Y:si | N:no" << std::endl;
            std::cin >> opcion;
            switch (opcion)
            {
            case 121:
            case 89:
                /* Código para los casos 121 o 89 */
                std::cout << "Porfavor ingrese el nombre del producto que desea:" << std::endl;
                std::cin >> txt;
                break;
            case 110:
            case 78:
                /* Código para los casos 110 o 23 */
                listaProductos.printProductInfo(database);
                break;
            default:
                /* Código para otros casos */
                break;
            }
            break;
        case 4:
            categorias.showCategories(database);
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
