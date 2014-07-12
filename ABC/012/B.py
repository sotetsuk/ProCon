N = int(raw_input())

h, m = N/3600, N%3600
m, s = m/60, m%60

print "{:02d}:{:02d}:{:02d}".format(h, m, s)
