#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //int a;
    //cin >> hex >> a;
    //cout << a;

    float e = 0.0f;
    float a = 0.0f/e , b = 0.0f/e , c = 1.0f/e , d = 1.0f/e;
    cout << a << " " << b << " " << c  << " " << d << endl;
    if (a == b)
        cout << "a == b" << endl;
    else
        cout << "a != b" << endl;
    if (c == d)
        cout << "c == d" << endl;
    else
        cout << "c != d" << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::reverse_iterator ri = find(v.rbegin(), v.rend(), 3);
    v.erase(--ri.base());
    return 0;
}