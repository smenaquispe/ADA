#include <iostream>
using namespace std;

template<typename T>
void quick(T arr[], int izq, int der, bool(*comparacion)(T,T))
{ 
    int i, j; 
    i = izq; 
    j = der; 

    T aux, x;
    x = arr[ (izq + der) /2 ];  // x será nuestro pivot

    do{ 

        while( comparacion(arr[i],x) && (j <= der) ) // realizamos comparaciones desde el pivot, y el extremo derechi
            i++;
 
        while( comparacion(x,arr[j]) && (j > izq) ) // realizamos comparaciones desde el pivoy, y el extremo izquierdo
            j--;
    
 
        if( i <= j ){  // realizamos un swap si es que llegan a ser iguales o aun no llegaron a ser iguales
            aux = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = aux; 
            i++;  
            j--; 
        }
         
    }while( i <= j ); 
 
    
    if( izq < j ) // funcion recursiva siempre y cuando aun no lleguen a los extremos
        quick( arr, izq, j , comparacion); 
    if( i < der ) 
        quick( arr, i, der ,comparacion); 

}

template <typename T>
void quickSort(T arr[], int size, bool(*comparacion)(T,T)){
    quick(arr,0,size-1,comparacion);
}

#include <iostream>

// Función de comparación para ordenar enteros en orden ascendente
bool compareInt(int a, int b) {
    return a < b;
}

// Función de comparación para ordenar cadenas en orden alfabético ascendente
bool compareString(std::string a, std::string b) {
    return a < b;
}

int main() {
    // Ejemplo de ordenamiento de enteros
    int arrInt[] = {8, 3, 1, 5, 2, 7, 4, 6};
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);

    std::cout << "Arreglo original de enteros:" << std::endl;
    for (int i = 0; i < sizeInt; ++i) {
        std::cout << arrInt[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arrInt, sizeInt, compareInt);

    std::cout << "Arreglo ordenado de enteros:" << std::endl;
    for (int i = 0; i < sizeInt; ++i) {
        std::cout << arrInt[i] << " ";
    }
    std::cout << std::endl;

    // Ejemplo de ordenamiento de cadenas
    std::string arrString[] = {"banana", "apple", "orange", "grape", "kiwi"};
    int sizeString = sizeof(arrString) / sizeof(arrString[0]);

    std::cout << "Arreglo original de cadenas:" << std::endl;
    for (int i = 0; i < sizeString; ++i) {
        std::cout << arrString[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arrString, sizeString, compareString);

    std::cout << "Arreglo ordenado de cadenas:" << std::endl;
    for (int i = 0; i < sizeString; ++i) {
        std::cout << arrString[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
