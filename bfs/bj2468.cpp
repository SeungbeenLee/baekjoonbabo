#include <iostream>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

#define X first
#define Y second
int	board[102][102];
int	pos[102][102];
int	vis[102][102];
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;
int N, Max, cnt, ans = 0;
int	Min = INT_MAX;

void	cnt_ans(void)
{
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir=0;dir<4;dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>= N) continue;
			if (vis[nx][ny] || !pos[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
		}
	}
	cnt++;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			cin >> board[i][j];
			if (Max < board[i][j]) Max = board[i][j];
			if (Min > board[i][j]) Min = board[i][j];
		}
	}
	Min--;
	while (Min < Max)
	{
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				if (board[i][j] > Min)
					pos[i][j] = 1;
		cnt = 0;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				if (pos[i][j] && !vis[i][j])
				{
					Q.push(make_pair(i, j));
					cnt_ans();
				}
		if (ans < cnt) ans = cnt;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
			{
				pos[i][j] = 0;
				vis[i][j] = 0;
			}
		Min++;
	}
	cout << ans;
}