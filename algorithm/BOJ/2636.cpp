#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int cheese = 1;
const int blank = 0;
int result = 0, cheeseCnt = 0, times = 0;

vector<vector<int>> map;
vector<vector<bool>> visit;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){
    queue<pair<int, int>> q;

    q.push(make_pair(0,0));
    visit[q.front().first][q.front().second] = true;
    result = cheeseCnt;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < map[0].size() && ny >= 0 && ny < map.size() && !visit[ny][nx]){
                if (map[ny][nx] == cheese){
                    map[ny][nx] = blank;
                    cheeseCnt--;
                }
                else {
                    q.push(make_pair(nx, ny));
                }
                visit[ny][nx] = true;
            }
        }
    }
}
int main()
{
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        vector<int> row(M);
        vector<bool> visitRow(M, false);
        for (int j = 0; j < M; j++){
            cin >> row[j];
            if (row[j] == cheese){
                cheeseCnt++;
            }
        }
        map.push_back(row);
        visit.push_back(visitRow);
    }

    while (cheeseCnt){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                visit[i][j] = false;
            }
        }
        bfs();
        times++;
    }
    cout << times << "\n" << result;

    return 0;
}