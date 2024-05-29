#include <iostream>
#include <queue>
using namespace std;

bool inline isWall(int a, int bit){
    return a & 1 << bit;
}
int N, M, maxCnt = 0, roomCnt = 0;
int map[51][51];
int visit[51][51];
int dx[4] = {-1, 0,1,0};
int dy[4] = {0,1,0, -1};

int bfs(pair<int, int> pos)
{
    queue<pair<int, int>> q;
    q.push(pos);
    visit[pos.second][pos.first] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && visit[ny][nx] == 0 && !isWall(visit[y][x], i)){
                q.push({nx, ny});
                visit[ny][nx] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for(int y = 0; y < M; y++){
        for (int x = 0; x < N; x++){
            cin >> map[y][x];
        }
    }

    for(int y = 0; y < M; y++){
        for (int x = 0; x < N; x++){
            if (visit[y][x] == 0){
                roomCnt++;
                maxCnt = max(maxCnt, bfs({x, y}));
            }
        }
    }

    return 0;
}