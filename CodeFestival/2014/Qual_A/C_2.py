def num_leap_years(a):
    ret = 0
    ret += a / 4
    ret -= a / 100
    ret += a / 400

    return ret

def is_leap_year(year):
    return year % 4 == 0 and year % 100 != 0 or year % 400 == 0

a, b = [int(x) for x in raw_input().split()]

if is_leap_year(a):
    print num_leap_years(b) - num_leap_years(a) + 1
else:
    print num_leap_years(b) - num_leap_years(a)
