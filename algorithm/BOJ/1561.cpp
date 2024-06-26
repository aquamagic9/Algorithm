#include <bits/stdc++.h>
#define max_n 60000000004
#define MAX_M 10004
using namespace std;
typedef long long ll;

ll n, m, a[MAX_M], lo, hi = max_n, ret, mid, temp;
bool check(ll mid){
    temp = m;
    for(ll i = 0; i < m; i++)
        temp += mid / a[i];
    return temp >= n;
}
int main() {
    cin >> n >> m;
    for(ll i = 0; i < m; i++)
        cin >> a[i];
    if(n <= m){
        cout << n; return 0;
    }
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            ret = mid; hi = mid - 1;
        } else lo = mid + 1;
    }
    temp = m;
    for(ll i = 0; i < m; i++)
        temp += ((ret - 1) / a[i]);

    for(ll i = 0; i < m; i++){
        if(ret % a[i] == 0)
            temp++;
        if(temp == n){
            cout << i + 1 << '\n';
            return 0;
        }
    }
    return 0;
}