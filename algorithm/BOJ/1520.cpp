#include <iostream>
#include <vector>
using namespace std;

int dfs(int x, int y);

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<vector<int>> v, dp;
int N, M;
int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        vector<int> tmp(N, -1);
        dp.push_back(tmp);
        for (int j = 0; j < N; j++)
        {
            cin >> tmp[j];
        }
        v.push_back(tmp);
    }
    cout << dfs(N - 1, M - 1);

    return 0;
}

int dfs(int x, int y)
{
    if (dp[y][x] != -1)
        return dp[y][x];
    if (x == 0 && y == 0)
        return 1;
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && v[ny][nx] > v[y][x])
        {
            dp[y][x] += dfs(nx, ny);
        }
    }

    return dp[y][x];
}