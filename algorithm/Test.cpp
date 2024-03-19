#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Parent{
public:
    void show(){
        cout << "AA";
    }

    void show(int a){
        cout << "CC";
    }
};

class Child : public Parent{
public:
    void show(){
        cout << "BB";
    }
};

int main(){
    Child * c = new Child;
    c->show();
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i); v.push_back(i);
    }
    unique(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";

}
