#!/usr/bin/env python
# coding=utf-8
# Created By:      ZhongZiyuan <zzy.albert@163.com>
# Created Time:    2016-08-14 23:58:14
# Modified Time:   2016-08-15 17:04:11

def adjust(arr, begin, end):
    big_child = begin*2+1
    if big_child > end:
        return
    if big_child+1 <= end and arr[big_child+1]>arr[big_child]:
        big_child+=1
    if arr[begin] < arr[big_child]:
        arr[begin],arr[big_child] = arr[big_child], arr[begin]
        adjust(arr, big_child, end)

def heap_sort(arr):
    if None == arr or len(arr)<=1:
        return
    begin = 0
    end = len(arr)-1
    for i in range((end-1)/2, begin-1, -1):
        adjust(arr,i,end)
    for i in range(end, begin, -1):
        arr[begin],arr[i] = arr[i],arr[begin]
        adjust(arr, begin, i-1)

if __name__ == "__main__":
    a = [2,3,2,4,12,23,13,44,2,12]
    print a
    heap_sort(a)
    print a

