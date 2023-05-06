#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long N, K;

    cin >> N >> K;
    long start = 1, end = K;
    long answer = 0;
    while (start <= end){
        long cnt = 0;
        long middle = (start + end) / 2;
        for (int i = 1; i <= N; i++){
            cnt += min(middle / i , N);
        }
        if (cnt < K)
            start = middle + 1;
        else{
            answer = middle;
            end =  middle - 1;
        }
    }
    cout << answer;
    return 0;
}