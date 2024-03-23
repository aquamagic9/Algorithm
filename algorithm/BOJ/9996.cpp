#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void MatchPatten(const string& pattern, const string& s)
{
    int i = pattern.find('*');
    if (s.size() >= pattern.size() - 1
            && pattern.substr(0, i) == s.substr(0, i)
            && pattern.substr(i + 1) == s.substr(s.size() - (pattern.size() - 1 - i)))
    {
        cout << "DA\n";
    }
    else
    {
        cout << "NE\n";
    }
}
int main()
{
    int N;
    string pattern, s;

    cin >> N;
    cin >> pattern;
    for (int i = 0; i < N; i++){
        cin >> s;
        MatchPatten(pattern, s);
    }

    return 0;
}