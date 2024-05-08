#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxInt = 2147483647;

int R, C, result = 0;
vector<vector<char>> map;
vector<vector<int>> personMap;
vector<vector<int>> fireMap;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> R >> C;

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pair<int, int> jpos;
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++){
        vector<char> row(C);
        vector<int> pRow(C, 0);
        vector<int> fRow(C, maxInt);
        for (int j = 0; j < C; j++){
            cin >> row[j];
            if (row[j] == 'F'){
                q.push(make_pair(j, i));
                fRow[j] = 1;
            }
            else if (row[j] == 'J'){
                jpos = {j, i};
            }
        }
        map.push_back(row);
        personMap.push_back(pRow);
        fireMap.push_back(fRow);
    }

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] != '#' && fireMap[ny][nx] == maxInt){
                q.push(make_pair(nx, ny));
                fireMap[ny][nx] = fireMap[y][x] + 1;
            }
        }
    }

    q.push(jpos);
    personMap[jpos.second][jpos.first] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == 0 || x == C - 1 || y == 0 || y == R - 1){
            result = personMap[y][x];
            break;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && personMap[ny][nx] == 0 && map[ny][nx] != '#' && fireMap[ny][nx] > personMap[y][x] + 1){
                q.push(make_pair(nx, ny));
                personMap[ny][nx] = personMap[y][x] + 1;
            }
        }
    }

    if (result == 0){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << result;
    }

    return 0;
}