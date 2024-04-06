# 생성되는 배열의 수가 너무 커져서 이 수를 조정해줄 필요가 있음 : bitmasking
N, M = map(int, input().split())
bags = []
for i in range(N):
	weight, value, count = map(int, input().split())
	binary = 1
	while (count > 0):
		m = min(count, binary)
		bags.append((weight * m, value * m))
		count -= binary
		binary *= 2

dp = [0] * (M+1)
for weight, value in bags:
	for i in range(M, weight -1, -1):
		dp[i] = max(dp[i], dp[i-weight] + value)
print(dp[M])