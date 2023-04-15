#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    std::sort(lost.begin(), lost.end());
    std::sort(reserve.begin(),reserve.end());
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = 1;
    }
    for (auto reserved : reserve){
        arr[reserved - 1] = 2;
    }
    for (auto losted:lost) {
        arr[losted - 1] -= 1;
    }
    for (auto reserved : reserve){
        if (arr[reserved - 1] != 2)
            continue;
        if (reserved - 2 >= 0 && arr[reserved - 2] == 0)
            arr[reserved - 2] = 1;
        else if (reserved < n && arr[reserved] == 0)
            arr[reserved] = 1;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] >= 1)
            answer++;
    }
    return answer;
}

int main()
{
    vector<int> lost;
    int losted[] = {2,4};
    int reserved[] = {3};
    vector<int> reserve;
    for(auto a : losted){
        lost.push_back(a);
    }
    for(auto a : reserved){
        reserve.push_back(a);
    }
    std::cout << solution(5, lost, reserve);
    return 0;
}