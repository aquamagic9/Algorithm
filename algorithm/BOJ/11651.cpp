#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    int N;

    cin >> N;
    vector<pair<int, int>> pos;
    for (int i = 0; i < N ; i++){
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        pos.push_back(tmp);
    }
    sort(pos.begin(), pos.end(), compare);
    for (int i = 0; i < N; i++){
        cout << pos[i].first << " " << pos[i].second << "\n";
    }

    return 0;
}