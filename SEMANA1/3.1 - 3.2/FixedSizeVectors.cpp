#include<iostream>
using namespace std;

// static vector
int gVect[100];
int gnCount;

void Insert(int elem) {
    if(gnCount < 100)
        gVect[gnCount++] = elem;
}

int main() {

    Insert(5);
    Insert(3);
    Insert(2);

    for(int i = 0; i < gnCount; i++) {
        cout<<gVect[i]<<" ";
    }

    return 0;
}