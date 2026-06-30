def is_prime(x):
    if x < 2:
        return False
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

def mex_p_subarray(arr):
    p = 2
    while True:
        if is_prime(p):
            ok = False
            for x in arr:
                if x % p != 0:   # key condition
                    ok = True
                    break
            if ok:
                return p
        p += 1


def solve():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))

        ans = 0
        for L in range(N):
            for R in range(L, N):
                sub = A[L:R+1]
                ans += mex_p_subarray(sub)

        print(ans)

