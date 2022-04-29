def mergeSort(elements, key, descending):
    if len(elements) <= 1:
        return
    else:
        mid = len(elements) // 2
        L = elements[:mid]
        R = elements[mid:]

        mergeSort(L, key, descending)
        mergeSort(R, key, descending)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i][key] < R[j][key]:
                elements[k] = L[i]
                i += 1
            else:
                elements[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            elements[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            elements[k] = R[j]
            j += 1
            k += 1

    if descending == "True":
        c = elements[::-1]
        print(c)
    #
        for i in range(len(elements)):
            elements[i] = c[i]


if __name__ == "__main__":
    elements = [
        {'name': 'vedanth', 'age': 17, 'time_hours': 1},
        {'name': 'rajab', 'age': 12, 'time_hours': 3},
        {'name': 'vignesh', 'age': 21, 'time_hours': 2.5},
        {'name': 'chinmay', 'age': 24, 'time_hours': 1.5},
    ]
    mergeSort(elements, key="age", descending="True")
    print(elements)
