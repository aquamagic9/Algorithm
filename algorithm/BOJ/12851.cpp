#include <iostream>
#include <queue>
using namespace std;

int dp[100001];
int result = 214748347;

int main()
{
    int start, end, cnt = 0;

    cin >> start >> end;
    queue<pair<int, int>> q;
    q.push({start, 0});
    while(!q.empty())
    {
        int p = q.front().first;
        int time = q.front().second;
        q.pop();
        if (time > result){
            continue;
        }
        if (p == end){
            dp[end] = time;
            result = time;
            cnt++;
            continue;
        }
        for (int next : {p + 1, p - 1, p * 2}){
            if (next >= 0 && next <= 100000 && (dp[next] == 0 || dp[next] >= time + 1)){
                dp[next] = time + 1;
                q.push({next, time + 1});
            }
        }
    }
    cout << result << "\n" << cnt;

    return 0;
}