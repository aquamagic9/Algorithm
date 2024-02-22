#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int arr[101][101] = {0, };
int rowSize = 3, colSize = 3, cnt = 0;
typedef pair<int, int> pairNum;

bool cmp(pair<int,int>& a, pair<int,int>& b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

void SortRow()
{
    map<int, int> nums;
    for (int row = 1; row <= rowSize; row++){
        nums.clear();
        for (int col = 1; col <= colSize; col++){
            if (arr[row][col] == 0)
                continue;
            nums[arr[row][col]]++;
        }
        vector<pairNum> pairNums(nums.begin(), nums.end());
        sort(pairNums.begin(), pairNums.end(), cmp);
        colSize = colSize > pairNums.size() * 2 ? colSize : pairNums.size() * 2;
        int size = pairNums.size() * 2 <= 100 ? pairNums.size() * 2 : 100;
        for (int col = 1; col <= size; col += 2){
            arr[row][col] = pairNums[col / 2].first;
            arr[row][col + 1] = pairNums[col / 2].second;
        }
        for (int col = size + 1; col <= colSize; col++)
            arr[row][col] = 0;
    }
}

void SortCol()
{
    map<int, int> nums;
    for (int col = 1; col <= colSize; col++){
        nums.clear();
        for (int row = 1; row <= rowSize; row++){
            if (arr[row][col] == 0)
                continue;
            nums[arr[row][col]]++;
        }
        vector<pairNum> pairNums(nums.begin(), nums.end());
        sort(pairNums.begin(), pairNums.end(), cmp);
        rowSize = rowSize > pairNums.size() * 2 ? rowSize : pairNums.size() * 2;
        int size = pairNums.size() * 2 <= 100 ? pairNums.size() * 2 : 100;
        for (int row = 1; row <= size; row += 2){
            arr[row][col] = pairNums[row / 2].first;
            arr[row + 1][col] = pairNums[row / 2].second;
        }
        for (int row = size + 1; row <= rowSize; row++)
            arr[row][col] = 0;
    }
}

int main()
{
    int r, c, k;

    cin >> r >> c >> k;
    for (int row = 1; row <= 3; row++){
        for (int col = 1; col <= 3; col++){
            cin >> arr[row][col];
        }
    }
    while (arr[r][c] != k){
        cnt++;
        if (cnt > 100){
            cnt = -1;
            break;
        }
        if (rowSize >= colSize){
            SortRow();
        }
        else{
            SortCol();
        }
    }
    cout << cnt;

    return 0;
}