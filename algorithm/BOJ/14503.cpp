#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
//cleared wall empty
#define EMPTY 0
#define WALL 1
#define CLEARED 2

bool haveNotUnclearedPlace(vector<vector<int>> &arr, int &y, int &x)
{
    if ((!(y + 1 < arr.size()) || y + 1 < arr.size() && arr[y + 1][x] == WALL || arr[y + 1][x] == WALL ) &&
        (!(y - 1 > 0) || y - 1 > 0 && arr[y - 1][x] == WALL) &&
        (!(x + 1 < arr.size()) || x + 1 < arr.size() && arr[y][x + 1] == WALL) &&
        (!(x - 1 > 0) || x - 1 > 0 && arr[y][x - 1] == WALL) )
        return true;
    return false;
}

bool moveToBack(vector<vector<int>> &arr, int &y, int &x, int &d)
{
    if (d == 0 && y + 1 < arr.size() && arr[y + 1][x] == EMPTY){
        y = y + 1;
    }
    else if (d == 1 && x - 1 > 0 && arr[y][x - 1] == EMPTY){
        x  = x - 1;
    }
    else if (d == 2 && y - 1 > 0 && arr[y - 1][x] == EMPTY){
        y = y - 1;
    }
    else if (d == 3 && x + 1 < arr.size() && arr[y][x + 1] == EMPTY){
        x = x + 1;
    } else
        return false;
    return true;
}

bool moveRobot(vector<vector<int>> &arr, int &y, int &x, int &d)
{
    cout << y << " " << x << endl;
    if (arr[y][x] == 0){
        arr[y][x] = CLEARED;
        cnt++;
        return true;
    }
    if (haveNotUnclearedPlace(arr, y, x))
    {
        if (!moveToBack(arr, y, x, d))
            return false;
        return true;
    }
    else{
        d = (d + 3) % 4;
        d = (d + 2) % 4;
        if (moveToBack(arr, y, x, d)){
            d = (d + 2) % 4;
            return true;
        }
        d = (d + 2) % 4;
        return false;
    }

}
int main()
{
    int y, x, d, N, M;

    vector<vector<int>> arr;

    cin >> N >> M;
    cin >> y >> x >> d;
    for(int i = 0; i < N; i++){
        vector<int> row(M);
        for (int j = 0; j < M; j++){
            cin >> row[j];
        }
        arr.push_back(row);
    }
    while (moveRobot(arr, y, x, d))
        ;
    cout << cnt;
    return 0;
}