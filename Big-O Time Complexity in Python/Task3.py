from bubble_sort import bubble_sort
from plot import plot
arr = [10, 8, 6, 4, 2, 1]
x = 100
size = []
iters = []
for i in range(10):
    # Create the Bubblesort function
    # populate the array in reverse order (worst case)
    for j in range(len(arr)):
        arr[j] = len(arr) - j # reverses the data in the array
    result, count = bubble_sort(arr)
    iters.append (count)
    size.append (len(arr))
    print("The array of size ", len(arr), "took ", count, "iterations")
    arr+=arr #Doubling the array each time through

plot (size, iters)
