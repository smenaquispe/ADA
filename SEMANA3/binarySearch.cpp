#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void binarySearch(vector<int> & lista, int n, int l, int u) {

    if(u < l) {
        cout<<"No se encontro "<<n<<endl;
        return;
    }

    // tomamos el index central
    int m = (l + u) / 2;

    if(lista[m] == n) {
        cout<<"Se encontro en el index "<<m<<endl;
        return;
    } else if (lista[m] < n) {
        // solo se buscará en la parte izquierda
        binarySearch(lista, n, l, m - 1);
    } else if(lista[m] > n) {
        // solo se buscará la parte derecha
        binarySearch(lista, n, m + 1, u);
    }
    
}   

int main() {


    vector<int> lista = {132, 100, 99, 18, 10, 1};
 
    binarySearch(lista, 18, 0, lista.size() - 1);
    return 0;
}