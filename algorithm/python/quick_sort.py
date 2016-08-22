#!/usr/bin/env python
# coding=utf-8
# Created By:      ZhongZiyuan <zzy.albert@163.com>
# Created Time:    2016-04-12 22:16:51
# Modified Time:   2016-08-22 11:34:11
import random

def partition(arr, begin, end):
    r = random.randint(begin, end)
    arr[begin], arr[r] = arr[r], arr[begin]
    mid = begin
    for i in range(begin+1, end+1):
        if arr[begin] > arr[i]:
            mid += 1
            arr[mid], arr[i] = arr[i], arr[mid]
    arr[begin], arr[mid] = arr[mid], arr[begin]
    return mid
def quick_sort(arr, begin, end):
    if None == arr or begin <0 or begin >= end:
        return
    mid = partition(arr, begin, end)
    quick_sort(arr, begin, mid-1)
    quick_sort(arr, mid+1, end)

if __name__ == "__main__":
    a = [2,3,2,5,6,2,21,12,44,5]
    print a
    quick_sort(a, 0 , 9)
    print a


