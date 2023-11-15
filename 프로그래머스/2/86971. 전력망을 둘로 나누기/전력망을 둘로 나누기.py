from collections import Counter
def solution(n, wires):
    answer = n
    wires.sort()
    for wire in wires:
        parent = [i for i in range(n+1)]
        graph = wires.copy()
        graph.remove(wire)
        list(map(lambda x: union(parent, x[0], x[1]), graph))
        list(map(lambda x: find(parent, x), range(n+1)))
        # tree가 둘로 갈라진다면.. 하나는 max, 하나는 n - max이므로 차이는 항상 max*2 - n
        answer = min(max(Counter(parent).values())*2 - n, answer)
        print(parent, answer)
    return answer

def find(parent, v):
    if parent[v] != v:
        parent[v] = find(parent,parent[v])
    return parent[v]

def union(parent, a, b):
    parent[find(parent, a)] = find(parent, b)