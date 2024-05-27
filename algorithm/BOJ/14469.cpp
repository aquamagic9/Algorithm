#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, start, time;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> start >> time;
        v.push_back({start, time});
    }
    sort(v.begin(), v.end());
    int totalT = 0;
    for (int i = 0; i < n; i++){
        if (totalT < v[i].first){
            totalT = v[i].first + v[i].second;
        }
        else {
            totalT += v[i].second;
        }
    }
    cout << totalT;

    return 0;
}