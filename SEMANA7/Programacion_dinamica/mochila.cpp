#include<iostream>
#include<vector>
using namespace std;


struct Objecto
{
    int p;
    int b;
};


void mochila(int n, int M, vector<Objecto> & objetos) {
    int** tabla = new int*[n + 1];
    for(int i = 0; i < n + 1; i++) {
        tabla[i] = new int[M + 1];
    }

    // iniciamos los casos base en cero
    for(int i = 0; i <= n; i++) {
        tabla[i][0] = 0;
    }

    for(int j = 0; j <= M; j++) {
        tabla[0][j] = 0;
    }


    // la ecuacion aplicable luego
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= M; j++) {
            
            if(j - objetos[i - 1].p < 0) {
                tabla[i][j] = tabla[i - 1][j];
            } else {
                tabla[i][j] = max(tabla[i - 1][j], objetos[i - 1].b + tabla[i - 1][j - objetos[i - 1].p]);
            }

        }
    }

    // imprimimos la tabla
    
    cout<<"La tabla queda tal que asi: "<<endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= M; j++) {
            cout<<tabla[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"El mayor beneficio es: "<<tabla[n][M]<<endl;


    vector<int> x;
    int j = M;
    for(int i = n; i >= 1; i--) {
        if(tabla[i][j] == tabla[i - 1][j]) {
            x.push_back(0);
        } else {
            x.push_back(1);
            j = j - objetos[i - 1].p;
        }

    }

    cout<<endl<<"Se seleccionaron los siguiente objetos"<<endl;
    for(int i = 0; i < n; i++) {
        if(x[i]) {
            cout<<"Objeto: "<<i + 1<<endl;
            cout<<"peso: "<<objetos[i].p<<" - beneficio: "<<objetos[i].b<<endl;
        }
    }

}


int main() {

    vector<Objecto> objetos = {
        {2,1},
        {3,2},
        {4,5}
    };

    mochila(3, 6, objetos);

    return 0;
}