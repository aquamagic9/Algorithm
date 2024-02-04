#include <iostream>
#include <vector>
using namespace std;

void CutArray(vector<vector<int>> &arr, int ax, int ay, int bx, int by);
bool CheckArr(vector<vector<int>> &arr, int ax, int ay, int bx, int by);
int blueCnt = 0;
int whiteCnt = 0;

int main()
{
    int N;

    cin >> N;
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        vector<int> tmp(N, 0);
        for (int j = 0; j < N; j++) {
            cin >> tmp[j];
        }
        arr[i] = tmp;
    }
    CutArray(arr, 0, 0, N - 1, N - 1);
    cout << whiteCnt << '\n' << blueCnt;

    return 0;
}

void CutArray(vector<vector<int>> &arr, int ax, int ay, int bx, int by)
{
    if (ax == bx && ay == by || CheckArr(arr, ax, ay, bx, by))
    {
        if (arr[ay][ax] == 1)
            blueCnt++;
        else
            whiteCnt++;
        return;
    }
    int length = (bx - ax) / 2;
    CutArray(arr, ax, ay, ax + length, ay + length);
    CutArray(arr, ax + length + 1, ay, bx, ay + length);
    CutArray(arr, ax, ay + length + 1, ax + length, by);
    CutArray(arr, ax + length + 1, ay + length + 1, bx, by);
}

bool CheckArr(vector<vector<int>> &arr, int ax, int ay, int bx, int by)
{
    int color = arr[ay][ax];
    for (int i = ay; i <= by; i++)
    {
        for (int j = ax; j <= bx; j++)
        {
            if (color != arr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}