#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, 1, 0,-1};

void bfs(vector<vector<int>> &visitMap, pair<int, int> pos)
{
    queue<pair<int, int>> q;
    q.push(pos);
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visitMap[y][x] = 0;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < visitMap.size() && ny >= 0 && ny < visitMap.size() && visitMap[ny][nx] != 0){
                q.push(make_pair(nx, ny));
                visitMap[ny][nx] = 0;
            }
        }
    }
}

int findSafeZone(const vector<vector<int>> &map, int height)
{
    int N = map.size();
    int cnt = 0;

    vector<vector<int>> visitMap;
    for (int i = 0; i < N; i++){
        vector<int> row(N, 0);
        for (int j = 0; j < N; j++){
            row[j] = max(0, map[i][j] - height);
        }
        visitMap.push_back(row);
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (visitMap[i][j] != 0){
                bfs(visitMap, make_pair(j, i));
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int N, maxHeight = 0, result = 0;

    cin >> N;
    vector<vector<int>> map;
    for (int i = 0; i < N; i++){
        vector<int> row(N);
        for (int j = 0; j < N; j++){
            cin >> row[j];
            maxHeight = max(maxHeight, row[j]);
        }
        map.push_back(row);
    }
    for (int h = 0; h < maxHeight; h++){
        result = max(result, findSafeZone(map, h));
    }
    cout << result;

    return 0;
}