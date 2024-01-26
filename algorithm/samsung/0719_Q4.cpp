#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;

        cin >> N;
        list<int> password(N);
        list<int>::iterator iter = password.begin();
        for (; iter != password.end(); iter++){
            cin >> *iter;
        }
        int M;
        cin >> M;
        char c;
        for (int i = 0; i < M; i++){
            cin >> c;
            if (c == 'I'){
                int x, y;
                cin >> x >> y;
                iter = password.begin();
                int index = 0;
                for (; iter != password.end(); iter++){
                    if (index == x)
                        break;
                    index++;
                }
                list<int> tmp(y);
                list<int>::iterator tmpIter = tmp.begin();
                for (;tmpIter != tmp.end(); tmpIter++){
                    cin >> *tmpIter;
                }
                password.insert(iter, tmp.begin(), tmp.end());
            }else if (c == 'D'){
                int x, y;
                cin >> x >> y;
                iter = password.begin();
                list<int>::iterator range_end = password.begin();
                advance(iter, x);
                advance(range_end, x + y);
                password.erase(iter, range_end);
            }else if (c == 'A'){
                int y, tmp;
                cin >> y;
                for (int j = 0; j < y; j++){
                    cin >> tmp;
                    password.push_back(tmp);
                }
            }
        }
        cout << "#" << test_case << " ";
        int cnt = 0;
        for (int word : password){
            cout << word << " ";
            cnt++;
            if (cnt == 10)
                break;
        }
        cout << "\n";
    }
    return 0;
}