import sys
from heapq import heapify, heappush


def dijsktra(graph, src, dest):
    node_data = {}
    inf = sys.maxsize
    for i in range(1, len(graph) + 1):
        a = str(i)
        node_data[a] = {'cost': inf, 'pred': []}
    node_data[src]['cost'] = 0
    visited = []
    temp = src
    # for i in range(len(graph) - 1):
    while temp != dest:
        if temp not in visited:
            visited.append(temp)
            min_heap = []
            for j in graph[temp]:
                if j not in visited:
                    cost = node_data[temp]['cost'] + graph[temp][j]
                    if cost < node_data[j]['cost']:
                        node_data[j]['cost'] = cost
                        node_data[j]['pred'] = node_data[temp]['pred'] + list(temp)
                    heappush(min_heap, (node_data[j]['cost'], j))

        heapify(min_heap)
        temp = min_heap[0][1]

    print("Shortest Distance: " + str(node_data[dest]['cost']))
    print("Shortest Path: " + str(node_data[dest]['pred'] + list(dest)))


graph = {'1': {'2': 7, '3': 14}, '2': {'1': 2, '3': 3, '4': 8}, '3': {'1': 4, '2': 3, '5': 5, '4': 2},
         '4': {'2': 8, '3': 2, '5': 11, '6': 22}, '5': {'3': 5, '4': 11, '6': 1}, '6': {'4': 22, '5': 1}}

source = '1'
destination = '4'
dijsktra(graph, source, destination)
