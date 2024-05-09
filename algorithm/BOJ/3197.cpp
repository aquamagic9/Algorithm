#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[1501][1501];
int visit[1501][1501];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1, 0};
int R, C;

int bfs(pair<int, int> pos)
{
    queue<pair<int, int>> q;

    q.push({pos.first, pos.second});
    visit[pos.second][pos.first] = 1;

    int cnt = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (map[y][x] == 'L'){
            cnt++;
        }
        else if (map[y][x] == 'X'){
            map[y][x] = '.';
            visit[y][x]= 1;
            continue;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && visit[ny][nx] == 0){
                q.push({nx, ny});
                visit[ny][nx] = 1;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }

    bool check = true;
    int result = 0;
    while (check){
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if ((map[i][j] == '.' || map[i][j] == 'L') && visit[i][j] == 0){
                    int cnt = bfs({j, i});
                    if (cnt == 2){
                        check = false;
                    }
                }
            }
        }
        result++;
    }
    cout << result - 1;

    return 0;
}