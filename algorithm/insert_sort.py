# coding=utf-8
def insert_sort(arr):
    for i in range(len(arr)):
        preIndex = i-1
        current = arr[i]
        while preIndex >= 0 and arr[preIndex] > current:
            arr[preIndex+1] = arr[preIndex]
            preIndex -= 1
            arr[preIndex+1] = current
    return arr

if __name__ == "__main__":
    arr = [123, 3123, 3214, 423543, 654, 6765324, 4234423, 4234]
    print(arr)
    insert_sort(arr)
    print(arr)
