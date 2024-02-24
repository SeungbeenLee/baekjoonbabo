T = int(input())
K = [0] * T
N = [0] * T
for i in range(T):
	K[i] = int(input())
	N[i] = int(input())

for idx in range(T):
	dp = [[0] * (K[i]) for _ in range(N[i] + 1)]
	dp[0][0] = 0
	for i in range(N[i]):
		dp[0][i] = i
	for i in range(N())