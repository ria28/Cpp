def chPr(arr, me):
    tar = tuple(sorted(arr))
    if mem.get(tar, -1) == -1:
        print(" ".join(arr))
        mem[tar] = input()
    return mem.get(tar)


def insRet(re, arr):
    arr.insert(len(arr) // 2, re[1])
    arr.insert(len(arr) // 2, re[0])
    return arr


t, n, q = list(map(int, input().split()))
for i in range(t):
    mem = dict()
    res = []
    prop = [str(k + 1) for k in range(n)]
    for j in range(n // 2):
        temp = set()
        q = 0
        while len(temp) != len(prop) - 2 and q < len(prop) -2:
            temp.add(chPr(prop[q:q + 3], mem))
            if prop[0] not in temp:
                prop.append(prop.pop(0))
            else:
                q += 1
        res = insRet(list(temp ^ set(prop)), res)
        prop = [str(s) for s in temp]
    s, en = 0, (len(res) // 2) - 1 if len(res) % 2 == 0 else len(res) // 2
    for l in range(s+1, en):
        if res[l] != chPr([res[s], res[l], res[en]], mem):
            res[l], res[len(res) - l - 1] = res[len(res) - l - 1], res[l]
    print(" ".join(res))
    if int(input()) == -1:
        break