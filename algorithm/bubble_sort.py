import pwd


def bubble_sort(arr):
    for i in range(1, len(arr)):
        for j in range(0, len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def print_arr(arr):
    print(arr)

if __name__ == "__main__" :
    tmparr = [1,2,34,43,32,231]
    print_arr(tmparr)
    bubble_sort(tmparr)
    print_arr(tmparr)


