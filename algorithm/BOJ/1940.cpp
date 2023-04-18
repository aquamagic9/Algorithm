#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;

    cin >> N;
    cin >> M;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int s_index = 0, e_index = arr.size() - 1, cnt = 0;
    while (s_index < e_index)
    {
        if (arr[s_index] + arr[e_index] == M){
            s_index++;
            e_index--;
            cnt++;
        }
        else if (arr[s_index] + arr[e_index] < M){
            s_index++;
        }
        else
            e_index--;
    }
    cout << cnt;
    return 0;
}