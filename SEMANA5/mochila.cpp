#include<iostream>
#include<vector>
#include<array>
using namespace std;

struct Objeto
{
    int p;
    int b;
};

bool noFueTomado(int i, vector<int> & objetosTomados) {
    for(int & elem : objetosTomados) {
        if(i == elem) return false; // si fue tomado
    }

    return true;
}

template<size_t Size>
int mejorObjeto(array<Objeto, Size> & objetos, vector<int> & objetosTomados) {
    float mayor = -1;
    int index = -1;

    int i = 0;
    for(Objeto & ob : objetos) {
        if((ob.b * 1.0 / ob.p) >= mayor && noFueTomado(i, objetosTomados)) {
            mayor = (ob.b * 1.0 / ob.p);
            index = i;
        }
        i++;
    }

    return index;
}

template<size_t Size>
void mochila(int M, array<Objeto, Size> objetos) {
    int pesoAct = 0; // acumulador del peso de los objetos

    // guarda los indexes de objetos que ya fueron tomados
    vector<int> objetosTomados;

    // guarda la cantidad de objetos que ya fueron guardados en la mochila
    array<float, Size> objetosGuardados;
    fill(objetosGuardados.begin(), objetosGuardados.end(), 0);

    while (pesoAct < M)
    {
        int i = mejorObjeto(objetos, objetosTomados);

        // caso se puede guardar el objeto entero
        if(pesoAct + objetos[i].p <= M) {
            objetosGuardados[i] = 1;
            pesoAct += objetos[i].p;
        } else { // caso se debe guardar por partes
            objetosGuardados[i] = (M - pesoAct) * 1.0 / objetos[i].p;
            pesoAct = M;
        }

        objetosTomados.push_back(i);

    }

    for(int i = 0; i < Size; i++) {
        cout<<objetosGuardados[i]<<" ";
    }
}

int main() {

  
    const size_t n = 4;
    int M = 10;

    // ejemplo 1
    /*
    array<Objeto, n> objetos = {
        Objeto{10,10},
        Objeto{3,9},
        Objeto{3,9},
        Objeto{4,9}
    };
    */

    // ejemplo 2
    array<Objeto, n> objetos = {
        Objeto{10,10},
        Objeto{3,1},
        Objeto{3,1},
        Objeto{4,1}
    };


    mochila(M, objetos);
    
    
    return 0;
}