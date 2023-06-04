#include <iostream>
#include <vector>
using namespace std;

void recursion(vector<vector<char>> &arr, int N, int y, int x){
    if (N == 1)
        return;
    int prevN = N;
    N = N / 3;
    for (int k = 0; k < 3; k++){
        for (int p = 0; p < 3; p++){
            for (int i = y + N + k * prevN; i < y + N + N + k * prevN; i++){
                for (int j = x + N + p * prevN; j < x + N + N + p * prevN; j++){
                    arr[i][j] = ' ';
                }
            }
            recursion(arr, N, y + k*prevN, x + p*prevN);
        }
    }
}
int main()
{
    int N;

    cin >> N;
    vector<vector<char>> arr;
    for (int i = 0; i < N; i++){
        vector<char> tmp(N, '*');
        arr.push_back(tmp);
    }
    N = N/3;
    for (int i = N; i < N + N; i++){
        for (int j = N; j < N + N; j++){
            arr[i][j] = ' ';
        }
    }
    recursion(arr, N, 0, 0);

    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}