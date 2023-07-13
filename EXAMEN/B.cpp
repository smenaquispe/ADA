#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cfloat>
using namespace std;

struct Point
{
    int x, y;
};

bool compareX(Point a, Point b)
{
    return a.x < b.x;
}

bool compareY(Point a, Point b)
{
    return a.y < b.y;
}

float getDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

float stripClosest(vector<Point>& strip, float d)
{
    float minDistance = d;

    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDistance; ++j)
        {
            float distance = getDistance(strip[i], strip[j]);
            minDistance = min(minDistance, distance);
        }
    }

    return minDistance;
}

float closestUtil(vector<Point>& points, int left, int right)
{
    if (right - left <= 3)
    {
        float minDistance = FLT_MAX;
        for (int i = left; i <= right; ++i)
        {
            for (int j = i + 1; j <= right; ++j)
            {
                float distance = getDistance(points[i], points[j]);
                minDistance = min(minDistance, distance);
            }
        }
        return minDistance;
    }

    int mid = (left + right) / 2;
    Point midPoint = points[mid];

    float leftDistance = closestUtil(points, left, mid);
    float rightDistance = closestUtil(points, mid + 1, right);
    float minDistance = min(leftDistance, rightDistance);

    vector<Point> strip;
    for (int i = left; i <= right; ++i)
    {
        if (abs(points[i].x - midPoint.x) < minDistance)
        {
            strip.push_back(points[i]);
        }
    }

    float stripDistance = stripClosest(strip, minDistance);
    return min(minDistance, stripDistance);
}

float closestPair(vector<Point>& points)
{
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    while (n != 0)
    {
        vector<Point> points(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].x >> points[i].y;
        }

        float minDistance = closestPair(points);

        if (minDistance >= 10000)
        {
            cout << "INFINITY" << endl;
        }
        else
        {
            cout << fixed << setprecision(4) << minDistance << endl;
        }

        points.clear();
        cin >> n;
    }
    

    return 0;
}
