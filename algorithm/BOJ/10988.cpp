#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    int size;

    cin >> s;
    size = s.size();
    for (int i = 0; i < size / 2; i++){
        if (s[i] != s[size - 1 - i]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}