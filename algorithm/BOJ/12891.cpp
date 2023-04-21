#include <iostream>
#include <string>
#include <vector>
using namespace std;

void countACGT(vector<int> &acgt, char alpha, bool decrease){
    int add = 1;
    if (decrease)
        add = -1;
    switch (alpha) {
        case 'A':
            acgt[0] += add;
            break;
        case 'C':
            acgt[1] += add;
            break;
        case 'G':
            acgt[2] += add;
            break;
        case 'T':
            acgt[3] += add;
            break;
        default:
            break;
    }
}

bool check(vector<int> &acgt, vector<int> &acgt_count)
{
    for (int i = 0; i < acgt.size(); i++){
        if (acgt[i] > acgt_count[i])
            return false;
    }
    return true;
}

int main()
{
    int S, P;
    vector<int> acgt(4, 0);
    vector<int> acgt_count(4, 0);
    string dna = "";

    cin >> S >> P;
    cin >> dna;
    for (int i = 0; i < P; i++){
        countACGT(acgt_count, dna[i], false);
    }
    for (int i = 0; i < acgt.size(); i++){
        cin >> acgt[i];
    }

    int index = 0, cnt = 0;
    while (index + P <= S){
/*        cout << dna.substr(index, P) << endl;
        for (int i= 0 ;i < 4; i++)
            cout << acgt_count[i] << " ";
        cout  << endl;*/
        if(check(acgt, acgt_count))
            cnt++;
        countACGT(acgt_count, dna[index], true);
        if (index + P < S)
            countACGT(acgt_count, dna[index + P], false);
        index++;
    }
    cout << cnt;

    return 0;
}