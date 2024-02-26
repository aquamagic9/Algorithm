#include <iostream>
#include <string>
using namespace std;

int arr[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1, -1, 0,0};
int M, N;
bool success = false;

void DFS(int x, int y)
{
    arr[y][x] = -1;
    if (y == M - 1)
        success = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[ny][nx] == 0){
            DFS(nx, ny);
        }
    }
}

int main()
{
    cin >> M >> N;
    string s;
    for (int i = 0; i < M; i++){
        cin >> s;
        for (int j = 0; j < N; j++){
            arr[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < N; i++){
        if (arr[0][i] == 0){
            DFS(i, 0);
            if (success){
                break;
            }
        }
    }
    if (success)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}