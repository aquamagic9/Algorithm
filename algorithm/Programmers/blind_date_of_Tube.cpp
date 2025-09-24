#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int x;
    int y;
    long long sum;
    int moveCnt;
};

bool boundary(int m, int n, int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    int maxInt = 2147483647;
    vector<int> answer = {maxInt, maxInt};
    queue<Point> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<long long> r(n, maxInt);
    vector<vector<long long>> dp(m, r);
    dp[0][0] = 0;

    q.push({0,0,0, 0});
    while (!q.empty()){
        Point p = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (boundary(m, n, x, y) && time_map[y][x] != -1 && time_map[y][x] + p.sum <= s && dp[y][x] > time_map[y][x] + p.sum){
                if (x == n - 1 && y == m - 1){
                    answer[0] = answer[0] > p.moveCnt + 1 ? p.moveCnt + 1 : answer[0];
                    answer[1] = answer[0] == p.moveCnt + 1 && answer[1] > p.sum ? p.sum : answer[1];
                    dp[y][x] = answer[1];
                    continue;
                }
                dp[y][x] = time_map[y][x] + p.sum;
                q.push({x, y, dp[y][x], p.moveCnt + 1});
            }
        }
    }

    return answer;
}

int main()
{
    int m = 3, n = 3, s = 150;
    vector<vector<int>> time_map = {{0, 2, 99}, {100, 100, 4}, {1, 2, 0}};

    solution(m, n, s, time_map);

    return 0;
}