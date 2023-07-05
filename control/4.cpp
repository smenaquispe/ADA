#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Contenedor
{
    int c;
    int p;
};

bool compare(Contenedor & a, Contenedor & b) {
    return a.p >= b.p;
}

// para maximizar el numero de toneladas
// es necesario sumar los contenedores con mayor peso
void maximizarNumeroToneladas(int k, vector<Contenedor> & contenedores) {
    sort(contenedores.begin(), contenedores.end(), compare);

    int curr = 0;
    vector<Contenedor> selected;

    for(auto & a : contenedores) {
        curr += a.p;
        if(curr > k) break;
        selected.push_back(a);
    }

    cout<<"Los contenderos seleccionados para curbrir un peso de "<<k<<" toneladas son"<<endl;
    for(auto & a : selected) {
        cout<<"Numero de contenedor: "<<a.c<<" peso: "<<a.p<<" toneladas"<<endl;
    }
}


int main() {

    int k = 150; // capacidad del buque
    vector<Contenedor> contenedores = {
        {1, 60}, // numero de contenedor, y peso
        {2, 13}, 
        {3, 15}, 
        {4, 91}, 
        {5, 8}
    }; // contenedores
    maximizarNumeroToneladas(k, contenedores);


    return 0;
}