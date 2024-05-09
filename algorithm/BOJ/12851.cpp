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
        if (p + 1 <= 100000 && (dp[p + 1] == 0 || dp[p + 1] >= time + 1)){
            dp[p + 1] = time + 1;
            q.push({p + 1, time + 1});
        }
        if (p - 1 >= 0 && (dp[p - 1] == 0 || dp[p - 1] >= time + 1)){
            dp[p - 1] = time + 1;
            q.push({p - 1, time + 1});
        }
        if (p * 2 <= 100000 && (dp[p * 2] == 0 || dp[p * 2] >= time + 1)){
            dp[p * 2] = time + 1;
            q.push({p * 2, time + 1});
        }
    }
    cout << result << "\n" << cnt;

    return 0;
}