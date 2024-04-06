# MLE : Memory Limit Exceeded
N, M = map(int, input().split())
weights = []
values = []
counts = []
for i in range(N):
	weight, value, count = map(int, input().split())
	counts.append(count)
	for j in range(count):
		weights.append(weight)
		values.append(value)

total = sum(counts)
dp = [[0]*(M+1) for _ in range(total)]
for i in range(total):
	for j in range(1, M+1):
		if weights[i] <= j:
			if i == 0:
				dp[i][j] = values[i]
			else:
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i])
		else:
			dp[i][j] = dp[i-1][j]

print(dp[total-1][M])