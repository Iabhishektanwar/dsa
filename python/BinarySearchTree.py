class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insertNode(head, data):
    if head is None:
        head = Node(data)
        return head
    if head.data < data:
        head.right = insertNode(head.right, data)
    else:
        head.left = insertNode(head.left, data)
    return head


def inOrderTraversal(head):
    if head is None:
        return
    else:
        inOrderTraversal(head.left)
        print(head.data, end=" ")
        inOrderTraversal(head.right)


def printLeafNodes(head):
    if head is None:
        return
    if head.left is None and head.right is None:
        print(head.data, end=", ")
        return
    if head.left is not None:
        printLeafNodes(head.left)
    if head.right is not None:
        printLeafNodes(head.right)


if __name__ == "__main__":
    # rootNode = Node(100)
    head = None
    rootNode = insertNode(head, 100)
    # inOrderTraversal(rootNode)

    insertNode(rootNode, 80)
    insertNode(rootNode, 50)
    insertNode(rootNode, 90)
    insertNode(rootNode, 30)
    insertNode(rootNode, 60)
    insertNode(rootNode, 90)
    insertNode(rootNode, 85)
    insertNode(rootNode, 95)
    insertNode(rootNode, 120)
    insertNode(rootNode, 110)
    insertNode(rootNode, 108)
    insertNode(rootNode, 115)
    insertNode(rootNode, 140)
    insertNode(rootNode, 150)
    # inOrderTraversal(rootNode)
    printLeafNodes(rootNode)
