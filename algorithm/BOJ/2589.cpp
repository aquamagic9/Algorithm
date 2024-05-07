#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

char map[51][51];
const char land = 'L';
const char ocean = 'W';
int visited[51][51];
int N, M, result, maxDistance = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> point;

void bfs(pair<int, int> pos)
{
    memset(visited, -1, sizeof(int) * 51 * 51);
    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.second][pos.first] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        bool check = false;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && visited[ny][nx] == -1 && map[ny][nx] == land){
                check = true;
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(nx, ny));
            }
        }
        if (!check && maxDistance < visited[y][x]){
            maxDistance = visited[y][x];
            point.push_back(make_pair(x, y));
        }
    }
}

int main()
{
    cin >> N >> M;
    result = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (map[i][j] == land){
                maxDistance = 0;
                bfs(make_pair(j, i));
                result = max(result, maxDistance);
            }
        }
    }
    cout << result;

    return 0;
}
/*
input:
5 9
LLLLLLLLL
LWWWLWWWL
LWWWLWWWL
LWWWLWWWL
LLLLLLLLW

answer: 15
 */