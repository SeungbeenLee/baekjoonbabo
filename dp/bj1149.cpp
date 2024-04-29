#include <iostream>
#include <algorithm>
using namespace std;

int N;
int	dp[1001][4]; // R-G-B
int R[1001];
int G[1001];
int B[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=1;i<=N;i++)
		cin >> R[i] >> G[i] >> B[i];
	dp[1][1] = R[1], dp[1][2] = G[1], dp[1][3] = B[1];
	for (int i=2;i<=N;i++)
	{
		dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + R[i];
		dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + G[i];
		dp[i][3] = min(dp[i-1][2], dp[i-1][1]) + B[i];
	}
	cout << min(min(dp[N][1], dp[N][2]), dp[N][3]);
}