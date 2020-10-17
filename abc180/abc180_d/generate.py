#!/usr/bin/env python3

"""
https://online-judge-tools.readthedocs.io/en/master/introduction.ja.html

$ oj g/i ./generate.py
# oj g/o -c ./tle.out  
"""

import random
MAX_X = 100000000
MAX_A = 1000
X = random.randint(1, MAX_X)
Y = random.randint(X + 1, MAX_X)
A = random.randint(2, MAX_A)
B = random.randint(1, MAX_A)
print(X, Y, A, B)
