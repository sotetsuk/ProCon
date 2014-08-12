from Queue import PriorityQueue
import math

s = raw_input()

n_kaburin = 5
c = 0
kaburin_op = PriorityQueue()
damage_op = PriorityQueue()
t = 0

def normal_throw():
    global n_kaburin
    if n_kaburin < 1:
        return
    print "N"
    n_kaburin -= 1
    kaburin_op.put((t+0.5+1.0+5.0, +1))
    damage_op.put((t+0.5+1.0, 10))

def tame_throw():
    global t, n_kaburin
    if n_kaburin < 3:
        return
    print "C"
    n_kaburin -= 3
    t += 2
    kaburin_op.put((t+2.5+1.0+5.0, +3))
    damage_op.put((t+2.5+1.0, 50))

def calculate_damage(a):
    return a * (1 + math.floor(c/10) * 0.1)


k = None
d = None

ans = 0
while True:
    # print t
    ## print d
    if t >= len(s) and damage_op.empty():
        break
    while not kaburin_op.empty():
        if k is None:
            k = kaburin_op.get()

        if k[0]+1 < t:
            n_kaburin += k[1]
            k = None
        else:
            break

    while not damage_op.empty():
        if d is None:
            d = damage_op.get()
        if d[0]+1 < t:
            ## print "debug damage"
            ## print d
            ans += calculate_damage(d[1])
            c += 1
            d = None
        else:
            break

    if t < len(s):
        command = s[t]

        if command == 'N':
            normal_throw()
        elif command == 'C':
            tame_throw()

    t += 1

if d is not None:
    ans += calculate_damage(d[1])

print ans
