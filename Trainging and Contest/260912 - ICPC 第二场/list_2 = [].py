list_2 = []
for _ in range(int(input())):
    n, p = map(int, input().split())
    list_1 = []
    for i in range(n):
        s = input()
        list_1.append(s)
    s_1 = "UnreasonableProblemArrangement"
    ans = 0
    for i in range(n):
        if list_1[i] == s_1:
            ans += 10
    dict_1 = {"WrongProblem": 100, "SameProblem": 30, "UnreasonableLimitForProblem": 5, "WeakTestsForProblem": 3, "BadProblem": 1}
    for i in range(n):
        s_2 = list_1[i][:-1]
        if s_2 in dict_1 and list_1[i][-1] in "ABCDEFGHIJKL":
            ans += dict_1[s_2]
    if ans > p:
        list_2.append("Joker")
    else:
        list_2.append("Judger")
for i in range(len(list_2)):
    print(list_2[i])