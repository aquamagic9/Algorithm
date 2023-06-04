#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool madeByOneType(vector<vector<int>> &arr, int size, int x, int y){
    int type = arr[y][x];
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            if (type != arr[i][j])
                return false;
        }
    }
    cout << arr[y][x];
    return true;
}

void recursion(vector<vector<int>> &arr, int size, int x, int y){
    if (size == 1){
        cout << "(" << arr[y][x] << ")";
        return ;
    }

    int halfSize = size / 2;
    cout << "(";

    if (!madeByOneType(arr, halfSize, x, y))
        recursion(arr, halfSize, x, y);

    if (!madeByOneType(arr, halfSize, x + halfSize, y))
        recursion(arr, halfSize, x + halfSize, y);

    if (!madeByOneType(arr, halfSize, x, y + halfSize))
        recursion(arr, halfSize, x, y + halfSize);

    if (!madeByOneType(arr, halfSize, x + halfSize, y + halfSize))
        recursion(arr, halfSize, x + halfSize, y + halfSize);

    cout << ")";
}

int main()
{
    int N;

    vector<vector<int>> arr;
    cin >> N;
    for (int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        vector<int> a;
        for (int j = 0; j < N; j++){
            a.push_back(tmp[j] - '0');
        }
        arr.push_back(a);
    }
    if (!madeByOneType(arr, arr.size(), 0, 0))
        recursion(arr, arr.size(), 0,0);
    return 0;
}