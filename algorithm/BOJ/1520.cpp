#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N, M;

    cin >> M >> N;
    vector<vector<int>> v, visit;
    for (int i = 0; i < M; i++)
    {
        vector<int> tmp(N, 0);
        visit.push_back(tmp);
        for (int j = 0; j < N; j++)
        {
            cin >> tmp[j];
        }
        v.push_back(tmp);
    }

    stack<pair<int, int>> stk;
    stk.push(make_pair(0,0));
    visit[0][0] = 1;
    while(!stk.empty())
    {
        pair<int, int> value = stk.top();
        stk.pop();
        int y = value.first;
        int x = value.second;
        if (y - 1 >= 0 && v[y][x] > v[y - 1][x] && visit[y - 1][x] == 0)
        {
            stk.push(make_pair(y - 1, x));
            visit[y - 1][x] = 1;
        }
        if (x - 1 >= 0 && v[y][x] > v[y][x - 1] && visit[y][x - 1] == 0)
        {
            stk.push(make_pair(y, x - 1));
            visit[y][x - 1] = 1;
        }
        if (y + 1 < M && v[y][x] > v[y + 1][x] && visit[y + 1][x] == 0)
        {
            stk.push(make_pair(y + 1, x));
            visit[y + 1][x] = 1;
        }
        if (x + 1 < N && v[y][x] > v[y][x + 1] && visit[y][x + 1] == 0)
        {
            stk.push(make_pair(y, x + 1));
            visit[y][x + 1] = 1;
        }
    }


    return 0;
}