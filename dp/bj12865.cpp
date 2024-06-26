#include <iostream>
using namespace std;

int	N, K;
int	dp[101][100001];
int W[100001];
int V[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i=1;i<=N;i++)
		cin >> W[i] >> V[i];
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=K;j++)
		{
			if (j >= W[i]) dp[i][j] = max(dp[i-1][j-W[i]] + V[i], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[N][K];
}