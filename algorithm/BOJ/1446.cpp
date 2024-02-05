#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ShortPass{
public:
    int startPos;
    int endPos;
    int distance;
    ShortPass(int startPos, int endPos, int distance)
    {
        this->startPos = startPos;
        this->endPos = endPos;
        this->distance = distance;
    }
};

bool CompareRoutes(ShortPass a, ShortPass b)
{
    if (a.startPos < b.startPos)
        return true;
    if (a.endPos < b.endPos)
        return true;
    if (a.distance < b.distance)
        return true;
    return false;
}

int main()
{
    int N, D;

    cin >> N >> D;
    vector<ShortPass> routes;
    for (int i = 0; i < N; i++)
    {
        ShortPass route(0,0,0);
        cin >> route.startPos >> route.endPos >> route.distance;
        routes.push_back(route);
    }
    sort(routes.begin(), routes.end(), CompareRoutes);


    return 0;
}