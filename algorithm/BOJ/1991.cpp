#include <iostream>
#include <map>

using namespace std;
void Preorder(char node);
void Inorder(char node);
void Postorder(char node);

map<char, pair<char, char>> tree;
int main()
{
    int N;

    cin >> N;
    char nodeName, leftChild, rightChild;
    for (int i = 0; i < N; i++){
        cin >> nodeName >> leftChild >> rightChild;
        tree[nodeName] = make_pair(leftChild, rightChild);
    }
    Preorder('A');
    cout << "\n";
    Inorder('A');
    cout << "\n";
    Postorder('A');

    return 0;
}

void Preorder(char node)
{
    cout << node;
    if (tree[node].first != '.')
        Preorder(tree[node].first);
    if (tree[node].second != '.')
        Preorder(tree[node].second);
}

void Inorder(char node)
{
    if (tree[node].first != '.')
        Inorder(tree[node].first);
    cout << node;
    if (tree[node].second != '.')
        Inorder(tree[node].second);
}

void Postorder(char node)
{
    if (tree[node].first != '.')
        Postorder(tree[node].first);
    if (tree[node].second != '.')
        Postorder(tree[node].second);
    cout << node;
}
