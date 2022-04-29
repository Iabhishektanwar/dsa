class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.val)
        temp = temp.next


def reverseLinkedList(head):
    if head is None or head.next is None:
        return head
    pointer = reverseLinkedList(head.next)
    head.next.next = head
    head.next = None
    return pointer


def reverse(head):
    pointer = None
    while head!= None:
        nextnode = head.next
        head.next = pointer
        pointer = head
        head = nextnode
    return pointer


if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)

    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5

    printLinkedList(n1)
    # rev = reverseLinkedList(n1)
    # printLinkedList(rev)
    rev = reverse(n1)
    print(rev)

