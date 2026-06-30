def solve(N, parent):
    tree = [[] for _ in range(N+1)]
    
    for i in range(2, N+1):
        p = parent[i-1]
        tree[p].append(i)

    dp = [0] * (N+1)

    def dfs(u):
        total = 0
        for v in tree[u]:
            dfs(v)
            if dp[v] > 0:
                total += dp[v]
        dp[u] = max(u, total)

    dfs(1)
    return dp[1]

