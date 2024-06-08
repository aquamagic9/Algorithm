#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

void eratos(int n) {
    vector<bool> prime(n + 1, true);

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prime[i])
            arr.push_back(i);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }

    eratos(n);

    int s = arr.size();

    int ans = 0, start = 0, end = 0, sum = 0;

    while (end <= s) {
        if (sum >= n) {
            sum -= arr[start++];
        }
        if (sum < n) {
            sum += arr[end++];
        }
        if (sum == n) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}