def bubble_sort (arr, count = 0):
    for i in range(len(arr)): #create breakpoint
        count+=1
        for j in range(len(arr)-1):
            count+=1
            if arr[j] > arr[j+1]:
                #swap them
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr, count
    # Worst case scenario - See through debugging option in vscode
    # The array of size 3072 took 9437184 iterations - Hence O(n^2), and O(n*m) if two arrays.
