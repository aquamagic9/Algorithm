#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "";
    const int alphabetCount = 26;
    int alphabets[alphabetCount] = {0, };

    cin >> s;
    for (char c : s)
    {
        alphabets[c - 'a']++;
    }
    for (int count : alphabets)
    {
        cout << count << " ";
    }

    return 0;
}