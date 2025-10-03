#include <iostream>
#include <string>

using namespace std;

int manhattanDist(int x, int y, int r, int c){
    return abs(r - x) + abs(c - y);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    if (manhattanDist(x, y, r, c) % 2 != k % 2 || manhattanDist(x, y, r, c) > k)
        return "impossible";

    string answer = "";

    int dist = k;
    int px = x, py = y;
    while (dist > manhattanDist(px, py, r, c)){
        while (dist > manhattanDist(px, py, r, c) && px < n) {
            px++;
            dist--;
            answer += "d";
        }
        while (dist > manhattanDist(px, py, r, c) && py > 1){
            py--;
            dist--;
            answer += "l";
        }
        if (dist > manhattanDist(px, py, r, c) && py < m){
            py++;
            dist--;
            answer += "r";
        }
    }

    //d,l,r,u
    //하,좌,우,상
    if (r - px > 0) for (int i = 0; i < r - px; i++) answer += "d";
    if (py - c > 0) for (int i = 0; i < py - c; i++) answer += "l";
    if (c - py > 0) for (int i = 0; i < c - py; i++) answer += "r";
    if (px - r > 0) for (int i = 0; i < px - r; i++) answer += "u";

    return answer;
}

int main()
{
    //int n = 3, m = 4, x = 2, y = 3, r = 3, c = 1, k = 5;
    //int n = 2, m = 2, x = 1, y = 1, r = 2, c = 2, k = 2;
    int n = 3, m = 3, x = 1, y = 2, r = 3, c = 3, k = 4;

    cout << solution(n, m, x, y, r, c, k);

    return 0;
}