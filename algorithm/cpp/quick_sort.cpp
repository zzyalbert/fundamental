// Created By:      ZhongZiyuan <zzy.albert@163.com>
// Created Time:    2016-04-12 22:22:49
// Modified Time:   2016-04-20 10:02:02

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

int partition1(int *arr, int begin, int end)
{
    int i, j;
    for(i=j=begin+1;j<=end;j++ )
    {
        if(arr[begin]>arr[j])
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    int mid = i-1;
    swap(arr[begin],arr[mid]);
    return mid;
}

int partition2(int* arr, int begin, int end)
{
    int i=begin+1, j=end;
    while(i<j)
    {
        while(arr[i]<=arr[begin]) i++;
        while(arr[j]>arr[begin]) j--;
        if(i<j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[begin], arr[j]);
    return j;
}

void quick_sort(int *arr, int begin, int end)
{
    if(NULL == arr || begin >= end || begin < 0 || end < 0)
        return;
    int mid = partition2(arr, begin, end);
    quick_sort(arr, begin, mid-1);
    quick_sort(arr, mid+1, end);
}

void print(int *arr, int len)
{
    for(int i=0; i<len; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(int argc, char *argv[]) {
    int arr[] = {2,2,2,2,5,3,76,12,33,5,5,5};
    print(arr, 12);
    quick_sort(arr, 0, 11);
    print(arr, 12);
    return 0;
}

