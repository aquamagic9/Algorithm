#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count[10001] = {0};
    int number = 0;

    for (int i = 0; i <= N; i++){
        cin >> number;
        count[number]++;
    }
    for (int i = 0; i <= 10000; i++){
        if (count[i] != 0){
            for(int j = 0; j < count[j]; j++)
                cout << i << "\n";
        }
    }
    return 0;
}