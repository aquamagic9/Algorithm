#include <iostream>
using namespace std;

int main()
{
    string num;

    cin >> num;
    for (int i = 0; i < num.size() - 1; i++){
        char max = i;
        for (int j = i + 1; j < num.size(); j++){
            if (num[max] < num[j]){
                max = j;
            }
        }
        int tmp = num[max];
        num[max] = num[i];
        num[i] = tmp;
    }

    cout << num;

    return 0;
}