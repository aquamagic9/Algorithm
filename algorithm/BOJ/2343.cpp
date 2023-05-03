#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;
    vector<int> arr(N, 0);
    int start = -1, end = 0;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        if (start < arr[i])
            start = arr[i];
        end += arr[i];
    }
    while (start <= end){
        int medi = (start + end) / 2;
        int sum = 0, cnt = 0;
        for (int i = 0; i < N; i++){
            if (sum + arr[i] > medi){
                cnt++;
                sum = 0;
            }
            sum += arr[i];
        }
        if (sum != 0)
            cnt++;
        if (cnt > M){
            start = medi + 1;
        }
        else {
            end = medi - 1;
        }
    }
    cout << start;

    return 0;
}