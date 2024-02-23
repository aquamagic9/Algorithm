#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;

    cin >> N;
    vector<int> myCards(N);
    for (int i = 0; i < N; i++){
        cin >> myCards[i];
    }
    sort(myCards.begin(), myCards.end());
    cin >> M;
    vector<int> predictionCards(M);
    vector<int> answer(M, 0);
    for (int i = 0; i < M; i++){
        cin >> predictionCards[i];
    }
    for (int i = 0; i < M; i++){
        int card = predictionCards[i];
        int start = 0, end = N - 1;
        while (start <= end){
            int mid = (start + end) / 2;
            if (card == myCards[mid]){
                answer[i] = 1;
                break;
            }
            else if (card > myCards[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    for (int i = 0; i < M; i++){
        cout << answer[i] << " ";
    }

    return 0;
}