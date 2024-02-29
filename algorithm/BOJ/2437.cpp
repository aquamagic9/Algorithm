#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> weights(N);
    for (int i = 0; i < N; i++){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int result = 1;
    for (int i = 0; i < N; i++){
        if (weights[i] > result){
            break;
        }
        result += weights[i];
    }
    cout << result;

    return 0;
}