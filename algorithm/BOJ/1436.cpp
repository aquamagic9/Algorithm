#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;
    int num = 666;
    while (N != 0){
        if (to_string(num).find("666") != string::npos){
            N--;
        }
        num++;
    }
    cout << num - 1;

    return 0;
}