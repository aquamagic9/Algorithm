#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 9, sum = 0, diff;
    vector<int> arr(N);

    for (int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    diff = sum - 100;
    for (int i = 0 ; i < N - 1; i++){
        for (int j = i + 1; j < N; j++){
            if (arr[i] + arr[j] == diff){
                arr.erase(arr.begin() + i);
                arr.erase(arr.begin() + j - 1);
                i = N;
                break;
            }
        }
    }
    for (int i = 0; i < N - 2; i++)
        cout << arr[i] << "\n";

    return 0;
}