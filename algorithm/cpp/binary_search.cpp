// Created By:      ZhongZiyuan <zzy.albert@163.com>
// Created Time:    2016-04-12 22:22:49
// Modified Time:   2016-06-23 19:30:55

#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    if(a == b)
        return;
    a ^= b;
    b ^= a;
    a ^= b;
}


void binary_search(int *arr, int begin, int end)
{
    if (NULL == arr || begin >= end || begin < 0 || end < 0)
        return;
}

/****************************  TEST  ******************************/

void print(int *arr, int len)
{
    for (int i=0; i<len; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(int argc, char *argv[]) {
    int arr[] = {2,4,21,2,2,15,3,76,52,52,30,12,33,5,5,5};
    int len = 16;
    print(arr, len);
    quick_sort(arr, 0, len-1);
    print(arr, len);
    return 0;
}

