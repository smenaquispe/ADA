#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Pair
{
    int L, R;
};

bool comparePair(Pair & a, Pair & b) {
    return a.L < b.L;
}

int main() {

    int N;
    cin>>N;

    while (N--)
    {
        
        int M;
        cin>>M; // es un segmento de 0 -> M en x

        int L = 1, R = 1;

        vector<Pair> pairs;

        while (true)
        {
            cin>>L>>R;

            if(L == 0 && R == 0) break;

            pairs.push_back({L, R});
        }

        sort(pairs.begin(), pairs.end(), comparePair);


        int minSegments = 0;
        int currR = 0;
        int maxR = 0;
        int i = 0;

        while (i < pairs.size() && currR < M)
        {
            if(pairs[i].L <= currR) {
                if(pairs[i].R > maxR) {
                    maxR = pairs[i].R;
                    currR = maxR;
                    minSegments++;
                }
                i++;
            } else {
                if(maxR > currR) {
                    currR = maxR;
                    minSegments++;
                } else {
                    break;
                }
            }
        }
        

        if(currR >= M) {
            cout<<minSegments<<endl;
            for(int j = i - 1; j < minSegments + 1; j++) {
                cout<<pairs[j].L<<" "<<pairs[j].R<<endl;
            }
        } else {
            cout<<0<<endl;
        }

    }
    

    return 0;
}