n, m = map(int, input().split())
dui = {}
dict_1 = {}
for _ in range(n):
    s = input()
    dui[s] = 1
ans = []
for _ in range(m):
    s = input()
    if s in dui:
        if s not in dict_1:
            ans.append("OK")
            dict_1[s] = 1
        else:
            ans.append("REPEAT")
    else:
        ans.append("WRONG")
for i in range(len(ans)):
    print(ans[i])