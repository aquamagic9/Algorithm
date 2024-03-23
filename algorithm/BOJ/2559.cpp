#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, num, sum = 0;

    cin >> n >> k;
    int maxValue = n * -100;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> num;
        v[i] = num;
        sum += num;
        if (i - k >= 0){
            sum -= v[i - k];
        }
        if (i >= k - 1){
            maxValue = max(maxValue, sum);
        }
    }
    cout << maxValue;

    return 0;
}