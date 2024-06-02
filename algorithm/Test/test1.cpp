#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> t = vector<vector<int>>(8);
int k = 0, n, cnt = 0;
int findNum(int a)
{
    if (a >= 2 && a <= 7){
        return t[a].size();
    }
    return 0;
}
bool inNum(int a){
    return (a >= 2 && a <= 7);
}
int check (vector<int> v)
{
    int a = 1, b = 1, c = 1;

    if (!inNum(v[0]))
        return 0;
    a = findNum(v[0]);
    if (v[0] == 6){
        a--;
    }
    for (int i = 0; i < v.size() - 1; i++){
        if (!inNum(v[i + 1] - v[i] - 1))
            return 0;
        b = findNum(v[i + 1] - v[i] - 1);
    }

    if (!inNum(n - v[v.size() - 1] - 2))
        return 0;
    c = findNum(n - v[v.size() - 1] - 2);
    if (k == 2)
        cout << a << " " << b << " " << c << " " << a*b*c << " " << v[0] << v[1] << v[2] <<  endl;
    return a * b * c;
}

void combi(int start, vector<int> v)
{
    if (v.size() == k){
        if (v.empty()){
            cnt += findNum(n) ;
            return;
        }
        cnt += check(v);
        return;
    }
    for (int i = start + 3; i < n; i += 1)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}



vector<string> split2(string input, string delimiter)
{
    vector<string> ss;
    string token = "";
    long long pos;

    while ((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ss.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ss.push_back(input);
    return ss;
}




















int main()
{
    t[2].push_back(1);
    t[3].push_back(7);
    t[4].push_back(4);
    t[5].push_back(2); t[5].push_back(3); t[5].push_back(5);
    t[6].push_back(0); t[6].push_back(6); t[6].push_back(9);
    t[7].push_back(7);

    int originN;
    cin >> originN;

    string s = "ageagef: geagg:efajwefij : geag: gae:";
    vector<string> ss = split(s,":");
    for (int i = 0;i < ss.size(); i++){
        cout << ss[i] << endl;
    }

    for (int i = 0; i < originN / 2; i++){
        vector<int> v;
        n = originN + i;
        k = i;
        combi(-1, v);
        cout << "n: " << n << " k: " << k << " cnt: " << cnt << endl;
    }
    cout << cnt;

    return 0;
}