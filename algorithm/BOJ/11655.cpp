#include <iostream>
#include <vector>
using namespace std;

bool isUpper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}
bool isLower(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}
int main()
{
    const int caesarNum = 13, alphabetCount = 26;
    string s, result ="";

    getline(cin, s);
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        char c = s[i];
        if (isUpper(c)){
            c = 'A' + (c - 'A' + caesarNum) % alphabetCount;
        }
        else if (isLower(c)){
            c = 'a' + (c - 'a' + caesarNum) % alphabetCount;
        }
        result += c;
    }
    cout << result;
    return 0;
}