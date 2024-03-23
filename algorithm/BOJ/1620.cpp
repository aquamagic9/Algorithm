#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

inline bool IsNum(const char c)
{
    return c >= '0' && c <= '9';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    map<string, int> mp;
    string command;

    cin >> N >> M;
    vector<string> pocketmons(N + 1);
    for (int i = 1; i <= N; i++){
        cin >> pocketmons[i];
        mp[pocketmons[i]] = i;
    }
    for (int i = 0; i < M; i++){
        cin >> command;
        if (IsNum(command.front())){
            cout << pocketmons[stoi(command)] << "\n";
        }
        else{
            cout << mp[command] << "\n";
        }
    }

    return 0;
}