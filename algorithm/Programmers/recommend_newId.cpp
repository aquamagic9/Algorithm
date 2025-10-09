#include <string>
#include <vector>
#include <iostream>

using namespace std;

string rule1(string s){
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

string rule2(string s){
    string newS = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'a' && s[i] <='z' || s[i] >= '0' && s[i] <= '9' || s[i] == '-' || s[i] == '_' || s[i] == '.')
            newS += s[i];
    }
    return newS;
}

string rule3(string s){
    string newS = "";
    newS += s[0];
    for (int i = 1; i < s.length(); i++){
        if (s[i - 1] == '.' && s[i] == '.'){
            continue;
        }
        newS += s[i];
    }
    return newS;
}

string rule4(string s){
    if (s[0] == '.')
        s = s.substr(1, s.length() - 1);
    if (s[s.length() - 1] == '.')
        s = s.substr(0, s.length() - 1);
    return s;
}

void rule5(string &s){
    if (s.length() == 0){
        s = "a";
    }
}

string rule6(string s){
    if (s.length() >= 16){
        s = s.substr(0, 15);
        if (s[s.length() - 1] == '.')
            s = s.substr(0, s.length() - 1);
        return s;
    }
    return s;
}

string rule7(string s){
    if (s.length() <= 2){
        while (s.length() != 3){
            s += s[s.length() - 1];
        }
    }
    return s;
}

string solution(string new_id) {
    string answer = "";

    new_id = rule1(new_id);
    new_id = rule2(new_id);
    new_id = rule3(new_id);
    new_id = rule4(new_id);
    rule5(new_id);
    new_id = rule6(new_id);
    answer = rule7(new_id);

    return answer;
}

int main(){
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    cout << solution(new_id);

    return 0;
}