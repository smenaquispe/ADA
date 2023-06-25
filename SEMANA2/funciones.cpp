#include<iostream>
using namespace std;

void funcion1(int N) {

    int c = 0;
    
    for(int i = 0; i <= N; i++) {
        c++;
        if(i % 2 == 0) {
            c++;
            cout<<i<<" ";
        }
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;
}

void funcion2(int N) {
    int c = 0;

    for(int i = 0; i <= N; i++) {
        c++;
        for(int j = i; j <= N; j++) {
            c++;
            cout<<i<<" , "<<j<<endl;
            c++;
        }
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;
}

template<int lenA, int lenB>
void funcion3(int A[lenA], int B[lenB]) {

    int c = 0;

    for(int i = 0; i < lenA; i++) {
        c++;
        for(int j = 0; j < lenB; j++) {
            c++;
            cout<<A[i]<<" , "<<B[j]<<endl;
            c++;
        }
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;

}

void funcion4(int N) {

    int c = 0;

    for(int i = 0; i <= N; i++) {
        c++;
        int j = 1;
        c++;
        while (j < N)
        {
            c++;
            cout<<j<<" ";
            c++;
            j *= 2;
            c++;
        }
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;
}

void funcion5(int N) {

    int c = 0;

    for(int i = 0; i <= N; i++) {
        c++;
        if(i % 2 == 0) {
            c++;
            cout<<i<<" ";
        }
        c++;
    }
    c++;


    for(int i = 0; i <= N; i++) {
        c++;
        if(i % 2 != 0) {
            c++;
            cout<<i<<" ";
        }
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;
}

void funcion6(int N) {
    int c = 0;

    int i = 1;
    c++;

    while (i < N)
    {
        c++;
        cout<<i<<" ";
        c++;
        i *= 2;
        c++;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;    
}

void funcion7() {
    
    int c = 0;

    int N = 1000;
    c++;

    c++;
    if(N % 2 == 0) {
        c++;
        cout<<"Par"<<endl;
    }

    else {
        c++;
        cout<<"Impar"<<endl;
    }
    c++;

    cout<<endl<<"contador: "<<c<<endl;    

}

int main() {

    //funcion1(5);
    //funcion2(6);

    /*
    int a[3] = {1,2,3};
    int b[2] = {1,2};

    funcion3<3,2>(a,b);
    */

    //funcion4(9);

    //funcion5(5);
    //funcion6(6);
    funcion7();

    return 0;
}