#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, maxCnt = 0;
int alpha[26];
char defaultAlphabet[5] = {'a', 'c', 'i', 't', 'n'};
const int defaultAlphabetSize = 5;
vector<char> newAlphabet;
vector<string> strs;

void combi(int start, vector<int> v)
{
    if (v.size() == K){
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            alpha[newAlphabet[v[i]] - 'a'] = 1;
        }
        for (int i = 0; i < N; i++){
            bool check = true;
            for (int j = 0; j < strs[i].size(); j++){
                if (alpha[strs[i][j] - 'a'] == 0){
                    check = false;
                }
            }
            if (check){
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
        for(int i = 0; i < v.size(); i++){
            alpha[newAlphabet[v[i]] - 'a'] = 0;
        }
        return;
    }
    for (int i = start + 1; i < newAlphabet.size(); i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
int main()
{
    cin >> N >> K;
    for (int i = 0; i < 5; i++){
        alpha[defaultAlphabet[i] - 'a'] = 1;
    }
    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        s = s.substr(4, s.size() - 8);
        strs.push_back(s);
        for (int j = 0; j < s.size(); j++){
            if (alpha[s[j] - 'a'] == 0){
                newAlphabet.push_back(s[j]);
            }
        }
    }
    sort(newAlphabet.begin(), newAlphabet.end());
    newAlphabet.erase(unique(newAlphabet.begin(), newAlphabet.end()), newAlphabet.end());
    K -= defaultAlphabetSize;
    if (K < 0){
        cout << 0;
        return 0;
    }
    if (K > newAlphabet.size())
        K = newAlphabet.size();

    vector<int> v;
    combi(-1, v);

    cout << maxCnt;

    return 0;
}