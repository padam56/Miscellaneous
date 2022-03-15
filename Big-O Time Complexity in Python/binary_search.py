def binary_search(arr, first, last, x, count = 0):
    if last >= first:
        mid = (last+first) // 2 # add a breakpoint
        if arr[mid] == x:
            return mid, count
        elif x < arr[mid]:
            count += 1
            return binary_search(arr, first, mid-, x, count)
        else:
            count += 1
            return binary_search(arr, mid+1, last, x, count)
    else:
        return -1, count

#Time complexity: O(logN)
