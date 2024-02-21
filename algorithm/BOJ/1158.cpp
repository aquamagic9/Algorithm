#include <iostream>
#include <list>
using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;
    int index = K + 1;
    list<int> people;
    for (int i = 1; i <= N; i++){
        people.push_back(i);
    }
    list<int>::iterator iter;
    iter = people.begin();

    cout << "<";
    while (people.size() > 1){
        for (int i = 0; i < K - 1; i++){
            if (++iter == people.end()){
                iter = people.begin();
            }
        }
        cout << *iter << ", ";
        iter = people.erase(iter);
        if (iter == people.end())
            iter = people.begin();
    }
    cout << people.front() << ">";

    return 0;
}