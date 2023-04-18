#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, cnt = 0;

    cin >> N;
    vector<int> arr(N, 0);
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++){
        int find = arr[i];
        int s_index = 0, e_index = N - 1;
        while (s_index < e_index){
            if (arr[s_index] + arr[e_index] < find){
                s_index++;
            }
            else if (arr[s_index] + arr[e_index] > find){
                e_index--;
            }
            else{
                if (s_index != i && e_index != i)
                {
                    cnt++;
                    break;
                }
                else if (s_index == i)
                    s_index++;
                else if (e_index == i)
                    e_index--;
            }
        }
    }
    cout << cnt;

    return 0;
}