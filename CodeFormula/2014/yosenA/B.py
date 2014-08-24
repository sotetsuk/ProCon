a, b = [int(x) for x in raw_input().split()]
p = [int(x) for x in raw_input().split()]
q = [int(x) for x in raw_input().split()]

output = [["x", " ", "x", " ", "x", " ", "x"],
          [" ", "x", " ", "x", " ", "x", " "],
          [" ", " ", "x", " ", "x", " ", " "],
          [" ", " ", " ", "x", " ", " ", " "]]

dic1 = [0, 3, 2, 2, 1, 1, 1, 0, 0, 0]
dic2 = [6, 3, 2, 4, 1, 3, 5, 0, 2, 4]

for s in p:
    output[dic1[s]][dic2[s]] = '.'

for t in q:
    output[dic1[t]][dic2[t]] = 'o'

for line in output:
    print ''.join(line)
