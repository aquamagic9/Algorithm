#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Fish{
public:
    int x;
    int y;
    int size;
    Fish(){
        x = 0;
        y = 0;
        size = 0;
    }
    Fish(int x, int y, int size){
        this->x = x;
        this->y = y;
        this->size = size;
    }
};

class MyFish : public Fish{
public:
    int feedCnt;
    MyFish(){
        Fish();
        this->feedCnt = 0;
    }
    void EatFeed(const Fish &fish){
        x = fish.x;
        y = fish.y;
        if (++feedCnt >= size){
            feedCnt = 0;
            size++;
            //cout << "Level Up! " << size << "\n";
        }
    }
};
bool cmp(const Fish &a, const Fish &b){
    if (a.y != b.y)
        return a.y < b.y;
    if (a.x != b.x)
        return a.x < b.x;
    return false;
}
int N;
int arr[20][20] = {0,};
int visit[20][20] = {0,};
vector<Fish> fishes;
MyFish myFish;
bool CanEat()
{
    bool canEat = false;
    for (int i = 0; i < fishes.size(); i++){
        if (fishes[i].size < myFish.size){
            canEat = true;
        }
    }
    return canEat;
}
int FindDistance(const Fish &fish)
{
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1, 0,0};
    queue<pair<int, int>> q;

    for (int i = 0 ; i < N; i++){
        for (int j = 0; j < N; j++){
            visit[i][j] = -1;
        }
    }
    q.push(make_pair(myFish.x, myFish.y));
    visit[myFish.y][myFish.x] = 0;
    while (!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[ny][nx] <= myFish.size && visit[ny][nx] == -1){
                q.push(make_pair(nx, ny));
                visit[ny][nx] = visit[y][x] + 1;
            }
        }
    }
    return visit[fish.y][fish.x];
}
int main()
{
    cin >> N;
    int resultTime = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 6){
                fishes.push_back(Fish(j, i, arr[i][j]));
            }
            if (arr[i][j] == 9){
                arr[i][j] = 0;
                myFish.x = j;
                myFish.y = i;
                myFish.size = 2;
            }
        }
    }
    sort(fishes.begin(), fishes.end(), cmp);
    while(CanEat())
    {
        int minDistance = N * N + 1;
        vector<Fish>::iterator minFish;
        for (auto iter = fishes.begin(); iter != fishes.end(); iter++){
            if ((*iter).size >= myFish.size)
                continue;
            int distance = FindDistance(*iter);
            if (distance == -1){
                continue;
            }
            if (minDistance > distance){
                minDistance = distance;
                minFish = iter;
            }
        }
        if (minDistance == N * N + 1){
            break;
        }
        resultTime += minDistance;
        //cout << "x: " << minFish->x << " y: " << minFish->y << "  " << resultTime << "\n";
        myFish.EatFeed(*minFish);
        arr[minFish->y][minFish->x] = 0;
        fishes.erase(minFish);
    }
    cout << resultTime;

    return 0;
}

