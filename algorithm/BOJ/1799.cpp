#include <iostream>
using namespace std;

int mapSize, maxCnt = 0;
int map[10][10];

void visitMap(int x, int y)
{
    map[y][x] = 0;
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {-1,1,-1, 1};
    int nx, ny;
    for (int i = 1; i <= 10; i++){
        for (int j = 0; j < 4; j++){
            nx = x + i * dx[j];
            ny = y + i * dy[j];
            if (nx >= 0 && ny >= 0 && ny < mapSize && nx < mapSize && map[ny][nx] == 1){
                map[ny][nx] = 0;
            }
        }
    }
}

void backTracking(pair<int, int> pos, int cnt)
{
    maxCnt = max(maxCnt, cnt);
    int newMap[10][10];
    copy(&map[0][0], &map[0][0] + 100, &newMap[0][0]);

    int x = pos.first;
    int y = pos.second;
    for (int i = y; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            if (i == y && j < x)
                continue;
            if (map[i][j] == 1){
                visitMap(j, i);
                backTracking({j, i}, cnt + 1);
                copy(&newMap[0][0], &newMap[0][0] + 100, &map[0][0]);
            }
        }
    }
}

int main()
{
    cin >> mapSize;
    for (int i = 0; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            cin >> map[i][j];
        }
    }
    backTracking({0, 0}, 0);
    cout << maxCnt;

    return 0;
}