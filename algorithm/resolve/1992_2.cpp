#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool madeByOneChar(vector<vector<int>> &arr, int size, int y, int x)
{
    int type = arr[y][x];
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            if (arr[i][j] != type){
                return false;
            }
        }
    }
    cout << arr[y][x];
    return true;
}

void recursion(vector<vector<int>> &arr, int size, int y, int x)
{
    if (size == 1){
        cout << arr[y][x];
        return;
    }
    int halfSize = size/2;
    cout << "(";
    if (!madeByOneChar(arr, halfSize, y, x))
        recursion(arr, halfSize, y, x);
    if (!madeByOneChar(arr, halfSize, y, x + halfSize))
        recursion(arr, halfSize, y, x + halfSize);
    if (!madeByOneChar(arr, halfSize, y + halfSize, x))
        recursion(arr, halfSize, y + halfSize, x);
    if (!madeByOneChar(arr, halfSize, y + halfSize, x + halfSize))
        recursion(arr, halfSize, y + halfSize, x + halfSize);
    cout << ")";
}

int main()
{
    int N;
    vector<vector<int>> arr;

    cin >> N;
    for (int i = 0; i < N; i++){
        string row;
        cin >> row;
        vector<int> tmp;
        for (int j = 0; j < row.size(); j++){
            tmp.push_back(row[j] - '0');
        }
        arr.push_back(tmp);
    }

    if (!madeByOneChar(arr, N, 0, 0))
        recursion(arr, N, 0, 0);

    return 0;
}