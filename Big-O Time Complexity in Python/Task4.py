from plot import plot
from linear_search import linear_search

import random
# Create and analyze the linear search function
arr = [ 2, 3, 4, 10, 40, 60, 80, 100]
x = 100

# Function call
size = []
iters = []
for i in range(10):
    result,count = linear_search(arr, x)

    iters.append (count)
    size.append (len(arr))
    if result != -1:
       print("Element is present at index", str(result))
    else:
       print("Element is not present in array")
    print("The array of size ", len(arr), "took ", count, "iterations")
    arr+=arr
    arr[len(arr) -1 ] = 1000 + i
    x = 1000 + i

plot (size, iters)

# Every time our array size increases the iteration, a repeat count follows it, the same as the size.
# So for an N of 500 the count is 500. For an N of 1000, the count is 1000 and so on, all the way up to 4000.
# So the iteration count matches the size, which is N.
# This means that the the linear search has a big O of N, O(n).
