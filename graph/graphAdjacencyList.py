# Add a Node to the dictionary
def add_Node(v):
    global graph
    global nodeNo
    if v in graph:
        print("Node ", v, " already exists.")
    else:
        nodeNo = nodeNo + 1
        graph[v] = []


# Add an edge between Node v1 and v2 with edge weight e
def add_edge(v1, v2, e):
    global graph
    # Check if Node v1 is a valid Node
    if v1 not in graph:
        print("Node ", v1, " does not exist.")
    # Check if Node v2 is a valid Node
    elif v2 not in graph:
        print("Node ", v2, " does not exist.")
    else:
        # Since this code is not restricted to a directed or
        # an undirected graph, an edge between v1 v2 does not
        # imply that an edge exists between v2 and v1
        temp = [v2, e]
        graph[v1].append(temp)


# Print the graph
def print_graph():
    global graph
    for Node in graph:
        for edges in graph[Node]:
            print(Node, " -> ", edges[0], " edge weight: ", edges[1])


# driver code
graph = {}
# stores the number of vertices in the graph
nodeNo = 0
add_Node(1)
add_Node(2)
add_Node(3)
add_Node(4)
# Add the edges between the vertices by specifying
# the from and to Node along with the edge weights.
add_edge(1, 2, 1)
add_edge(1, 3, 1)
add_edge(2, 3, 3)
add_edge(3, 4, 4)
add_edge(4, 1, 5)
print_graph()
# Reminder: the second element of each list inside the dictionary
# denotes the edge weight.
print("Internal representation: ", graph)
