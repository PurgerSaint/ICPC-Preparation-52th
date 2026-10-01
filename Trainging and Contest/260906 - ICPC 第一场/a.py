
for _ in range(int(input())):
    n = int(input())
    zhan = []
    dict_1 = {}
    ans = []
    for i in range(n):
        list_1 = list(map(str, input().split()))
        if list_1[0] == "+":
            zhan.append(list_1[1])
            if list_1[1] not in dict_1:
                dict_1[list_1[1]] = 1
            else:
                dict_1[list_1[1]] += 1
            ans.append("+")
        elif list_1[0] == "T":
            ans.append("?")
        else:
            num_1 = 0
            if list_1[1] in dict_1:
                num_1 = dict_1[list_1[1]]
            while num_1:
                num_2 = zhan.pop()
                dict_1[num_2] -= 1
                if num_2 == list_1[1]:
                    num_1 -= 1
                ans.append("-")
            ans.append("?")
    print("".join(ans))
    




