#include <bits/stdc++.h>
using namespace std;

struct Arista
{
    int par[2];
    int peso;
};

bool estaSeleccionado(vector<Arista> & seleccionados, int i , int j) {
    for(auto & s : seleccionados) {
        if(s.par[0] == i && s.par[1] == j) {
            return true;
        }
    }

    return false;
}

template<size_t n>
bool esCiclo(vector<Arista> &seleccionados, int (&A)[n][n], int i, int j) {
    
    // con un size de 0 o 1, no se pueden formar cilcos
    if(seleccionados.size() <= 1) return false;
    
    // es ciclo si comienza con un numero a y el ultimo para tambien comienza con a
    // si existe algun 

    bool primero = false; // 
    bool segundo = false;

    for(auto & s : seleccionados) {
        if(s.par[0] == i) primero = true;
        if(s.par[1] == j) segundo = true;
    }

    return (primero && segundo);

}

bool esLista(vector<Arista> & seleccionados, int i, int j) {

    if(seleccionados.size() <= 1) return true;

    vector<Arista> aristas = seleccionados;
    Arista a;
    a.par[0] = i;
    a.par[1] = j;
    a.peso = 0;

    aristas.push_back(a);

    map<int, int> nodos;  
    bool band = true;

    for (const auto& arista : aristas) {
    
        int nodo1 = arista.par[0];
        int nodo2 = arista.par[1];

        if(!nodos[nodo1]) nodos[nodo1] = 1;
        else nodos[nodo1] += 1;
        
        if(!nodos[nodo2]) nodos[nodo2] = 1;
        else nodos[nodo2] += 1;


        if (nodos[nodo1] > 2 || nodos[nodo2] > 2) {
            band = false;
        }

    }
    
    return band;
}

template<size_t n>
void problemaViajante(int (&A)[n][n]) {
    // Código para resolver el problema del viajante
    
    /*
        hallar costes minimos
        y que al final se forme el ciclo (todos sean seleccionado)
    */

    vector<Arista> seleccionados;

    int menor = INT_MAX; // tomamos el primer valor para setear el menor peso
    int par[2];

    while (seleccionados.size() < n)
    {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(A[i][j] < menor && !estaSeleccionado(seleccionados, i, j)) {

                    if(seleccionados.size() == n) {
                        // el ultimo debe formar un ciclo
                        if(esCiclo(seleccionados, A, i, j) && esLista(seleccionados, i, j)) {
                            par[0] = i;
                            par[1] = j;

                            menor = A[i][j];

                            break;
                        }
                    } else {
                        // no debe formar ciclo, además de que debe ser una lista
                        if(!esCiclo(seleccionados, A, i, j) && esLista(seleccionados, i, j)) {
                            // guardamos el par seleccionado
                            par[0] = i;
                            par[1] = j;

                            menor = A[i][j];
                        }
                    }

                }
            }
        }

        Arista a;
        a.par[0] = par[0];
        a.par[1] = par[1];
        a.peso = menor;
        seleccionados.push_back(a);
        menor = INT_MAX;
    }
    
    int pesoTtoal = 0;
    for(auto & s : seleccionados) {
        cout<<"( "<<s.par[0] + 1<<" , "<<s.par[1] + 1<<" ) "<<" -> "<<s.peso<<endl;
        pesoTtoal += s.peso;
    }
    
    cout<<"Peso total: "<<pesoTtoal<<endl;

}

int main() {
    const int n = 5; // número de nodos
    // matriz de adyacencia
    int A[n][n] = {
        {0, 10, 55, 25, 45},
        {0, 0, 20, 25, 40},
        {0, 0, 0, 15, 30},
        {0, 0, 0, 0, 50},
        {0, 0, 0, 0, 0}
    };
    // como es no direccionado, basta con llenar la mitad
    problemaViajante(A);

    return 0;
}
