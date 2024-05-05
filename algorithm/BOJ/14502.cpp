#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int safe = 0;
const int rock = 1;
const int virus = 2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int result, N, M;
int maxResult = 0;

void bfs(vector<vector<int>> &map, const pair<int, int> &pos){
    queue<pair<int, int>> q;

    q.push(pos);
    map[pos.second][pos.first] = virus;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == safe){
                q.push(make_pair(nx, ny));
                result--;
                map[ny][nx] = virus;
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    vector<vector<int>> map;
    vector<pair<int, int>> safeZone;
    vector<pair<int, int>> virusZone;
    for(int i = 0; i < N; i++){
        vector<int> row(M);
        for (int j = 0; j < M; j++){
            cin >> row[j];
            if (row[j] == 0){
                safeZone.push_back(make_pair(j, i));
            }
            else if (row[j] == 2){
                virusZone.push_back(make_pair(j, i));
            }
        }
        map.push_back(row);
    }

    int size = safeZone.size();
    for (int i = 0; i < size; i++) {
        map[safeZone[i].second][safeZone[i].first] = rock;
        for (int j = i + 1; j < size; j++) {
            map[safeZone[j].second][safeZone[j].first] = rock;
            for (int k = j + 1; k < size; k++) {
                map[safeZone[k].second][safeZone[k].first] = rock;
                vector<vector<int>> visited = map;
                result = safeZone.size() - 3;
                for (int p = 0; p < virusZone.size(); p++){
                    bfs(visited, virusZone[p]);
                }
                maxResult = max(maxResult, result);
                map[safeZone[k].second][safeZone[k].first] = safe;
            }
            map[safeZone[j].second][safeZone[j].first] = safe;
        }
        map[safeZone[i].second][safeZone[i].first] = safe;
    }
    cout << maxResult;

    return 0;
}