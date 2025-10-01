#include <iostream>
#include <string>

using namespace std;

bool isSmallAlphabet(char c) {
    return 'a' <= c && c <= 'z';
}

bool isBigAlphabet(char c){
    return 'A' <= c && c <= 'Z';
}

string solution(string sentence) {
    string answer = "";
    int alpha[27] = {0,};

    for (char c : sentence){
        if (isSmallAlphabet(c))
            alpha[c - 'a']++;
        if (c == ' ')
            return "invalid";
    }

    for (int i = 0; i < sentence.size(); i++){
        char c = sentence[i];
        if (isSmallAlphabet(c) && alpha[c - 'a'] == 2){
            int j = i + 1;
            while (++j < sentence.size()){
                if (sentence[j] == c && isBigAlphabet(sentence[i + 1]) && isBigAlphabet(sentence[j - 1])){
                    sentence[i] = ' ';
                    sentence[j] = ' ';
                    alpha[c - 'a'] -= 2;
                    break;
                }
            }
            if (alpha[c - 'a'] != 0)
                return "invalid";
        }
    }

    for (int i = 0; i < sentence.size(); i++){
        char c = sentence[i];
        if (isSmallAlphabet(c)){
            if (alpha[c - 'a'] == 0 || i == 0){
                return "invalid";
            }
            int index = i, size = alpha[c - 'a'];
            while (alpha[c - 'a'] != 0){
                char pc = sentence[index - 1], nc = sentence[index + 1];
                if (isBigAlphabet(pc) && isBigAlphabet(nc) && c == sentence[index]){
                    index += 2;
                    alpha[c - 'a']--;
                }
                else{
                    return "invalid";
                }
            }
            for (int j = 0; j < size; j++){
                sentence[i + j] = sentence[i + 1 + j * 2];
            }
            for (int j = 0; j < size; j++){
                sentence[i + size * 2 - 1 - j] = ' ';
            }
            i = index + 2;
        }
    }
    for (int i = 0; i < sentence.size(); i++){
        if (sentence[i] == ' '){
            continue;
        }
        int index = i + 1;
        while (index < sentence.size() && sentence[index] != ' '){
            index++;
        }
        answer += sentence.substr(i, index - i) + " ";
        i = index;
    }
    answer = answer.substr(0, answer.size() - 1);

    return answer;
}

int main()
{
    string sentence = "HaEaLaLaObWORLDb";
    string sentence2 = "SpIpGpOpNpGJqOqA";
    string sentence3 = "HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoKKKAxAxAxAA";

    cout << solution(sentence3);

    return 0;
}