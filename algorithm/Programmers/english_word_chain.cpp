#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> used_words;
    int i = 0;

    string prev_word = words.front();
    for(string s : words)
    {
        i++;
        if (i != 1 && prev_word[prev_word.size() - 1] != s[0])
            break;
        prev_word = s;
        if (s.size() == 1)
            break;
        int flag = true;
        for (string s2 : used_words)
            if (s2 == s)
                flag = false;
        if (flag == false)
            break;
        used_words.push_back(s);
    }
    if (used_words.size() == words.size())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back((i - 1) % n + 1);
    answer.push_back((i-1) / n + 1);

    return answer;
}