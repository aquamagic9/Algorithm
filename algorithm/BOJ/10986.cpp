#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    long cnt = 0;
    cin >> N >> M;
    vector<long> A(N, 0);
    vector<long> S(N, 0);
    vector<long> C(M, 0);

    cin >> S[0];
    for (int i = 1; i < N; i++)
    {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    for (int i = 0; i < N; i++)
    {
        int remain = S[i] % M;
        if (remain == 0)
            cnt++;
        C[remain]++;
    }
    for (int i = 0; i < M; i++){
        if (C[i] > 1){
            cnt = cnt + (C[i] * (C[i] - 1) / 2);
        }
    }
    cout << cnt ;

    return 0;
}