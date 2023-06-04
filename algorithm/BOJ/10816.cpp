#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    vector<int> myCard, yourCard;

    cin >> N;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        myCard.push_back(tmp);
    }
    sort(myCard.begin(), myCard.end());
    cin >> M;
    //이분탐색 시간초과가 남
//    for (int i = 0; i < M; i++){
//        int tmp, cnt = 0;
//        cin >> tmp;
//        int front = 0, end = N - 1;
//        while (front <= end){
//            int index = (front + end) / 2;
//            if (myCard[index] < tmp){
//                front = index + 1;
//            }
//            else if (myCard[index] > tmp){
//                end = index - 1;
//            } else{
//                cnt++;
//                int index_tmp = index + 1;
//                while (myCard[index_tmp] == tmp){
//                    index_tmp++;
//                    cnt++;
//                }
//                index_tmp = index - 1;
//                while (myCard[index_tmp] == tmp){
//                    index_tmp--;
//                    cnt++;
//                }
//                break;
//            }
//        }
//        cout << cnt << " ";
//    }

    for (int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        int cnt = upper_bound(myCard.begin(), myCard.end(), tmp) - lower_bound(myCard.begin(), myCard.end(), tmp);
        cout << cnt << " ";
    }
    return 0;
}