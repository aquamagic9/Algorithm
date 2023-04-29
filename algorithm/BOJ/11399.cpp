#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N; j++){
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += arr[i] * (N - i);
    }
    cout << sum;

    return 0;
}