#!/usr/bin/env python3

import random
N = random.randint(1, 3000)
print(N)
s = ""
for _ in range(N):
    n = random.randint(0, 2)
    if n % 3 == 0:
        s += 'R'
    elif n % 3  == 1:
        s += 'G'
    elif n % 3 == 2:
        s += 'B'
print(s)
