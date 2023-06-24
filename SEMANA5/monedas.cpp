#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void imprimirResultado(vector<int> & monedasDisponibles, vector<int> & monedasUsadas) {
    int total = 0;
    std::cout<<"Monedas usadas:"<<endl;
    for(int i = 0; i < monedasDisponibles.size(); i++) {
        std::cout<<"Moneda: "<<monedasDisponibles[i]<<" -> cantidad: "<<monedasUsadas[i]<<endl;
        total += monedasUsadas[i];
    }
    std::cout<<"Total de monedas usadas: "<<total<<endl;
}

void devolverCambio(float P, vector<int> & monedasDisponibles) {
    
    // necesario ordenar de mayor a menor, de ser necesario
    sort(monedasDisponibles.rbegin(), monedasDisponibles.rend());
    
    int cant = 0; // cantidad de monedas utilizadas
    float rest = P; // cambio restante

    vector<int> monedasUsadas;

    for(auto & moneda : monedasDisponibles) {
        cant = floor(rest / moneda);
        monedasUsadas.push_back(cant);
        rest -= cant * moneda;
    }

    imprimirResultado(monedasDisponibles, monedasUsadas);
}

int main() {

    vector<int> monedasDisponibles = {100, 90, 1};

    devolverCambio(180, monedasDisponibles);

    return 0;
}