#include<iostream>
using namespace std;

// Class CVector definition
class CArithmetic
{
    private:
    // Some attributes go here
    public:

        static double Addition(double a, double b) { return a + b; }
        static double Subtraction(double a, double b) { return a - b; } 
        static double Multiplication(double a, double b) { return a * b; } 
        static double Division(double a, double b) { 
            if ( b == 0.0 )
                throw (int)0; // an exceptions is thrown here
            return a/b;
        } 
    // More methods go here
};

int main() {

    double x = 6, y = 0, z;
    try {
        z = CArithmetic::Division(x, y);
        cout<<z<<endl;
    } catch(int errorCode) {
        cout<<errorCode<<endl;
    }
    return 0;
}