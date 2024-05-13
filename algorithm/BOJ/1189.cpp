#include <iostream>
using namespace std;
int R, C, K, cnt = 0;
string map[5];
int visit[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(pair<int, int> pos, int distance)
{
    int x = pos.first;
    int y = pos.second;
    if (x == C - 1 && y == 0 && distance == K){
        cnt++;
        return ;
    }
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] == '.' && visit[ny][nx] == 0){
            visit[ny][nx] = 1;
            dfs(make_pair(nx, ny), distance + 1);
            visit[ny][nx] = 0;
        }
    }
}
int main()
{
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++){
        cin >> map[i];
    }

    visit[R - 1][0] = 1;
    dfs({0,R - 1}, 1);
    cout << cnt;

    return 0;
}