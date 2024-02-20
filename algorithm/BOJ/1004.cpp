#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Pos{
public:
    int x;
    int y;
    Pos(){
        x = 0;
        y = 0;
    }
    Pos(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class Circle : public Pos{
public:
    int r;
    Circle(){
        Pos();
        this->r = r;
    }
    Circle(int x, int y, int r){
        Pos(x, y);
        this->r = r;
    }
};

float DistanceOfTwoPoints(Pos a, Pos b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool IsInCircle(Circle c, Pos a)
{
    return DistanceOfTwoPoints(c, a) <= c.r;
}

int main()
{
    int test_case;

    cin >> test_case;
    for (int i = 1; i <= test_case; i++)
    {
        Pos start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        int N, result = 0;
        cin >> N;
        Circle circle;
        for (int i = 0; i < N; i++){
            cin >> circle.x >> circle.y >> circle.r;
            if (IsInCircle(circle, start) ^ IsInCircle(circle, end)){
                result++;
            }
        }
        cout << result << "\n";
    }

    return 0;
}