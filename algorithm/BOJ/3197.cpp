#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[1501][1501];
int visit[1501][1501], swanVisit[1501][1501];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1, 0};
int R, C, lx, ly;
queue<pair<int, int>> newSwanQ, swanQ, newWaterQ, waterQ;

void Qclear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q,empty);
}

void bfsWater()
{
    while (!waterQ.empty())
    {
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        waterQ.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && visit[ny][nx] == 0 && map[ny][nx] == 'X'){
                newWaterQ.push({nx, ny});
                visit[ny][nx] = 1;
                map[ny][nx] = '.';
            }
        }
    }
}

bool bfsSwanMove(){
    while (!swanQ.empty())
    {
        int x = swanQ.front().first;
        int y = swanQ.front().second;
        swanQ.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && swanVisit[ny][nx] == 0){
                swanVisit[ny][nx] = 1;
                if (map[ny][nx] == 'X')
                    newSwanQ.push({nx, ny});
                else if (map[ny][nx] == '.')
                    swanQ.push({nx, ny});
                else if (map[ny][nx] == 'L'){
                    return true;
                }
            }
        }
    }
    return false;
}

void printMap()
{
    cout << endl;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> map[i][j];
            if (map[i][j] == 'L'){
               lx = j;
               ly = i;
            }
            if (map[i][j] == 'L' || map[i][j] == '.'){
                waterQ.push({j, i});
                visit[i][j] = 1;
            }
        }
    }

    swanQ.push({lx, ly});
    swanVisit[ly][lx] = 1;
    int cnt = 0;
    while (!bfsSwanMove()){
        bfsWater();

        waterQ = newWaterQ;
        Qclear(newWaterQ);
        swanQ = newSwanQ;
        Qclear(newSwanQ);

        cnt++;
    }
    cout << cnt;

    return 0;
}