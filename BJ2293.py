n, k = map(int, input().split())
coins = [0] * n
for i in range(n):
	coins[i] = int(input())

dp = [0] * (k+1)
dp[0] = 1

for coin in coins:
	for i in range(coin, k+1):
		dp[i] += dp[i - coin]

print(dp[k])