#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int N;
    deque<int> tmp;

    cin >> N;
    for (int i = 0; i < N; i++){
        tmp.push_back(i + 1);
    }
    int i = 0;
    while (tmp.size() > 1){
        if (i % 2 == 0)
            tmp.pop_front();
        else
        {
            tmp.push_back(tmp.front());
            tmp.pop_front();
        }
        i++;
    }
    cout << tmp.front();

    return 0;
}
