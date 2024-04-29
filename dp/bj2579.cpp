#include <iostream>
using namespace std;

int dp[301][3];
int step[301];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=1;i<=N;i++)
        cin >> step[i];
	dp[1][1] = step[1], dp[1][2] = 0;
	dp[2][1] = step[2], dp[2][2] = step[1] + step[2];
	for (int i=3;i<=N;i++)
	{
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + step[i];
		dp[i][2] = dp[i-1][1] + step[i];
	}
    cout << max(dp[N][1], dp[N][2]);
}