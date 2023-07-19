#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<vector<int>> arr;
    for (int i = 0; i < N; i++){
        vector<int> row(N);
        for (int j = 0; j < N; j++){
            cin >> row[j];
        }
        arr.push_back(row);
    }


    return 0;
}