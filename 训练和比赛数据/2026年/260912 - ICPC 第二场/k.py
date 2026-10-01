import sys
from copy import deepcopy
nums = []
for _ in range(int(input())):
    n = int(input())
    list_1 = list(map(int, input().split()))
    q = int(input())
    dict_1 = {}
    ans = []
    ans_1 = 0
    for i in range(n):
        if list_1[i] in dict_1:
            dict_1[list_1[i]] += 1
        else:
            dict_1[list_1[i]] = 1
    for i in range(n + 1):
        if i in dict_1:
            ans_1 = max(ans_1, i + 1)
        else:
            break  
    list_2 = []

    for i in range(q):
        k = int(input())
        dang = ans_1 
        dict_2 = deepcopy(dict_1)
        while k - dang in dict_2 and (dict_2[k - dang] >= 2 or k - dang > dang):
            dict_2[k - dang] -= 1
            dang += 1
        ans.append(dang)
    num_1 = ans[0]
    for i in range(1, len(ans)):
        num_1 ^= ans[i]
    nums.append(num_1) 
for i in range(len(nums)):
    print(nums[i])



        

    





