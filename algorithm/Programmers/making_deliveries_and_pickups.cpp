#include <iostream>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    int d = 0, p = 0;
    for (int i = n - 1; i >= 0; i--){
        int cnt = 0;
        d -= deliveries[i];
        p -= pickups[i];
        while (d < 0 || p < 0){
            d += cap;
            p += cap;
            cnt++;
        }
        answer += (i + 1) * 2 * cnt;
    }

    return answer;
}

int main()
{
    //int cap = 4, n = 5;
    //vector<int> deliveries = {1, 0, 3, 1, 2};
    //vector<int> pickups = {0, 3, 0, 4, 0};
    int cap  = 2, n = 7;
    vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
    vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};

    cout << solution(cap, n, deliveries, pickups);

    return 0;
}