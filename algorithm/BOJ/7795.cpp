#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T, N, M;

    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> N >> M;
        vector<int> A(N);
        vector<int> B(M);
        for(int j = 0; j < N; j++){
            cin >> A[j];
        }
        for (int j = 0; j < M; j++){
            cin >> B[j];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int total = 0, cnt = 0, startIndex = 0;
        for (int j = 0; j < N; j++){
            for (int k = startIndex; k < M; k++){
                if (A[j] > B[k]){
                    cnt++;
                    if (k == M - 1){
                        startIndex = M;
                    }
                }
                else{
                    startIndex = k;
                    break;
                }
            }
            total += cnt;
        }
        cout << total << "\n";
    }

    return 0;
}