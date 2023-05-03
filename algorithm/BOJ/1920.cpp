#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        int start = 0, end = N - 1;
        bool find = false;
        cin >> target;
        while (start <= end){
            if (A[(start + end) / 2] == target)
            {
                find = true;
                break;
            }
            else if (A[(start + end) / 2] > target)
                end = (start + end) / 2 - 1;
            else
                start = (start + end) / 2 + 1;
        }
        if (find)
            cout << "1" << "\n";
        else
            cout << "0" << "\n";
    }

    return 0;
}