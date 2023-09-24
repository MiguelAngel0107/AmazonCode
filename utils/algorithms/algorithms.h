#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../../apps/producto/controller.h"

class SortingAlgorithms
{
public:
    // Fisher-Yates shuffle para mezclar un vector
    static void fisherYatesShuffle(std::vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            std::swap(arr[i], arr[j]);
        }
    }

    // Ordenamiento Burbuja
    static void bubbleSort(std::vector<int> &arr)
    {
        int n = arr.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    // Ordenamiento por Selección
    static void selectionSort(std::vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            std::swap(arr[i], arr[min_idx]);
        }
    }

    // Ordenamiento por Inserción
    static void insertionSort(std::vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Ordenamiento Shell
    static void shellSort(std::vector<int> &arr)
    {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    bool compararPorPrecio(const Product &a, const Product &b)
    {
        return a.getPrice() > b.getPrice(); // Ordenar de mayor a menor precio
    }

    bool compararPorStock(const Product &a, const Product &b)
    {
        return a.getStock() > b.getStock(); // Ordenar de mayor a menor precio
    }

    void ordenarPorPrecio(std::vector<Product> &productos)
    {
        int n = productos.size();
        for (int i = 0; i < n - 1; i++)
        {
            int max_idx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (compararPorPrecio(productos[j], productos[max_idx]))
                {
                    max_idx = j;
                }
            }
            if (max_idx != i)
            {
                std::swap(productos[i], productos[max_idx]);
            }
        }
    }
};
