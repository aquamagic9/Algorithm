#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool canMakePalindrome(const string &s)
{
    bool check = true;
    if (s.size() % 2)
        check = false;
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == s[i + 1]){
            i++;
        }
        else {
            if (!check){
                check = true;
            }
            else
                return false;
        }
    }
    return true;
}

string makePalindrome(const string &s)
{
    string newString;
    char mid = '\0';
    newString.resize(s.size());
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == s[i + 1]){
            newString[i / 2] = s[i];
            newString[s.size() - 1 - i / 2] = s[i];
            i++;
        }
        else {
            mid = s[i];
        }
    }
    if (mid == '\0')
        newString[s.size() / 2] = s[s.size() - 1];
    else
        newString[s.size() / 2] = mid;
    return newString;
}

int main()
{
    string s;

    cin >> s;
    sort(s.begin(), s.end());
    if (canMakePalindrome(s)){
        cout << makePalindrome(s);
    }
    else {
        cout << "I'm Sorry Hansoo";
    }

    return 0;
}