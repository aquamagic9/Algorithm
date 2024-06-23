#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<int> v(n);
    vector<int> answer(3);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int st, ed;
    long long result = 3000000000;
    for (int i = 0; i < n - 2; i++){
        int num = v[i];
        st = i + 1;
        ed = n - 1;
        while (st < ed){
            long long sum = (long long)num + (long long)v[st] + (long long)v[ed];
            if (abs(sum) < abs(result)){
                result = sum;
                answer[0] = num;
                answer[1] = v[st];
                answer[2] = v[ed];
            }
            if (sum < 0){
                st++;
            }
            else{
                ed--;
            }
        }
    }
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}
// -24 -6 -3 -2 61 98 100