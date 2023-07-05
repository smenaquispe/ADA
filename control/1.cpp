#include<iostream>
using namespace std;

// funcion prpuesta por el ejercicio
bool inArray(int x, int ** A, int n) {
    int f, c;
    f = 1;
    c = n - 1;

    while ((f <= n - 1) && (c >= 0))
    {
        if(x < A[f][c])
            c = c - 1;
        else if(x > A[f][c])
            f = f + 1;
        else return 1;
    }
    
    return 0;
}

// mi funcioon hecha con divide y venceras
bool inArrayRecursivo(int x, int **A, int n, int f, int c) {
    if(f == n || c < 0) return 0;
    
    if(x < A[f][c])
        return inArrayRecursivo(x, A, n, f, c - 1);
    else if(x > A[f][c])
        return inArrayRecursivo(x, A, n, f + 1, c);
    else return 1;
}

// funcion solo para declarar la f y c
bool inArrayRecursivo(int x, int **A, int n) {
    int f = 1;
    int c = n - 1;
    return inArrayRecursivo(x, A, n, f, c);
}

int main () {
    
    int n = 3;

    int **A = new int * [n];

    for(int i = 0; i < n; i++) {
        A[i] = new int[n];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = count++;
        }
    }

    cout<<"Array: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }    

    int a = 18;
    if(inArrayRecursivo(a, A, n)) {
        cout<<a<<" esta en array"<<endl;
    } else {
        cout<<a<<" no esta en array"<<endl;
    }

    a = 5;
    if(inArrayRecursivo(a, A, n)) {
        cout<<a<<" esta en array"<<endl;
    } else {
        cout<<a<<" no estan en array"<<endl;
    }

    return 0;
}