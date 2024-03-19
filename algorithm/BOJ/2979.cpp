#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    const int trucksCnt = 3;
    vector<int> pay(trucksCnt);
    int cnt[101] = {0, };

    for (int i = 0; i < trucksCnt; i++){
        cin >> pay[i];
    }
    int in, out;
    for (int i = 0; i < trucksCnt; i++){
        cin >> in >> out;
        for(int j = in; j < out; j++){
            cnt[j]++;
        }
    }
    int result = 0;
    for (int i = 1; i < 100; i++){
        if (cnt[i] == 1)
            result += pay[0];
        else if (cnt[i] == 2)
            result += pay[1] * 2;
        else if (cnt[i] == 3)
            result += pay[2] * 3;
    }
    cout << result;
    
    return 0;
}