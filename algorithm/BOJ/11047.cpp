#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, K, num, cnt, result = 0;
    vector<int> V;

    cin >> N >> K;
    for (int i= 0; i< N; i++)
    {
        cin >> num;
        V.push_back(num);
    }
    for (int i =0 ; i < N; i++)
    {
        if (K <= 0)
            break;
        cnt = K / V[N - 1 - i];
        result += cnt;
        K = K - cnt * V[N - 1 - i];
    }

    cout << result;
    return 0;
}