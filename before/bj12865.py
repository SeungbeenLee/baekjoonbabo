N, K = map(int, input().split())
weights = []
values = []
for i in range(N):
	weight, value = map(int, input().split())
	weights.append(weight)
	values.append(value)

dp = [[0]*(K+1) for _ in range(N)]

for i in range(N):
	for j in range(1, K+1):
		if weights[i] <= j:
			if i == 0:
				dp[i][j] = values[0]
			else:
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i])
		else:
			dp[i][j] = dp[i-1][j]

print(dp[N-1][K])