#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        ret += v[i].second;
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            ret -= pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";

    return 0;
}