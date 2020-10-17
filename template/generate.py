#!/usr/bin/env python3

"""
https://online-judge-tools.readthedocs.io/en/master/introduction.ja.html

$ oj g/i ./generate.py
$ oj g/o -c ./tle.out  
"""

import random
N = random.randrange(1, 101)
W = random.randrange(1, 10001)
print(N, W)
for _ in range(N):
    v = random.randrange(1, 1001)
    w = random.randrange(1, 1001)
    print(v, w)
