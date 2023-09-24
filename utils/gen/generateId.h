#include <random>
#include <iostream>

class UniqueIdGenerator
{
public:
    static int generateUniqueId()
    {
        std::cout << "Entre a generar el numero" << std::endl;
        // Utiliza una generación de números aleatorios
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dis(1, 1000000); // Rango de IDs posibles
        std::cout << "Genere el numero" << std::endl;
        return dis(gen); // Genera un número único aleatorio
    }
};
