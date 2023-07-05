#include<iostream>
#include<vector>
using namespace std;

bool existeIndice(vector<int> & vec, int & indice) {
    if(vec.size() == 0) return 0;
    if(vec[indice] == indice) return 1;
    return existeIndice(vec, ++indice);
}

int main() {

    vector<int> vec = {1,1,2,5,7,8,9};

    int indice = 0;    
    if(existeIndice(vec, indice)) {
        cout<<"Si existe un indice i tal que X[i]"<<endl;
    } else {
        cout<<"No existe un indice i tal que X[i]"<<endl;
    }

    return 0;
}