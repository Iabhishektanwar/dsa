# Add a Node to the set of Nodes and the graph
def add_Node(v):
    global graph
    global noOfNodes
    global Nodes
    if v in Nodes:
        print("Node ", v, " already exists")
    else:
        noOfNodes = noOfNodes + 1
        Nodes.append(v)
        if noOfNodes > 1:
            for Node in graph:
                Node.append(0)
        temp = []
        for i in range(noOfNodes):
            temp.append(0)
        graph.append(temp)


# Add an edge between Node v1 and v2 with edge weight e
def add_edge(v1, v2, e):
    global graph
    global noOfNodes
    global Nodes
    # Check if Node v1 is a valid Node
    if v1 not in Nodes:
        print("Node ", v1, " does not exist.")
    # Check if Node v1 is a valid Node
    elif v2 not in Nodes:
        print("Node ", v2, " does not exist.")
    # Since this code is not restricted to a directed or
    # an undirected graph, an edge between v1 v2 does not
    # imply that an edge exists between v2 and v1
    else:
        index1 = Nodes.index(v1)
        index2 = Nodes.index(v2)
        graph[index1][index2] = e


# Print the graph
def print_graph():
    global graph
    global noOfNodes
    for i in range(noOfNodes):
        for j in range(noOfNodes):
            if graph[i][j] != 0:
                print(Nodes[i], " -> ", Nodes[j],
                      " edge weight: ", graph[i][j])


# Driver code
# stores the Nodes in the graph
Nodes = []
# stores the number of Nodes in the graph
noOfNodes = 0
graph = []
# Add Nodes to the graph
add_Node(1)
add_Node(2)
add_Node(3)
add_Node(4)
# Add the edges between the Nodes by specifying
# the from and to Node along with the edge weights.
add_edge(1, 2, 1)
add_edge(1, 3, 1)
add_edge(2, 3, 3)
add_edge(3, 4, 4)
add_edge(4, 1, 5)
print_graph()
print("Internal representation: ", graph)
