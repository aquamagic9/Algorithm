#include <iostream>
using namespace std;

char map[21][21];
int visit[21][21];
int bigAlpha[27];
int R, C, maxResult = 0;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int distance)
{
    bigAlpha[map[y][x] - 'A'] = 1;
    visit[y][x] = 1;
    if (distance > maxResult){
        maxResult = distance;
    }
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < C && ny >= 0 && ny < R && visit[ny][nx] == 0 && bigAlpha[map[ny][nx] - 'A'] == 0){
            dfs(nx, ny, distance + 1);
        }
    }
    bigAlpha[map[y][x] - 'A'] = 0;
    visit[y][x] = 0;
}

int main()
{

    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }
    dfs(0,0,1);
    cout << maxResult;

    return 0;
}