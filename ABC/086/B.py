a, b = input().split()

x = int(a + b)

i = 1
while i ** 2 <= x:
    if i ** 2 == x:
        print("Yes")
        exit()
    i += 1

print("No")
