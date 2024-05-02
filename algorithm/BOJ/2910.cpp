#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> mp, mpFirst;
bool sortByCount(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return mpFirst[a.first] < mpFirst[b.first];
    }
    return a.second > b.second;
}
int main()
{
    int N, C;

    cin >> N >> C;
    for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        mp[temp]++;
        if (mpFirst[temp] == 0)
            mpFirst[temp] = i + 1;
    }
    vector<pair<int,int>> v;
    for (auto it : mp){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), sortByCount);
    for (auto i : v){
        for (int j = 0; j < i.second; j++){
            cout << i.first << " ";
        }
    }

    return 0;
}