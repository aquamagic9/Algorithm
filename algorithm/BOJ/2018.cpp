#include <iostream>
using namespace std;
int main()
{
    int N, sum = 1, cnt = 1, s_index = 1, e_index = 1;

    cin >> N;
    while (e_index != N)
    {
        if (sum < N){
            e_index++;
            sum += e_index;
        }
        else if (sum > N){
            sum -= s_index;
            s_index++;
        }
        else{
            cnt++;
            e_index++;
            sum += e_index;
        }
        //cout << sum << " ";
    }
    cout << cnt ;
    return 0;
}