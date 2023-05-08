#include <string>
#include <vector>

using namespace std;
int answer = 0;

void recursion(vector<int> numbers, int target, int value, int index){
    if (index == numbers.size()){
        if (value == target)
            answer++;
        return;
    }
    recursion(numbers, target, value + numbers[index], index + 1);
    recursion(numbers, target, value - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {

    recursion(numbers, target, 0, 0);
    return answer;
}