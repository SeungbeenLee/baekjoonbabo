T = int(input())
K = [0] * T
N = [0] * T
for i in range(T):
	K[i] = int(input())
	N[i] = int(input())

for i in range(T):
	dp = [[0] * (N[i] + 1) for _ in range(K[i] + 1)]
	for j in range(K[i] + 1):
		dp[j][0] = 0
		dp[j][1] = 1
	for k in range(N[i] + 1):
		dp[0][k] = k
	for m in range(1, K[i] + 1):
		for n in range(2, N[i] + 1):
			dp[m][n] = dp[m-1][n] + dp[m][n-1]
	print(dp[K[i]][N[i]])