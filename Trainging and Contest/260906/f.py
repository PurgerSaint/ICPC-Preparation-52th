
n, m = map(int, input().split())
list_1 = []
for i in range(n):
    list_2 = list(map(int, input().split()))
    sum_1 = sum(list_2)
    list_1.append(sum_1)

ans = 1
dang = list_1[0]
for i in range(1, n):
    if list_1[i] < dang:
        ans += 1
    dang = list_1[i]
print(ans)

