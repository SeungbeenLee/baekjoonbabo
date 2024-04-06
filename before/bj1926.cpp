#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first // X는 행
#define Y second // Y는 열
int board[502][502];
bool vis[502][502]; // 방문 여부
int n, m, art_num, mx_size; // 행, 열의 수, 그림수, 최대 개수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
pair<int, int> first = make_pair(0,0);

int find_first(queue<pair<int,int> >& Q, const int board[502][502], int n, int m)
{
	for (int i=first.X;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (board[i][j] == 0 || vis[i][j]) continue;
			Q.push(make_pair(i,j));
			vis[i][j] = 1;
			first.X = i;
			return (1);
		}
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > Q;
	cin >> n >> m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin >> board[i][j];
	while (find_first(Q, board, n, m))
	{
		art_num++;
		int art_size = 0;
		while (!Q.empty())
		{
			pair<int, int> cur = Q.front(); Q.pop();
			art_size++;
			for (int dir=0;dir<4;dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
				if (vis[nx][ny] || board[nx][ny] != 1) continue;
				vis[nx][ny] = 1;
				Q.push(make_pair(nx, ny));
			}
			if (mx_size < art_size) mx_size = art_size;
		}
	}
	cout << art_num << "\n" << mx_size;
}