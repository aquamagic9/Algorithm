#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;

    for(int num : nums){
        s.insert(num);
    }
    answer = s.size() < nums.size() / 2 ? s.size() : nums.size() / 2;

    return answer;
}

int main()
{
    vector<int> nums;

    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);

    cout << solution(nums);

    return 0;
}