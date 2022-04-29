# def reverseString(str):
#     if str == "":
#         return ""
#     else:
#         return reverseString(str[1:]) + str[0]
#
#
# print(reverseString("Abhishek"))

# def isPalindrome(string):
#     if len(string) == 0 or len(string) == 1:
#         return True
#     if string[0] == string[len(string) - 1]:
#         return isPalindrome(string[1:len(string) - 1])
#     return False
#
#
# print(isPalindrome("racecar"))


# def findBinary(Number, result):
#     if Number == 0:
#         return result
#
#     result = str(Number % 2) + result
#     return findBinary(Number//2, result)
#
#
# print(findBinary(25, ""))


# def sumOfNatruralNumbers(Number):
#     if Number <= 1:
#         return Number
#     return Number + sumOfNatruralNumbers(Number-1)
#
#
# print(sumOfNatruralNumbers(5))

# Iterative Solution
"""
def binarySearch(lst, number):
    low = 0
    high = len(lst) - 1
    while low <= high:
        mid = (low + high ) // 2
        if lst[mid] == number:
            return mid
        if lst[mid] > number:
            high = mid - 1
        else:
            low = mid + 1
    return "Number Not Found"


print(binarySearch([2, 5, 7, 9, 23, 45, 67], 67))
"""

# Recursive Solution
"""
def binarySearch(lst, left, right, number):
    if left > right:
        return -1
    mid = (left + right) // 2
    if number == lst[mid]:
        return mid
    if lst[mid] > number:
        return binarySearch(lst, left, mid - 1, number)
    else:
        return binarySearch(lst, mid + 1, right, number)


A = [2, 5, 7, 9, 23, 45, 67]
print(binarySearch(A, 0, len(A) - 1, 67))
"""


def merge(data, start, mid, end):
    temp = [0 for i in range(len(data))]
    i = start
    j = mid + 1
    k = 0
    while i <= mid and j <= end:
        if data[i] <= data[j]:
            temp[k] = data[i]
            i += 1
            k += 1
        else:
            temp[k] = data[j]
            j += 1
            k += 1

    while i <= mid:
        temp[k] = data[i]
        i += 1
        k += 1
    while j <= end:
        temp[k] = data[j]
        j += 1
        k += 1
    for i in range(start, end + 1):
        data[i] = temp[i-start]


def mergeSort(data, start, end):
    if start < end:
        mid = (start + end) // 2
        mergeSort(data, start, mid)
        mergeSort(data, mid + 1, end)
        merge(data, start, mid, end)


A = [-5, 20, 10, 3, 2, 0]
mergeSort(A, 0, len(A)-1)
print(A)


# def mergeTwoSortedArrays(A, B):
#     result = [0] * (len(A) + len(B))
#     i, j, k = 0, 0, 0
#     while i < len(A) and j < len(B):
#         if A[i] < B[j]:
#             result[k] = A[i]
#             i += 1
#         else:
#             result[k] = B[j]
#             j += 1
#         k += 1
#     while i < len(A):
#         result[k] = A[i]
#         i += 1
#         k += 1
#
#     while j < len(B):
#         result[k] = B[j]
#         j += 1
#         k += 1
#
#     return result
#
#
# print(mergeTwoSortedArrays([2, 5, 7, 9], [1, 3, 6, 8]))
