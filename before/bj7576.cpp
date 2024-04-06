#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > Q;
	int N,M, zero = 0, ans = 0;
	cin >> M >> N;
	for (int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0) zero++;
		}
	for (int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if (board[i][j] == 1)
			{
				dist[i][j] = 1;
				Q.push(make_pair(i, j));
			}
	while (!Q.empty())
	{
		pair<int,int> cur = Q.front(); Q.pop();
		for (int i=0;i<4;i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx <0 || nx >= N || ny<0 || ny >= M) continue;
			if (board[nx][ny] == 1 || board[nx][ny] == -1) continue;
			board[nx][ny] = 1;
			zero--;
			if (dist[nx][ny] == 0)
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			else
				dist[nx][ny] = min(dist[nx][ny], dist[cur.X][cur.Y] + 1);
			ans = max(ans, dist[nx][ny]);
			Q.push(make_pair(nx,ny));
		}
	}
	if (zero == 0)
		if (ans == 0) 
			cout << 0;
		else
			cout << (ans-1);
	else cout << -1;
}