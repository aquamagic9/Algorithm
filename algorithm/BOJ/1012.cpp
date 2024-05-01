#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int visited = 2;
int result = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(vector<vector<int>> &arr, pair<int, int> pos)
{
    if (arr[pos.second][pos.first] != 1){
        return ;
    }
    result++;
    queue<pair<int, int>> q;
    q.push(pos);
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        arr[y][x] = visited;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < arr[0].size() && ny >= 0 && ny < arr.size() && arr[ny][nx] == 1){
                q.push(make_pair(nx, ny));
                arr[ny][nx] = visited;
            }
        }
    }
}

int main()
{
    int testCase;

    cin >> testCase;
    for (int t = 1; t <= testCase; t++)
    {
        int M, N, K;

        cin >> M >> N >> K;
        vector<vector<int>> map;
        for (int i = 0; i < N; i++)
        {
            vector<int> row(M, 0);
            map.push_back(row);
        }
        vector<pair<int, int>> poses;
        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            poses.push_back(make_pair(x, y));
            map[y][x] = 1;
        }

        result = 0;
        for(pair p : poses){
            bfs(map, p);
        }

        cout << result << "\n";
    }

    return 0;
}