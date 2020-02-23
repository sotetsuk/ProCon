K = int(input())

num_odd = K // 2 if K % 2 == 0 else K // 2 + 1
num_even = K // 2

print(num_odd * num_even)