#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visit[1001][1001];
vector<string> map;

int findDirectionIndex(char c)
{
    switch (c) {
        case 'D':
            return 0;
        case 'R':
            return 1;
        case 'U':
            return 2;
        case 'L':
            return 3;
        default:
            break;
    }
    return -1;
}

void bfs(pair<int, int> pos)
{
    queue<pair<int, int>> q;
    q.push(pos);
    visit[pos.second][pos.first] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nx = x + dx[findDirectionIndex(map[y][x])];
        int ny = y + dy[findDirectionIndex(map[y][x])];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && visit[ny][nx] == 0){
            q.push({nx, ny});
            visit[ny][nx] = 1;
        }
        for (int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visit[ny][nx] == 0 && findDirectionIndex(map[ny][nx]) == (i + 2) % 4){
                q.push({nx, ny});
                visit[ny][nx] = 1;
            }
        }
    }
}

int main()
{
    int result = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string row;
        cin >> row;
        map.push_back(row);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (visit[i][j] == 0){
                bfs({j, i});
                result++;
            }
        }
    }
    cout << result;

    return 0;
}