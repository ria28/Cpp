def count_func(num1, num2):
    dif = len(str(num1)) - len(str(num2))
    cnt = 0
    
    if num2 > num1:
        return num2,cnt

    # zz = num2*10
    if int(str(num2) + "0"*dif) > num1:
        return int(str(num2) + "0"*dif), cnt+ dif
    cnt += dif
    # print(zz)

    z = (str(num2) + "0"*dif)
    zz = int(z)
    
    extchk = num1 - zz
    ele = 10**dif
    if (extchk < (ele - 1)):
        zz += extchk + 1
    else:
        zz = zz*10
        cnt += 1

    return zz, cnt

T = int(input())

for test_case in range(1, T+1):
    n = int(input())
    nums = list(map(int, input().split()))
    
    count = 0
    for i in range(1, n):
        # print("Case #",i,":")
        nums[i], cnt_  = count_func(nums[i-1], nums[i])
        count += cnt_

    print("Case #{}: {}".format(test_case, count))