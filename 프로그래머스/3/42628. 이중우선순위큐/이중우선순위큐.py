from heapq import heappush, heappop
def solution(operations):
    answer = []
    maxheap, minheap = [], []
    for i in operations:
        operator, operand = i.split()
        if operator == "I":
            heappush(maxheap, -int(operand))
            heappush(minheap, int(operand))
        else:
            if not minheap:
                pass
            elif operand == "1":
                minheap.remove(-heappop(maxheap))
            elif operand == "-1":
                maxheap.remove(-heappop(minheap))
        print(maxheap, minheap)
    return [-heappop(maxheap), heappop(minheap)] if maxheap else [0, 0]