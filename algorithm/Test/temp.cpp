#include <iostream>
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
    return 0;
}