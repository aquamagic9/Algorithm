#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> pre;
vector<int> in;
vector<int> nodeIndex;
vector<int> post;

bool CheckChild(int start, int end, int child)
{
    for(int i = start; i <= end; i++){
        if (in[i] == child){
            return true;
        }
    }
    return false;
}

void PostOrder(int parentPreIndex, int inStartIndex, int inEndIndex)
{
    int parent = pre[parentPreIndex];

    int leftChild = 0, leftChildPreIndex = parentPreIndex + 1;
    if (leftChildPreIndex <= n){
        leftChild = pre[leftChildPreIndex];
    }

    int rightChild = 0, rightChildPreIndex = parentPreIndex + (nodeIndex[parent] - inStartIndex) + 1;
    if (rightChildPreIndex <= n)
        rightChild = pre[rightChildPreIndex];

    if (CheckChild(inStartIndex, nodeIndex[parent] - 1, leftChild)){
        PostOrder(leftChildPreIndex, inStartIndex, nodeIndex[parent] - 1);
    }
    if (CheckChild(nodeIndex[parent] + 1, inEndIndex, rightChild)){
        PostOrder(rightChildPreIndex, nodeIndex[parent] + 1, inEndIndex);
    }
    cout << parent << " ";
    post.push_back(parent);
}

int main()
{
    int testcase;

    cin >> testcase;
    for (int i = 0; i < testcase; i++){
        cin >> n;
        pre.assign(n + 1, 0);
        in.assign(n + 1, 0);
        nodeIndex.assign(n + 1, 0);
        for (int j = 1; j <= n ; j++)
            cin >> pre[j];
        for (int j = 1; j <= n ; j++){
            cin >> in[j];
            nodeIndex[in[j]] = j;
        }
        PostOrder(1, 1, n);
        cout << "\n";
    }

    return 0;
}