from collections import deque
N, *I = map(int, open(0).read().split())
I.reverse()
deq = deque()

instructions = {
    1: lambda: deq.appendleft(I.pop()),
    2: lambda: deq.append(I.pop()),
    3: lambda: print(deq.popleft() if deq else -1),
    4: lambda: print(deq.pop() if deq else -1),
    5: lambda: print(len(deq)),
    6: lambda: print(1 if not deq else 0),
    7: lambda: print(deq[0] if deq else -1),
    8: lambda: print(deq[-1] if deq else -1)
}

while I: instructions[I.pop()]()