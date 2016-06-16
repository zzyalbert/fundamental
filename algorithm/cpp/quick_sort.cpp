// Created By:      ZhongZiyuan <zzy.albert@163.com>
// Created Time:    2016-04-12 22:22:49
// Modified Time:   2016-06-16 13:28:15

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
    int mid = begin;
    for (int i = begin; i <= end; i++ )
    {
        if (arr[begin]>=arr[i])
        {
            swap(arr[mid],arr[i]);
            mid++;
        }
    }
    mid -= 1;
    swap(arr[begin],arr[mid]);
    return mid;
}

int partition2(int* arr, int begin, int end)
{
    int i=begin, j=end;
    while(i<j)
    {
        while(i<end && arr[i]<=arr[begin]) i++;
        while(j>begin && arr[j]>arr[begin]) j--;
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
    int mid = partition1(arr, begin, end);
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
    int arr[] = {2,4,21,2,2,15,3,76,52,52,30,12,33,5,5,5};
    int len = 16;
    print(arr, len);
    quick_sort(arr, 0, len-1);
    print(arr, len);
    return 0;
}

