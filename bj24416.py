cnt = 0
def fib(n):
	if n == 1 or n == 2:
		return 1
	else:
		return fib(n-2) + fib(n-1)

def fibbonaci(n):
	global cnt
	dp = [0] * (n+1)
	dp[0] = 0
	dp[1] = dp[2] = 1
	for i in range(3, n+1):
		dp[i] = dp[i-1] + dp[i-2]
		cnt += 1
	return dp[n]
n = int(input())
print(fibbonaci(n), cnt)