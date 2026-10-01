
ans_1 = []
for _ in range(int(input())):
    list_1 = list(map(str, input().split()))
    list_1[0] = int(list_1[0])
    list_1[1] = int(list_1[1])
    ans = 0
    if list_1[1] >= 50 or list_1[1] >= list_1[0] * 0.2:
        ans = 1
    if int(list_1[2][1]) >= 4:
        ans = 1
    ans_1.append("YES" if ans == 1 else "NO")
for i in range(len(ans_1)):
    print(ans_1[i])





