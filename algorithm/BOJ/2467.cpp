#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<int> v(n);
    vector<int> answer(2);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int st, ed;
    int result = 2000000000;

    st = 0;
    ed = n - 1;
    while (st < ed){
        int sum = v[st] + v[ed];
        if (abs(sum) < abs(result)){
            result = sum;
            answer[0] = v[st];
            answer[1] = v[ed];
        }
        if (sum < 0){
            st++;
        }
        else{
            ed--;
        }
    }
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}