#include <iostream>
#include <vector>
using namespace std;

int n, m, k, t, a, b, cnt[301], dp[301][301];
vector<pair<int, int>> v;
int go(int here, int num, int prev){
    if(here == v.size())
        return 0;
    if(dp[here][num])
        return dp[here][num];

    int cost = max(0, t - v[here].second);
    int real_cost = (prev >= cost) ? 0 : cost - prev;

    int & ret = dp[here][num];
    if(num - real_cost >= 0){
        return ret = max(go(here + 1, num - real_cost, cost)+ v[here].first, go(here + 1, num, 0));
    }else
        return ret = go(here + 1, num, 0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k >> t;
    for(int j = 0; j < m; j++){
        cin >> a >> b;
        for(int i = a; i < b; i++)
            cnt[i] = min(t, ++cnt[i]);
    }
    int temp = cnt[1];
    int _count = 1;
    for(int i = 2; i <= n; i++){
        if(temp != cnt[i]){
            v.push_back({_count, temp});
            _count = 0;
            temp = cnt[i];
        }
        _count++;
    }
    v.push_back({_count, temp});

    cout << go(0, k, 0) << "\n";
    return 0;
}