from return_element import return_element

import random
from plot import plot
arr = [10, 8, 6, 4, 2, 1]
x = 100
size = []
iters = []
for i in range(10):
    # task 2: create the return_element function
    # gen a random index into the array
    index = random.randint(0,len(arr)-1)
    result, count = return_element(arr, index)
    iters.append (count)
    size.append (len(arr))

    arr+=arr

plot (size, iters)

# We have a constant value here. No matter how large the array gets all the way up to 3000. The number of iterations is always one. In other words, the Big O for the return element function is O(1). It is O(1) because it is just a single statement that accesses an array element in the function. We could have three single statements in there. We'd still call it a O(1) because it's a constant time. No matter how large the array is, the time is the same.
