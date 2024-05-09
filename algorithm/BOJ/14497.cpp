#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> map;
vector<vector<int>> visit;
pair<int, int> myPos;
pair<int, int> enemyPos;
int dx[4] = {0 , 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M, cnt = 0;

bool bfs()
{
    queue<pair<int, int>> q;

    q.push(myPos);
    visit[myPos.second][myPos.first] = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (map[y][x] == '1'){
            map[y][x] = '0';
            visit[y][x] = 1;
            continue;
        }
        else if (map[y][x] == '#'){
            return true;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && visit[ny][nx] == 0){
                q.push({nx, ny});
                visit[ny][nx] = 1;
            }
        }
    }
    return false;
}
int main()
{
    cin >> N >> M;
    cin >> myPos.second >> myPos.first >> enemyPos.second >> enemyPos.first;
    myPos = {myPos.first - 1, myPos.second - 1};
    enemyPos = {enemyPos.first - 1, enemyPos.second - 1};

    for (int i = 0; i < N; i++){
        vector<int> vRow(M, 0);
        string row;
        cin >> row;
        map.push_back(row);
        visit.push_back(vRow);
    }

    cnt = 1;
    while (!bfs()){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                visit[i][j] = 0;
            }
        }
        cnt++;
    }
    cout << cnt;

    return 0;
}