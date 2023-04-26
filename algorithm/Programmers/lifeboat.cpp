#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int cnt = 0;

    sort(people.begin(), people.end(), compare);
    int j = people.size() - 1;
    for (int i = 0; i <= j; i++)
    {
        if (i != j && (people[i] + people[j] <= limit))
            j--;
        cnt++;
    }
    answer = cnt;

    return answer;
}