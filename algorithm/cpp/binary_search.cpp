// Created By:      ZhongZiyuan <zzy.albert@163.com>
// Created Time:    2016-04-12 22:22:49
// Modified Time:   2016-07-06 21:46:16

#include <iostream>
using namespace std;

int binary_search(int *arr, int len, int value)
{
    if (NULL == arr || len <= 0)
        return -1;

    int left = 0;
    int right = len-1;
    
    while (left<=right)
    {
        int middle = left + ((right-left)>>1) ;
        if (arr[middle] > value)
            right = middle - 1;
        else if (arr[middle] < value)
            left = middle + 1;
        else
            return middle;
    }

    return -1;
}

/****************************  TEST  ******************************/

void print(int *arr, int len)
{
    for (int i=0; i<len; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(int argc, char *argv[]) {
    int arr[] = {1,3,4,7,9,12,16,23,27,34,35,45,47,51,55,67};
    int len = 16;
    cout << "Searching the list: ";
    print(arr, len);
    int value = 0;
    cout << endl << "Please input the num to search: " ;
    while (cin >> value)
    {
        int index = binary_search(arr, len, value);
        if (-1 == index)
            cout << value << " is not in the list!" << endl;
        else
            cout << "The index of "<< value <<" is " << index << endl;
        cout << endl << "Please input the num to search: " ;
    }
    return 0;
}

