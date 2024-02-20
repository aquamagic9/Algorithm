#include <iostream>
#include <queue>
using namespace std;

class Queue {
public:
    int queue[10000];
    int begin = 0;
    int end = 0;

    void push(int x) {
        queue[end++] = x;
    }

    bool empty() {
        return begin == end;
    }

    int pop() {
        if (empty())
            return -1;
        int num = queue[begin];
        queue[begin++] = 0;
        return num;
    }

    int size() {
        return end - begin;
    }

    int front() {
        if (empty())
            return -1;
        return queue[begin];
    }

    int back() {
        if (empty())
            return -1;
        return queue[end - 1];
    }
};

int main()
{
    int N, num;

    cin >> N;
    string command;
    Queue q;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            cin >> num;
            q.push(num);
        }
        else if (command == "pop") {
            cout << q.pop() << "\n";
        }
        else if (command == "size") {
            cout << q.size() << "\n";
        }
        else if (command == "empty") {
            cout << q.empty() << "\n";
        }
        else if (command == "front") {
            cout << q.front() << "\n";
        }
        else if (command == "back") {
            cout << q.back() << "\n";
        }
    }

    return 0;
}