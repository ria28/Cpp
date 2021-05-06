def solve(N, tar):
    if (((N)*(N + 1))//2) - 1 < tar or tar < N - 1:
        return "IMPOSSIBLE"
    pyr = [1 for _ in range(N - 1)]
    tar -= N - 1
    i = 0
    while tar != 0 and i < len(pyr):
        ml = N - 1 - i
        if ml <= tar:
            pyr[i] += ml
            tar -= ml
        else:
            pyr[i] += tar
            tar -= tar
        i += 1
    sol = [str(i + 1) for i in range(N)]
    print(pyr)
    for i in range(N - 2, -1,-1):
        en = i + pyr[i] - 1
        print(i)
        print(en)
        sol = sol[:i] + sol[i:en+1][::-1] + sol[en +1:]
        print(sol)
    return " ".join(sol)

    print(pyr)
    


tc = int(input())
for i in range(tc):
    n, target = list(map(int, input().split()))
    print("Case #" + str(i + 1) + ":", solve(n, target))


""" 
5
4 6
2 1
7 12
7 2
2 1000 

"""
