#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int start = 0, end = 0, cnt = 0, result = 0;

    while (true){
        if (end >= N){
            result = max(result, cnt);
            break;
        }
        if (v[start] + 4 >= v[end]){
            end++;
            cnt++;
        }
        else{
            result = max(result, cnt);
            start++;
            cnt--;
        }
    }

    cout << 5 - result;

    return 0;
}