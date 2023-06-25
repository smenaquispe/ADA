#include<iostream>
using namespace std;

long powerNumber(int base, int exp) {
    
    // caso base para todoo exponenete igual a cero
    if(exp == 0) return 1;

    int mitad = exp / 2;
    long res = powerNumber(base, mitad); // llamamos recursivamente a la base, con un exponente dividio a la mitad

    // si es par, solo devolvemos el resultado al cuadrado
    if(exp % 2 == 0) return res * res; 
    // si no, lo devolvemos multiplicado por la base misma
    else return base * res * res;

} 

int main() {

    cout<<powerNumber(2, 3)<<endl;
    return 0;
}