#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H, W;

    cin >> H >> W;
    for (int i = 0; i < H; i++){
        string s;
        cin >> s;
        int cnt = 0;
        bool firstCloud = false;
        for (int j = 0; j < W; j++){
           if (s[j] == 'c'){
               cnt = 0;
               cout << cnt++ << " ";
               firstCloud = true;
           }
           else {
               if (firstCloud == false){
                   cout << "-1 ";
               }
               else {
                   cout << cnt++ << " ";
               }
           }
        }
        cout << "\n";
    }

    return 0;
}