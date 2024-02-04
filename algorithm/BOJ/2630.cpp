#include <iostream>
#include <vector>
using namespace std;

void CutArray(vector<vector<int>> &arr, int ax, int ay, int bx, int by);
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
    if (ax == bx && ay == by)
    {
        if (arr[ay][ax] == 1)
            blueCnt++;
        else
            whiteCnt++;
        return;
    }
    int length = bx - ax;
    CutArray(arr, 0, 0, length / 2, length / 2);
    CutArray(arr, length / 2 + 1, 0, bx, length / 2);
    CutArray(arr, 0, length / 2 + 1, length / 2, by);
    CutArray(arr, length / 2, length / 2, bx, by);
}
