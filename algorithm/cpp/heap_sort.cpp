// Created By:      ZhongZiyuan <zzy.albert@163.com>
// Created Time:    2016-04-12 22:22:49
// Modified Time:   2016-06-23 17:06:47

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

/*
int index(int heap_index, int begin)
{
    return heap_index + (begin -1);
}
*/

void adjust_max_heap1(int* arr, int begin, int end)
{
    int i = begin;
    while (i*2 <= end)
    {
        int big_child = i*2;
        if(big_child + 1 <= end && arr[big_child] < arr[big_child+1])
            big_child += 1;
        if(arr[i] < arr[big_child])
            swap(arr[i], arr[big_child]);
        else
            break;
        i = big_child;
    }
}

void adjust_max_heap2(int* arr, int begin, int end)
{
    int big_child = begin * 2;
    
    if (big_child > end)
        return;
    if(big_child+1 <= end && arr[big_child+1]>arr[big_child])
        big_child += 1;
    if(arr[begin]<arr[big_child])
    {   
        swap(arr[begin],arr[big_child]);
        adjust_max_heap2(arr, big_child, end);
    }
}

void heap_sort(int *arr, int begin, int end)
{
    if(NULL == arr || begin >= end || begin != 1)
        return;

    for(int i=end/2; i>=begin; i--)
        adjust_max_heap2(arr, i, end);
    
    for(int i=end; i>begin; i--)
    {
        swap(arr[begin], arr[i]);
        adjust_max_heap2(arr, begin, i-1);
    }
}

/****************************  TEST  ******************************/

void print(int *arr, int len)
{
    for(int i=0; i<len; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(int argc, char *argv[]) {
    int arr[] = {7,4,21,2,2,15,3,76,52,52,30,12,33,5,5,5};
    int len = 16;
    print(arr, len);
    heap_sort(arr, 1, len-1);
    print(arr, len);
    return 0;
}

