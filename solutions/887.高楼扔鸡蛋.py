# 
# 继续动规
# 

def superEggDrop(k: int, n:int):

    memo = dict()
    def dp(k,n) -> int:
        # base case
        if k ==1 : return n
        if n ==0 : return 0

        if (k, n) in memo:
            return memo[(k,n)]

        res = float('INF')

        for i in range(1, n+1):
            res = 1 + min(res, max(dp(k, n-i), dp(k-1, i-1)))
            memo[(k,n)] = res
            return res
        return dp(k, n) 
