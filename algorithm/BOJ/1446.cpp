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

int main()
{
    int N, D;

    cin >> N >> D;
    vector<ShortPass> routes;
    for (int i = 0; i < N; i++)
    {
        ShortPass route(0,0,0);
        cin >> route.startPos >> route.endPos >> route.distance;
        if (route.endPos - route.startPos <= route.distance || route.startPos < 0 || route.endPos > D){
            continue;
        }
        routes.push_back(route);
    }
    vector<int> dp(D + 1);
    for (int i = 0; i < D + 1; i++){
        dp[i] = i;
    }
    for (int i = 0; i < D + 1; i++){
        if (i > 0)
            dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 0; j < routes.size(); j++) {
            if (routes[j].startPos == i){
                dp[routes[j].endPos] = min(dp[routes[j].endPos], dp[routes[j].startPos] + routes[j].distance);
            }
        }
    }
    cout << dp[D];

    return 0;
}