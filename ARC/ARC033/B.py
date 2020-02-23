Na, Nb = [int(x) for x in raw_input().split()]
A = set([int(x) for x in raw_input().split()])
B = set([int(x) for x in raw_input().split()])

print 1. * len(A.intersection(B)) / len(A.union(B))
