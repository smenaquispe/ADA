#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

struct Point
{
    int x, y;
};


float getDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void minDistance() {

    int n;
    cin>>n;

    vector<Point> points;

    while (n != 0)
    {
        int x, y;
        for(int i = 0; i < n; i++) {
            cin>>x>>y;
            points.push_back({x,y});
        }

        float menor = -1;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                float distance = getDistance(points[i], points[j]);
                if(menor == -1 || distance < menor) {
                    menor = distance;
                }
            }
        }

        if(menor >= 10000) {
            cout<<"INFINITY"<<endl;
        } else {
            cout<< fixed << setprecision(4) << menor<<endl;
        }

        cin>>n;
        points.clear();
    }
    
}

int main() {

    minDistance();

    return 0;
}
