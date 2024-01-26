#include <iostream>
#include <list>
using namespace std;

int main(){

    int T;

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++){
        int N, M, L;
        cin >> N >> M >> L;
        list<int> sequence(N);
        list<int>::iterator iter = sequence.begin();
        for (;iter != sequence.end(); iter++){
            cin >> *iter;
        }
        for (int i = 0; i < M; i++){
            char order;
            cin >> order;
            iter = sequence.begin();
            if (order == 'I'){
                int index, num;
                cin >> index >> num;
                advance(iter, index);
                sequence.insert(iter, num);
            }
            else if (order == 'D'){
                int index;
                cin >> index;
                advance(iter, index);
                sequence.erase(iter);
            }
            else if (order == 'C'){
                int index, num;
                cin >> index >> num;
                advance(iter, index);
                *iter = num;
            }
        }
        if (sequence.size() <= L){
            cout << "#" << test_case << " -1\n";
            continue;
        }
        iter = sequence.begin();
        advance(iter, L);
        cout << "#" << test_case << " " << *iter << "\n";
    }

    return 0;
}