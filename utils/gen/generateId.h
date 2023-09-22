#include <random>

class UniqueIdGenerator {
public:
    static int generateUniqueId() {
        // Utiliza una generación de números aleatorios
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dis(1, 1000000); // Rango de IDs posibles

        return dis(gen); // Genera un número único aleatorio
    }
};


