#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;

    cin >> N;
    string word;
    int cnt = N;
    for (int i = 0; i < N; i++){
        cin >> word;
        int alphabet[26] = {0, };
        alphabet[word[0] - 'a']++;
        for (int j = 1; j < word.length(); j++){
            if (alphabet[word[j] - 'a'] != 0 && word[j - 1] != word[j]){
                cnt--;
                break;
            }
            alphabet[word[j] - 'a']++;
        }
    }
    cout << cnt;

    return 0;
}