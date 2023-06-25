#include<iostream>
using namespace std;

template<typename T>
void merge(T arr[], int l, int m, int r, bool(*comparacion)(T,T)) {
   int nl, nr;

   nl = m - l + 1; // tamaño del array por izquierda
   nr = r - m; // tamaño del array por derecha

   T larr[nl], rarr[nr];

   //llenamos los arrays con los respectivos fragmentos
   for(int i = 0; i < nl; i++)
      larr[i] = arr[l + i];

   for(int j = 0; j < nr; j++)
      rarr[j] = arr[m +1 + j];


   int i = 0, j = 0, k = l;

   //comenzamos a pasar los valores desde los temporales al array principal
   while(i < nl && j < nr) {
      if(comparacion(larr[i],rarr[j])) { 
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }

   while(i < nl) {  // exlemento extra en el array izquierdo
      arr[k] = larr[i];
      i++; k++;
   }
   while(j < nr) {  // elemento extra en el array derecho
      arr[k] = rarr[j];
      j++; k++;
   }
}

template<typename T>
void merging(T arr[], int l, int r, bool(*comparacion)(T,T)) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Realizamos la primera division y lo mandamos a la funcion recursiva
      merging(arr, l, m, comparacion);
      merging(arr, m+1, r, comparacion);
      merge(arr, l, m, r, comparacion);
   }
}

template<typename T>
void mergeSort(T arr[], int size, bool(*comparacion)(T,T)){
   merging(arr,0,size-1,comparacion);
}

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

    mergeSort(arrInt, sizeInt, compareInt);

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

    mergeSort(arrString, sizeString, compareString);

    std::cout << "Arreglo ordenado de cadenas:" << std::endl;
    for (int i = 0; i < sizeString; ++i) {
        std::cout << arrString[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
