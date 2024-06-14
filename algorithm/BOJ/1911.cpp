#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void fastIO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}
int n, m, idx, ret, b;
int main(){
    fastIO();
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i].second <= idx) continue;
        if(idx < a[i].first){
            b = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
            idx = a[i].first + b * m;
        }else{
            b = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
            idx = idx + b * m;
        }
        ret += b;
    }
    cout << ret << "\n";
    return 0;
} 