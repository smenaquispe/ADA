#include<iostream>
#include<vector>
using namespace std;

void existeIndice(vector<int> & vec, int & indice) {
    if(vec.size() == 0) return;
    if(vec[indice] == indice) {
        cout<<"Si existe un indice "<<indice<<" tal que X["<<indice<<"] = "<<vec[indice]<<endl;
    }
    return existeIndice(vec, ++indice);
}

int main() {

    vector<int> vec = {1,1,2,5,7,8,9};

    int indice = 0;    
    existeIndice(vec, indice);
    
    return 0;
}