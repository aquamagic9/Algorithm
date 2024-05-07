#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,0,-1};
int map[51][51];
int visited[51][51];
int N, L, R, cnt = 0;
vector<pair<int, int>> poses;

bool condition(int a, int b){
    int diff = abs(a - b);
    if (diff >= L && diff <= R){
        return true;
    }
    return false;
}

bool canTie(pair<int, int> pos)
{
    int x = pos.first;
    int y = pos.second;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] == 0 && condition(map[y][x], map[ny][nx])){
            return true;
        }
    }
    return false;
}

int bfs(pair<int, int> pos)
{
    int sum = 0;
    queue<pair<int, int>> q;

    sum += map[pos.second][pos.first];
    q.push(pos);
    visited[pos.second][pos.first] = 1;
    cnt++;
    poses.clear();
    poses.push_back(pos);
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] == 0 && condition(map[y][x], map[ny][nx])){
                q.push(make_pair(nx, ny));
                poses.push_back(make_pair(nx, ny));
                visited[ny][nx] = 1;
                cnt++;
                sum += map[ny][nx];
            }
        }
    }

    return sum / cnt;
}

int main()
{
    int result = -1;

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    bool check = true;
    while (check)
    {
        result++;
        check = false;
        memset(visited, 0, sizeof(int) * 51 * 51);
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j] == 0 && canTie(make_pair(j, i))){
                    cnt = 0;
                    int avg = bfs(make_pair(j, i));
                    check = true;
                    for(const auto &pos : poses){
                        map[pos.second][pos.first] = avg;
                    }
                }
            }
        }
    }
    cout << result;

    return 0;
}