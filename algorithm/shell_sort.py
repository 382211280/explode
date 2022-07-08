#coding=utf-8

import math
def shell_sort(arr):
    gap=1
    while(gap<len(arr)/3):
        gap = gap*3
    while gap>0:
        for i in range(gap,len(arr)):
            temp = arr[i]
            j = i-gap
            while j >= 0 and arr[j]>temp:
                arr[j+gap]=arr[j]
                j-=gap
            arr[j+gap]=temp
        gap=math.floor(gap/3)
        print(gap)
    return arr
if __name__ == "__main__":
    arr=[12,32,321,31243,312,31]
    print(arr)
    shell_sort(arr)
    print(arr)