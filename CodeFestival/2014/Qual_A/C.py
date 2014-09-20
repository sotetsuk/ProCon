def is_leap_year(year):
    return year % 4 == 0 and year % 100 != 0 or year % 400 == 0

a, b = [int(x) for x in raw_input().split()]

s = 0
for i in range(a, b + 1):
    if is_leap_year(i):
        s += 1

print s
