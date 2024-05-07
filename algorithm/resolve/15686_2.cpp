#include <iostream>
#include <vector>
using namespace std;

struct Pos{
    int x;
    int y;
};

int N, M, resultDistance;
const int house = 1;
const int chickenHouse = 2;

vector<Pos> houses;
vector<Pos> chickenHouses;

int chickenDistance(const vector<int> &v){
    int result = 0;
    for (int i = 0; i < houses.size(); i++){
        int minDistance = N * N;
        for (int j = 0; j < v.size(); j++){
            int distance = abs(houses[i].x - chickenHouses[v[j]].x) + abs(houses[i].y - chickenHouses[v[j]].y);
            minDistance = min(minDistance, distance);
        }
        result += minDistance;
    }
    return result;
}

void combi(const int start, vector<int> &v, const int size)
{
    if (v.size() == size){
        resultDistance = min(resultDistance, chickenDistance(v));
        return;
    }
    for (int i = start + 1; i < chickenHouses.size(); i++)
    {
        v.push_back(i);
        combi(i, v, size);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;


    int num;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> num;
            if (num == house){
                houses.push_back({j, i });
            }
            else if (num == chickenHouse){
                chickenHouses.push_back({j, i });
            }
        }
    }
    resultDistance = N * N * houses.size();

    for (int i = 1; i <= M; i++){
        vector<int> v;
        combi(-1, v, i);
    }
    cout << resultDistance;

    return 0;
}