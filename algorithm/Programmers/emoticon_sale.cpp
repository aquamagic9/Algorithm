#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<float> sales = { 0.1f, 0.2f, 0.3f, 0.4f };

    int n = 0, maxCase = pow(4, emoticons.size());
    int maxServiceCnt = 0, maxSumPrice = 0;
    while (n < maxCase){
        int serviceCnt = 0, sumPrice = 0;
        for (vector<int> user : users){
            int limitSale = user[0], limitPrice = user[1], k = n;
            float sum = 0;
            for (int i = 0; i < emoticons.size(); i++){
                if (limitSale <= (int)(sales[k % 4] * 100))
                    sum += (float)emoticons[i] * (1 - sales[k % 4]);
                k /= 4;
            }
            if (limitPrice <= (int)sum)
                serviceCnt++;
            else
                sumPrice += (int)sum;
        }
        if (maxServiceCnt <= serviceCnt){
            if (maxServiceCnt == serviceCnt){
                if (maxSumPrice < sumPrice)
                    maxSumPrice = sumPrice;
            }
            else{
                maxServiceCnt = serviceCnt;
                maxSumPrice = sumPrice;
            }
        }
        n++;
    }
    answer.push_back(maxServiceCnt);
    answer.push_back(maxSumPrice);

    return answer;
}

int main()
{
    vector<vector<int>> users = {{40, 10000}, {25, 10000}};
    vector<int> emoticons = {7000, 9000};
    vector<int> answer;

    answer = solution(users, emoticons);
    for (int n : answer)
        cout << n << " " << endl;

    return 0;
}