#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> prices(N);
    for (int i = 0; i < N; i++){
        cin >> prices[i];
    }
    int maxNum = -1;
    int result = 0;
    for (int i = N - 1; i >= 0; i--){
        if (prices[i] > maxNum){
            maxNum = prices[i];
        }
        result = max(result, maxNum - prices[i]);
    }
    cout << result;

    return 0;
}