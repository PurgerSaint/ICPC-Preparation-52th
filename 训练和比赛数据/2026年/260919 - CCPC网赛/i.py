'''
list_1 = [0] * 10000000

for a in range(-100, 100):
    for b in range(-100, 100):
        for c in range(-100, 100):
            n = a * b * (a + b) + b * c * (b + c) + a * c * (a + c)
            if n == 2:
                print(a, b, c, n)
            if n == 4:
                print(a, b, c, n)
            list_1[n] = 1


print(list_1[:100])
for i in range(1000):
    if not list_1[i]:
        print(i)'''


for i in range(1, 10):
    a = -1
    b = 1
    c = i 
    n = a * b * (a + b) + b * c * (b + c) + a * c * (a + c)
    print(n, c)















