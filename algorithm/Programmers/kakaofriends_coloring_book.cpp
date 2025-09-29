#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, k;
};

bool boundary(int n, int m, int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int m, int n, int x, int y, vector<vector<int>> &picture){
    int cnt = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    queue<Point> q;

    q.push({x, y, picture[y][x]});
    picture[y][x] = -1;
    while (!q.empty()){
        Point p = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < 4; i++){
            int px = p.x + dx[i], py = p.y + dy[i];
            if (boundary(n, m, px, py) && picture[py][px] != 0 && picture[py][px] == p.k){
                q.push({px, py, p.k});
                picture[py][px] = -1;
            }
        }
    }

    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);

    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            if (picture[y][x] != -1 && picture[y][x] != 0){
                number_of_area++;
                max_size_of_one_area = max(bfs(m, n, x, y, picture), max_size_of_one_area);
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main()
{
    int m = 6, n = 4;
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    vector<int> answer = solution(m, n, picture);
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}