#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    if (completion.empty())
        return participant[0];

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int answerIndex = 0;
    for(int i = 0; i < participant.size(); i++){
        answerIndex = i;
        if (participant[i] != completion[i])
            break;
    }
    string answer = participant[answerIndex];

    return answer;
}

int main()
{
    vector<string> a, b;

    a.push_back("leo");
    //a.push_back("eden");
    //b.push_back("leo");

    cout << solution(a, b);

    return 0;
}