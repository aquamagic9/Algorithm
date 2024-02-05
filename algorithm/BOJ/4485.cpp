#include <iostream>
#include <vector>
#define MAX 125*125*10
using namespace std;
vector<vector<int>> CreateArr(int N);
void FindShortValue(vector<vector<int>> &v, int N);
int cnt = 1;
int main()
{
    int N = 1;

    while (N != 0)
    {
        cin >> N;
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
        vector<int> tmp(N, 0);
        visitValueArr.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                visitValueArr[i][j] = v[i][j];
                continue;
            }
            int leftValue = MAX, upValue = MAX;
            if (j - 1 >= 0){
                leftValue = visitValueArr[i][j - 1];
            }
            if (i - 1 >= 0){
                upValue = visitValueArr[i - 1][j];
            }
            if (leftValue < upValue){
                visitValueArr[i][j] = v[i][j] + leftValue;
            }
            else {
                visitValueArr[i][j] = v[i][j] + upValue;
            }
        }
    }
    cout << "Problem " << cnt << ": " << visitValueArr[N - 1][N - 1] << '\n';
}
