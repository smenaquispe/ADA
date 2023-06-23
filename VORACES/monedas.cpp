#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<float> C = {100, 90, 1};

void DevolverCambio2(int P, int n) {
    vector<float> X;
    float act = 0;

    int j = 0;
    while (act != P)
    {
        if(j == n - 1) {
            std::cout<<"No hay  resultado poisible"<<endl;
            return;
        }


        
    }
    
}
/*
void DevolverCambio(int P, int C[], int X[], int n) {
    int act = 0;
    int j = n - 1;

    for(int i = 0; i < n; i++) {
        X[i] = 0;
    }

    // P
    while(act != P) {

        while (C[j] > (P - act) && (j > 0))
        {
            j--;
        }

        if(j == 0) {
            std::cout<<"No existe solución"<<endl;
            return;
        }

        X[j] = floor((P - act) / C[j]);
        act = act + C[j]*X[j];

    }

}
*/
int main() {

    return 0;
}