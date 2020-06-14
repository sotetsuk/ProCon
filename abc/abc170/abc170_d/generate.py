#!/usr/bin/env python3

"""
https://online-judge-tools.readthedocs.io/en/master/introduction.ja.html

$ oj g/i ./generate.py
# oj g/o -c ./tle.out  
"""

import random
N = random.randint(1, 100)
W = random.randint(1, 10000)
print(N, W)
for _ in range(N):
    v = random.randint(1, 1000)
    w = random.randint(1, 1000)
    print(v, w)
