#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i;
    int brown_remain_box = (brown - 4) / 2;

    for (i = 1; i <= brown_remain_box; i++)
    {
        if (i * (brown_remain_box - i) == yellow)
            break;
    }
    answer.push_back(brown_remain_box - i + 2);
    answer.push_back(i + 2);
    return answer;
}