#include<iostream>
#include<vector>
using namespace std;

void cambio(int n, int P, vector<int> c) {
    int ** D = new int*[n];
    for(int i = 0; i < n; i++ ){
        D[i] = new int[P + 1];
    }

    // seteamos a cero la primera columna
    for(int i = 0; i < n; i++) {
        D[i][0] = 0;
    }


    // realizamos los calculos
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= P; j++) {
            
            if(i - 1 < 0 || (j - c[i]) < 0) {
                D[i][j] = j;
                continue;
            }
            
            D[i][j] = min(D[i - 1][j], 1 + D[i][j - c[i]]);

        }
    }

    // imrprimimos tabla
    cout<<"La tabla resultante es la siguiente:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= P; j++) {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }

    // el resultado optimo
    cout<<endl<<"El resultado optimo es: "<<D[n - 1][P]<<endl;

    // recomponiendo solucion
    vector<int> x;
    for(int i = 0; i < n; i++){
        x.push_back(0);
    }

    int i = n - 1, j = P;

    while (i != 0 && j != 0)
    {
        if(D[i][j] == D[i - 1][j]) {
            i--;
        } else {
            x[i]++;
            j -= c[i];
        }
    }
    
    // imprimimos solucion
    cout<<"La moneda y cantidad usada por moneda:"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"Moneda ("<<c[i]<<") -> Cantidad ("<<x[i]<<")"<<endl;
    }
}

int main() {

    vector<int> c = {1, 4, 6};
    cambio(3,8, c);


    return 0;
}