#include <iostream>
using namespace std;

int N;
int dp[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[1] = 1, dp[2] = 2;
	for (int i=3;i<=N;i++)
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	cout << dp[N] ;
}