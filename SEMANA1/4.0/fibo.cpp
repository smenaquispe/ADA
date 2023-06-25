#include<iostream>
using namespace std;

unsigned long fibo(unsigned n)
{
    if( n < 2 )
        return 1;
    unsigned long f1 = 0, f2 = 1;
    unsigned long output;
    do
    {
        output = f1 + f2;
        f1 = f2;
        f2 = output;
    } while(--n >= 2);

    return output;
}

int main() {

    cout<<fibo(70);
    return 0;
}