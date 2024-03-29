#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char board[1002][1002];
int fire[1002][1002];
int jihoon[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int,int> > Qj;
	queue<pair<int,int> > Qf;
	int R, C;
	cin >> R >> C;

	for (int i=0;i<R;i++)
	{
		string s;
		cin >> s;
		for (int j=0;j<C;j++)
			board[i][j] = s[j];
	}

	for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            if (board[i][j] == 'J') Qj.push(make_pair(i,j));
            if (board[i][j] == 'F') Qf.push(make_pair(i,j));
        }
    }

    while (!Qf.empty())
    {
        pair<int,int> cur = Qf.front(); Qf.pop();
        for (int i=0;i<4;i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
            if (board[nx][ny] != '.' || fire[nx][ny] > 0) continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Qf.push(make_pair(nx,ny));
        }
    }
    while (!Qj.empty())
    {
        pair<int,int> cur = Qj.front(); Qj.pop();
        for (int i=0;i<4;i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx<0 || nx>=R || ny<0 || ny>=C)
            {
                cout << (jihoon[cur.X][cur.Y] + 1);
                return (0);
            }
            if (board[nx][ny] != '.' || jihoon[nx][ny] > 0) continue;
            if (fire[nx][ny] > jihoon[cur.X][cur.Y] + 1 || fire[nx][ny] == 0)
            {
                jihoon[nx][ny] = jihoon[cur.X][cur.Y] + 1;
                Qj.push(make_pair(nx,ny));
            }
        }
    }
    cout << "IMPOSSIBLE";
}