#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, target, after_str = "";

    cin >> str >> target;
    for (int i = 0; i < str.size(); i++)
    {
        after_str += str[i];
        if (target.back() == after_str.back()) {
            bool flag = true;
            for (int j = 0; j < target.size(); j++) {
                if (after_str.size() - 1 - j >= 0 &&
                    after_str[after_str.size() - 1 - j] != target[target.size() - 1 - j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                after_str.erase(after_str.size() - target.size(), target.size());
            }
        }
    }
    if (after_str.size())
        cout << after_str;
    else
        cout << "FRULA";
    return 0;
}
