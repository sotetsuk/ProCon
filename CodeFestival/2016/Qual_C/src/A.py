s = input()

c_exists = False
f_exists = False
for c in s:
    if c == 'C' and not c_exists:
        c_exists = True
    if c_exists and c == 'F' and not f_exists:
        f_exists = True

if c_exists and f_exists:
    print("Yes")
else:
    print("No")