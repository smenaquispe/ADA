#include<iostream>

void Mochila(int M, int p[], int x[], int n) {
    for(int i = 0; i < n; i++) {
        X[i] = 0;
    }

    int pesoAct = 0;
    while (pesoAct < M)
    {
        int i; // el mejor objeto restante

        if(pesoAct + p[i] <= M) {
            X[i] = 1;
            pesoAct += p[i];
        } else {
            X[i] = (M - pesoAct) / p[i];
            pesoAct = M;
        }
    }
    
}

int main() {


    return 0;
}