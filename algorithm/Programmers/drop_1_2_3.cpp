#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

struct NodeInfo{
    int min;
    int max;
};

using namespace std;

bool emptyNodeInfo(NodeInfo nodeInfo){
    return nodeInfo.min == 0 && nodeInfo.max == 0;
}

vector<int> findLeafNode(map<int, vector<int>> &edge){
    vector<int> leafNodes;
    queue<int> q;

    q.push(1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for (int child : edge[node]){
            if (edge[child].empty())
                leafNodes.push_back(child);
            else
                q.push(child);
        }
    }

    return leafNodes;
}

bool findNodeInfo(int node, map<int, vector<int>> &edge, vector<NodeInfo> &nodesInfo){
    if (edge[node].empty())
        return true;

    if (emptyNodeInfo(nodesInfo[node])){
        int minN = 0, maxN = 2147483647;
        vector<NodeInfo> nodesMinMax;

        for (int child : edge[node]){
            if (emptyNodeInfo(nodesInfo[child])){
                findNodeInfo(child, edge, nodesInfo);
            }
            nodesMinMax.push_back(nodesInfo[child]);
        }

        int i = 0, size = edge[node].size();
        while (true){
            if (nodesMinMax[i  % size].max == 0){
                maxN = i;
                break;
            }
            nodesMinMax[i % size].min--;
            nodesMinMax[i % size].max--;
            i++;
            if (nodesMinMax[(i - 1) % size].min == 0){
                minN = i;
            }
        }

        for (int i = 0; i < size; i++){
            int child = edge[node][i];
            if (nodesInfo[child].min > minN / size + (i < minN % size))
                return false;
            if (nodesInfo[child].max < maxN / size + (i < maxN % size))
                return false;
        }
        nodesInfo[node].min = minN;
        nodesInfo[node].max = maxN;
    }

    return true;
}

vector<NodeInfo> calculateNodeInfo(vector<int> &target, map<int, vector<int>> &edge, vector<int> &leafNodes){
    NodeInfo nodeInfo;
    nodeInfo.min = 0, nodeInfo.max = 0;
    vector<NodeInfo> nodesInfo(target.size(),nodeInfo);

    for (int node : leafNodes){
        if (target[node] == 0)
            continue;
        nodesInfo[node].min = target[node] < 3 ? 1 : target[node] / 3 + (target[node] % 3 != 0);
        nodesInfo[node].max = target[node];
    }

    if (!findNodeInfo(1, edge, nodesInfo))
        nodesInfo.clear();

    return nodesInfo;
}

int dropNumber(map<int, vector<int>> &edge, int targetSize, vector<int> &times){
    int node = 1;

    while (!edge[node].empty()){
        int dir = times[node];
        times[node]++;
        int childCnt = edge[node].size();
        node = edge[node][dir % childCnt];
    }

    return node;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    target.insert(target.begin(), 0);

    map<int, vector<int>> edge;
    for (vector<int> nodes : edges)
        edge[nodes[0]].push_back(nodes[1]);
    for (auto &node : edge)
        sort(node.second.begin(), node.second.end());

    vector<int> leafNodes = findLeafNode(edge);

    vector<NodeInfo> nodesInfo = calculateNodeInfo(target, edge, leafNodes);
    if (nodesInfo.empty()){
        answer.push_back(-1);
        return answer;
    }
//    [print]
//    for (int i = 1; i < nodesInfo.size(); i++)
//        cout << i << ":" << "["<<nodesInfo[i].min << " " << nodesInfo[i].max << "] ";
//    cout << endl;

    vector<int> rooms(target.size(), 0);
    vector<int> times(target.size(), 0);
    for (int i = 0; i < nodesInfo[1].min; i++)
        rooms[dropNumber(edge, target.size(), times)]++;

    vector<int> numbers;
    vector<vector<int>> nums(target.size(), numbers);
    for (int i = 1; i < rooms.size(); i++){
        if (rooms[i] == 0) continue;
        nums[i].assign(rooms[i], 1);

        int limit = target[i] - rooms[i];
        int j = nums[i].size() - 1;

        while (limit > 0){
            if (nums[i][j] < 3){
                nums[i][j]++;
                limit--;
            }
            else
                j--;
        }
    }
    times.assign(target.size(), 0);
    for (int i = 0; i < nodesInfo[1].min; i++){
        int node = dropNumber(edge, target.size(), times);
        int number = nums[node].front();
        nums[node].erase(nums[node].begin());
        answer.push_back(number);
    }

    return answer;
}

//1. 일단 분할정복으로 리프부터 올라가면서 최대 최소 구하기
//2. 루트에서 가장 최적의 개수 구하기
//3. 시행하면서 어떤 리프에 몇번 도달하는지 체크
//4. 리프에 가능한 크기만큼 1로 채우고 남은 개수를 마지막 칸에서부터 1개씩 쌓기(최대 3개)
//5. 다시 개수만큼 돌리면서 리프의 가장 작은 숫자를 answer에 푸쉬.끝.!

int main()
{
    vector<vector<int>> edge = {{2, 4}, {1, 2}, {6, 8}, {1, 3}, {5, 7}, {2, 5}, {3, 6}, {6, 10}, {6, 9}};
    vector<int> target = {0, 0, 0, 3, 0, 0, 5, 1, 2, 3};
//    vector<vector<int>> edge = {{1, 2}, {1, 3}};
//    vector<int> target = {0,7,3};

    vector<int> result = solution(edge, target);
    for (int n : result){
        cout << n << " ";
    }

    return 0;
}