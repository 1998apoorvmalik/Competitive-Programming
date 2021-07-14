#!/bin/python3

import os
import copy
from collections import defaultdict

#
# Complete the 'lilysHomework' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#


def findSwaps(sorted_arr, unsorted_arr):
    arr_value_index_map = defaultdict(lambda: [])
    n_swaps = 0

    # mapping each value of the sorted array to its corresponding index
    for i, e in enumerate(sorted_arr):
        arr_value_index_map[e].append(i)

    # finding number of swaps to convert the unsorted array to sorted
    for i in range(len(unsorted_arr)):
        while(unsorted_arr[i] != sorted_arr[i]):
            j = arr_value_index_map[unsorted_arr[i]].pop()
            unsorted_arr[i], unsorted_arr[j] = unsorted_arr[j], unsorted_arr[i]
            n_swaps += 1

    return n_swaps


def lilysHomework(arr):
    unsorted_arr = copy.copy(arr)
    unsorted_arr_rev = copy.copy(arr)
    arr.sort()
    sorted_arr = copy.copy(arr)
    sorted_arr_rev = copy.copy(arr[::-1])

    # find number of swaps to convert the unsorted array to both sorted
    # and reverse sorted arrays
    n_swaps = findSwaps(sorted_arr, unsorted_arr)
    n_swaps_rev = findSwaps(sorted_arr_rev, unsorted_arr_rev)

    # return whatever is minimum.
    return min(n_swaps, n_swaps_rev)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = lilysHomework(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
