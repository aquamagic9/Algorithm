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
vector<int> v;
void MakePermutation(int n, int r, int depth)
{
    if (depth == r)
        return;
    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        MakePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}
int n, k;//v's size;
void combi(int start, vector<int> &v)
{
    if (v.size() == k)
        return;
    for (int i = start + 1; i < n; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    string token = "";
    long long pos;
    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + input.length());
    }
    ret.push_back(input);
    return ret;
}