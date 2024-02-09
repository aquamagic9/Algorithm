#include <iostream>
#include <vector>
#include <queue>
#define MAX 125*125*10
using namespace std;
vector<vector<int>> CreateArr(int N);
void FindShortValue(vector<vector<int>> &v, int N);
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int cnt = 1;
int main()
{
    int N = 1;

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        vector<vector<int>> v = CreateArr(N);
        FindShortValue(v, N);
        cnt++;
    }
    return 0;
}

vector<vector<int>> CreateArr(int N)
{
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        vector<int> tmp(N);
        for (int j = 0; j < N; j++)
        {
            cin >> tmp[j];
        }
        v.push_back(tmp);
    }
    return v;
}

void FindShortValue(vector<vector<int>> &v, int N)
{
    vector<vector<int>> visitValueArr;
    for (int i = 0; i < N; i++)
    {
        vector<int> tmp(N, MAX);
        visitValueArr.push_back(tmp);
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visitValueArr[0][0] = v[0][0];
    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (visitValueArr[ny][nx] > visitValueArr[y][x] + v[ny][nx])
                {
                    visitValueArr[ny][nx] = visitValueArr[y][x] + v[ny][nx];
                    q.push(make_pair(ny, nx));
                }

            }
        }
    }
    cout << "Problem " << cnt << ": " << visitValueArr[N - 1][N - 1] << '\n';
}
