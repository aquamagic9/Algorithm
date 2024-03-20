#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    const int alphabetSize = 26;
    string name, result = "";

    cin >> n;
    int alphabet[alphabetSize] = {0,};
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        alphabet[name.front() - 'a']++;
    }
    for (int i = 0; i < alphabetSize; i++)
    {
        if (alphabet[i] >= 5)
            result += 'a' + i;
    }
    if (result.empty()){
        result += "PREDAJA";
    }
    cout << result;

    return 0;
}