#include<iostream>
using namespace std;

int main() {

    int T;
    cin>>T;

    for(int i = 0; i < T; i++){
        int N;
        cin>>N;

        int coins[N];
        for(int j = 0; j < N; j++) {
            cin>>coins[j];
        }

        int biggest = coins[0];
        int numCoins = 1;

        for(int j = 1; j < N - 1; j++){
            if(biggest + coins[j] < coins[j + 1]) {
                biggest += coins[j];
                numCoins++;
            }
        }

        numCoins++;
        cout<<numCoins<<endl;
    }

    return 0;
}