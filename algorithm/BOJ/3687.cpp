#include <iostream>
using namespace std;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6},t, n;
string dp[104], dp2[104], MAX_STR = "11111111111111111111111111111111111111111111111111111";

string get_min_str(string a, string b){
    if(a.size() == b.size())
        return (a < b ? a : b);
    if(a.size() < b.size())
        return a;
    else
        return b;
}

string findMax(int here){
    string ret = "";
    if(here & 1){
        ret += '7';
        here -= 3;
    }
    while(here){
        ret += '1';
        here -= 2;
    }
    return ret;
}

string findMin(int here){
    if(here == 0)
        return "";
    string &ret = dp[here];
    if(ret != MAX_STR)
        return ret;
    for(int i = 0; i <= 9; i++){
        if(here - a[i] < 0)
            continue;
        if(here == n && i == 0)
            continue;
        ret = get_min_str(ret, to_string(i) + findMin(here - a[i]));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        fill(dp, dp + 104, MAX_STR);
        cout << findMin(n) << " " << findMax(n) << "\n";
    }
}