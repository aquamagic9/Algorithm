#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int visit = 1;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(vector<vector<int>> &map, pair<int, int> pos)
{
    queue<pair<int, int>> q;
    q.push(pos);
    map[q.front().second][q.front().first] = visit;
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < map[0].size() && ny >= 0 && ny < map.size() && map[ny][nx] != visit){
                q.push(make_pair(nx, ny));
                map[ny][nx] = visit;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int M, N, K;

    cin >> M >> N >> K;
    vector<vector<int>> map;
    for (int i = 0; i < M; i++)
    {
        vector<int> row(N, 0);
        map.push_back(row);
    }
    for (int i = 0; i < K; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++){
            for (int y = y1; y < y2; y++){
                map[y][x] = visit;
            }
        }
    }

    vector<int> area;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                area.push_back(bfs(map,make_pair(j, i)));
            }
        }
    }
    sort(area.begin(), area.end());
    cout << area.size() << "\n";
    for (int i = 0; i < area.size(); i++){
        cout << area[i] << " ";
    }

    return 0;
}