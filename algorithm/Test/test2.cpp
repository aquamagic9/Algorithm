#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1,0};
int dy[4] = {0, 1, 0, -1};

int boardSize;
vector<vector<int>> visit;

void resetVisit() {
    for (auto& row : visit){
        fill(row.begin(), row.end(), 0);
    }
}

bool bfsHorizontal(const vector<vector<int>> &board, pair<int, int> pos, int type)
{
    resetVisit();
    queue<pair<int, int>> q;
    q.push(pos);
    visit[pos.second][pos.first] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i+= 2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[ny][nx] == type && visit[ny][nx] == 0)
            {
                visit[ny][nx] = 1;
                cnt++;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if (cnt >= 3){
        cout << "horizontal: "<<pos.first << " " << pos.second << " " << cnt << endl;
        return true;
    }
    return false;
}

bool bfsVertical(const vector<vector<int>> &board, pair<int, int> pos, int type)
{
    resetVisit();
    queue<pair<int, int>> q;
    q.push(pos);
    visit[pos.second][pos.first] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 1; i < 4; i+= 2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[ny][nx] == type && visit[ny][nx] == 0)
            {
                visit[ny][nx] = 1;
                cnt++;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if (cnt >= 3){
        cout << "vertical: "<< pos.first << " " << pos.second << " " << cnt << endl;
        return true;
    }
    return false;
}

void swap(int &a, int &b)
{
    int tmp =a;
    a = b;
    b = tmp;
}
int solution(vector<vector<int>> board)
{
    int answer = -1;
    int count = 0;

    boardSize = board.size();
    vector<vector<int>> v;
    visit = v;
    for (int i = 0; i < boardSize; i++){
        vector<int> row(boardSize);
        visit.push_back(row);
    }
    for (int y = 0; y < boardSize; y++){
        for (int x = 0; x < boardSize; x++){
            for (int i =0;i < 2; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < boardSize && ny < boardSize)
                {
                    swap(board[ny][nx], board[y][x]);
                    if (bfsHorizontal(board, make_pair(nx, ny), board[ny][nx])
                        || bfsVertical(board, make_pair(nx, ny), board[ny][nx])
                        || bfsHorizontal(board, make_pair(x, y), board[y][x])
                        || bfsVertical(board, make_pair(x, y), board[y][x]))
                        count++;
                    swap(board[ny][nx], board[y][x]);
                }
            }
        }
    }
    if (count > 0){
        answer = count;
    }
    return answer;
}
int main()
{
    int arr[4][4] = {{1, 1, 2, 3},
                     {2, 3, 2, 3},
                     {1, 1, 4, 2},
                     {4, 2, 3, 1}};
    vector<vector<int>> v;
    for (int i = 0;i < 4; i++){
        vector<int> row;
        for (int j = 0; j < 4; j++){
            row.push_back(arr[i][j]);
        }
        v.push_back(row);
    }
    cout << solution(v);
    return 0;
}