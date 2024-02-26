#include <iostream>
using namespace std;

void QuickSort(int *data, int start, int end)
{
    if (start >= end)
        return ;
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    while (i <= j){
        while (data[i] <= data[key]){
            i++;
        }
        while (data[j] >= data[key] && j > start){
            j--;
        }
        if (i > j){
            temp = data[key];
            data[key] = data[j];
            data[j] = temp;
        }
        else {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    QuickSort(data, start, j - 1);
    QuickSort(data, j + 1, end);
}


int main()
{
    int a[10] = { 2,3,1,4,9,7,6,5,8,0};

    QuickSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << " " << a[i];
    return 0;
}