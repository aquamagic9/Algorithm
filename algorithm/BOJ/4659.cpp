#include <iostream>
using namespace std;
char vowels[5] = {'a', 'e', 'i','o' ,'u'};

bool inline isSmallAlphabet(char c){
    return c >= 'a' && c <= 'z';
}
bool isVowel(char c){
    for (char vowel : vowels){
        if (vowel == c){
            return true;
        }
    }
    return false;
}
bool inline isConsonant(char c){
    return !isVowel(c);
}
bool condition1(string s){
    for (char c : s){
        if (isSmallAlphabet(c) && isVowel(c)){
            return true;
        }
    }
    return false;
}
bool condition2(string s){
    int cnt = 1;
    for (int i = 0; i < s.length() - 1; i++){
        if (isVowel(s[i]) && !isVowel(s[i + 1]) || isConsonant(s[i]) && !isConsonant(s[i + 1]))
        {
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        if (cnt == 3){
            return false;
        }
    }
    return true;
}
bool condition3(string s){
    for (int i = 0; i < s.length() - 1; i++){
        if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o'){
            return false;
        }
    }
    return true;
}
int main()
{
    while (true){
        string s;

        cin >> s;
        if (s == "end"){
            break;
        }
        cout << "<" << s << ">";
        if (condition1(s) && condition2(s) && condition3(s)){
            cout << " is acceptable.\n";
        }
        else{
            cout << " is not acceptable.\n";
        }
    }

    return 0;
}