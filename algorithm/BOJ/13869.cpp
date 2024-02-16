#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = v[0] * v[1] + v[N - 1] * v[N - 2];
    //8642013579
    for (int i = 0; i < N - 2; i++){
        sum += v[i] * v[i + 2];
    }
    cout << fixed;
    cout.precision(3);
    cout << sin((double )2 * M_PI / N) / (double)2 * (double)sum;

    return 0;
}