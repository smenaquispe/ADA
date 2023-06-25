#include<iostream>
using namespace std;

int bsearch(double a[], double key, int l, int u)
{
    int m;
    if (u<l)
        return -1;
    m = (l+u) / 2;
    if (a[m] == key)
        return m;
    if (a[m] > key)
        return bsearch(a, key, l, m-1);
    else
        return bsearch(a, key, m+1, u);
}

int main() {
    double arr[] = {1.5, 2.3, 3.7, 5.2, 6.8, 7.9, 9.1}; // Ejemplo de arreglo ordenado ascendente
    int size = sizeof(arr) / sizeof(arr[0]);
    
    double key;
    std::cout << "Ingrese el número a buscar: ";
    std::cin >> key;
    
    int index = bsearch(arr, key, 0, size - 1);
    
    if (index == -1)
        std::cout << "El número no se encontró en el arreglo." << std::endl;
    else
        std::cout << "El número se encuentra en el índice: " << index << std::endl;
    
    return 0;
}