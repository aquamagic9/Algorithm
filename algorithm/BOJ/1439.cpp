#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string num;
    int cnt = 1;

    cin >> num;
    for (int i = 1; i < num.size(); i++){
        if(num[i - 1] != num[i]){
            cnt++;
        }
    }
    cout << cnt / 2;
    return 0;
}
