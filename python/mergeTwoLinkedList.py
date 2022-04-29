class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.val, end=" ")
        temp = temp.next


def mergeSortedLinkedList(A, B):
    if A is None:
        return B
    if B is None:
        return A
    if A.val <= B.val:
        A.next = mergeSortedLinkedList(A.next, B)
        return A
    else:
        B.next = mergeSortedLinkedList(A, B.next)
        return B


if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(8)
    n3 = Node(22)
    n4 = Node(40)

    n1.next = n2
    n2.next = n3
    n3.next = n4

    a1 = Node(4)
    a2 = Node(11)
    a3 = Node(16)
    a4 = Node(20)

    a1.next = a2
    a2.next = a3
    a3.next = a4

    # printLinkedList(n1)
    # printLinkedList(a1)

    # mergedlist = mergeSortedLinkedList(n1, a1)
    printLinkedList(mergeSortedLinkedList(n1, a1))
