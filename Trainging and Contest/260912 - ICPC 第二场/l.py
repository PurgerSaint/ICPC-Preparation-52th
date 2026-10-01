'''ans = []
for _ in range(int(input())):
    n = int(input())
    list_1 = list(map(int, input().split()))
    list_1 = list_1[::-1]
    dp = [0] * n
    dp[-1] = list_1[-1]
    for i in range(n - 2, -1, -1):
        dp[i] = dp[i + 1] + list_1[i]
    
    num_1 = 0
    while num_1 < n - 1:
        list_2 = [0] * n
        for i in range(n):
            list_2[i] = list_1[(i + 1) % n]
        dp_1 = list_2[::]
        
        for i in range(n - 1, -1, -1):
            if i + 1 < n:
                dp_1[i] = min(dp[i], dp_1[i + 1]) + dp_1[i]
            else:
                dp_1[i] = dp[i] + dp_1[i]

        dp = dp_1[::]
        list_1 = list_2[::]
        num_1 += 1
    ans.append(dp[0])
for i in range(len(ans)):
    print(ans[i])'''
    

ans = []
for _ in range(int(input())):
    n = int(input())
    list_1 = list(map(int, input().split()))
    list_2 = [0] * n 
    for i in range(n):
        list_2[(i + 1) % n] = list_1[i]
    dang = 0
    ans_1 = 10** 9 + 10
    for i in range(n):
        num_1 = list_1[i] * (n - i) + list_1[(i + 1) % n] * (n - i - 1) + dang 
        dang += list_1[i] * 2
        ans_1 = min(ans_1, num_1)
    dang = 0
    for i in range(n):
        num_1 = list_2[i] * (n - i) + list_2[(i + 1) % n] * (n - i - 1) + dang 
        dang += list_2[i] * 2
        ans_1 = min(ans_1, num_1)
    ans.append(ans_1)
for i in range(len(ans)):
    print(ans[i])












