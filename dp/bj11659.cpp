#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int arr[100001];
int dp[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	queue<pair<int, int> > Q;
	for (int i=1;i<=N;i++)
		cin >> arr[i];
	for (int i=0;i<M;i++)
	{
		int x, y;
		cin >> x >> y;
		Q.push(make_pair(x,y));
	}
	dp[0] = 0;
	dp[1] = arr[1];
	for (int i=2;i<=N;i++)
		dp[i] = dp[i-1] + arr[i];
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		int x = cur.first;
		int y = cur.second;
		cout << dp[y] - dp[x-1] << '\n';
	}
}