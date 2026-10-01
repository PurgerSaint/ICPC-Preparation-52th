'''
import sys 
list_1 = list(map(int, input().split()))
k = int(input())
list_1.sort()
num_1 = (list_1[3] + 1) * 4 
num_2 = k - num_1 
ans = 0
if num_2 - 1 > list_1[2]:
    ans = 1
elif num_2 - list_1[0] - 1 > list_1[1]:
    ans = 2
else:
    ans = 0
if ans == 1:
    print("YES")
    list_2 = [(list_1[3] + 1)] * 4 + [num_2 - 1, 1]
    print(*list_2)
elif ans == 2:
    print("YES")
    list_2 = [(list_1[3] + 1)] * 4 + [num_2 - list_1[0] - 1, list_1[0] + 1]
    print(*list_2)
else:
    print("NO")'''


import sys 
list_1 = list(map(int, input().split()))
k = int(input())
list_1.sort()
list_2 = [0] * 6
list_3 = [0] * 6 
dict_1 = {}
list_4 = []
for i in range(6):
    list_2[i] = list_1[i] + 1
for i in range(6):
    num_1 = 0
    for j in range(6):
        if list_1[j] < list_2[i]:
            num_1 += 1
    dict_1[list_2[i]] = num_1

def dfs(x, ans):
    if ans >= 19:
        global list_4
        if sum(list_3) <= k:
            list_4 = list_3[: x] + [1] * (6 - x)
        return 
    if x >= 6:
        if ans >= 19:
            if sum(list_3) <= k:
                list_4 = list_3[::]
            # print(list_3)
        return 
    for i in range(6):
        list_3[x] = list_2[i]
        dfs(x + 1, ans + dict_1[list_2[i]])

dfs(0, 0)

if sum(list_4) <= k and list_4:
    print("YES")
    num_3 = k - sum(list_4)
    if num_3 == 0:
        print(*list_4)
    else:
        list_4[-1] += num_3
        print(*list_4)
else:
    print("NO")





















