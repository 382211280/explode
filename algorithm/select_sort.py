#coding=utf-8
def select_sort(arr):
    for i in range(len(arr)-1):#选举i为最小值索引
        minIndex = i
        for j in range(i+1,len(arr)):#从i的下一位选取索引
            if arr[j] < arr[minIndex]:
                minIndex = j    #选举j为重新的最小值索引
            # i不是最小值索引 将 i和最小数进行交换
        if i!=minIndex:
            arr[i],arr[minIndex] = arr[minIndex],arr[i]
    return arr

if __name__ == "__main__":
    arr = [231,342,3123,43,564,32131]
    print(arr)
    select_sort(arr)
    print(arr)