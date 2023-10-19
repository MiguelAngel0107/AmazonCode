#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <iomanip>
class Menu
{
public:

    Menu() {}

    void mostrarMenu()
    {
        std::cout << "\n" << "\n" << std::endl;
    std::cout << "\t" << "\t" << "\t"<< "    /*+/  /+*/   /*+*+*+*+*/   /*+*+*+*+/     /*+\   /*+*|     /*+*+*+*+*/   /*+*+*+*+*/" << std::endl ;
    std::cout << "\t" << "\t" << "\t"<< "   /*+/__/+*/   /*+/______    /*+/  /+*/     /*+*+\_/*+**|    /*+/______    /*+/______ " << std::endl;
    std::cout << "\t" << "\t" << "\t"<< "  /*+ __ +*/   /*+*+*+*+*/   /*+*+*+* /     /*+/\*+*+/**+|   /*+*+*+*+*/   /*+*+*+*+*/" << std::endl;
    std::cout << "\t" << "\t" << "\t"<< " /*+/  /+*/   /*+/_____     /*+/  \+*\       /*+/  \*+/ /+*/  /*+/_____     _______/*+/" << std::endl;
    std::cout << "\t" << "\t" << "\t"<< "/*+/  /+*/   /*+*+*+*+*/   /*+/    \+*\     /*+/      /+*/  /*+*+*+*+*/   /*+*+*+*+*/" << std::endl;

    std::cout << "\n" << "\n" << "\n" << "\t" << "\t" << "\t" << "'BIENVENIDO A HERMES , LOS MEJORES PRECIOS DONDE CADA DIA ES VIERNES'" << std::endl;
    std::cout << "\n" << "\n" << "\t" << "\t" << "\t" << "1. " << "INICIAR SESION" << "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "2. " << "REGISTRARSE" << "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "3. " << "BUSCAR PRODUCTO" << "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "4. " << "VER CATEGORIA DE PRODUCTOS" <<  "   ->" << std::endl;
    std::cout << "\n" << "\n" << std::endl;
    }

    void mostrarMenuAuthenticated()
    {
        std::cout << "\n" << "\n" << std::endl;
    std::cout << "\t" << "\t" << "\t"<< "    /*+/  /+*/   /*+*+*+*+*/   /*+*+*+*+/     /*+\   /*+*|     /*+*+*+*+*/   /*+*+*+*+*/" << std::endl ;
    std::cout << "\t" << "\t" << "\t"<< "   /*+/__/+*/   /*+/______    /*+/  /+*/     /*+*+\_/*+**|    /*+/______    /*+/______ " << std::endl;
    std::cout << "\t" << "\t" << "\t"<< "  /*+ __ +*/   /*+*+*+*+*/   /*+*+*+* /     /*+/\*+*+/**+|   /*+*+*+*+*/   /*+*+*+*+*/" << std::endl;
    std::cout << "\t" << "\t" << "\t"<< " /*+/  /+*/   /*+/_____     /*+/  \+*\       /*+/  \*+/ /+*/  /*+/_____     _______/*+/" << std::endl;
    std::cout << "\t" << "\t" << "\t"<< "/*+/  /+*/   /*+*+*+*+*/   /*+/    \+*\     /*+/      /+*/  /*+*+*+*+*/   /*+*+*+*+*/" << std::endl;

    std::cout << "\n" << "\n" << "\n" << "\t" << "\t" << "\t" << "'BIENVENIDO A HERMES , LOS MEJORES PRECIOS DONDE CADA DIA ES VIERNES'" << std::endl;
    std::cout << "\n" << "\n" << "\t" << "\t" << "\t" << "1. " << "PERFIL" << "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "2. " << "CARRITO DE COMPRAS" << "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "3. " << "BUSCAR PRODUCTO" << "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "4. " << "VER CATEGORIA DE PRODUCTOS" <<  "   ->" << std::endl;
    std::cout << "\n" << "\t" << "\t" << "\t" << "5. " << "CERRAR SESION" <<  "   ->" << std::endl;
    std::cout << "\n" << "\n" << std::endl;
    }

    int ingresarOpcion()
    {
        std::cout << "\n" << "\t" << "\t" << "\t" << "INGRESE UNA OPCION: ";
        std::cin >> opcion;
        return opcion;
    }

private:
    int opcion;
};

#endif
