#include <iostream>
using namespace std;

int N;
int board[4000][7000];
int dx[8] = {0, 1, 1, 2, 2, 2, 2, 2};
int dy[8] = {0, -1, 1, -2, -1, 0, 1, 2};

void mk_star(int x, int y, int num)
{
	if (num == 3)
	{
		for (int i=0;i<8;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0) continue;
			board[nx][ny] = 1;
		}
	}
	int n = num / 2;
	if (n >= 3)
	{
		mk_star(x, y, n);
		mk_star(x+n, y+n, n);
		mk_star(x+n, y-n, n);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	mk_star(0, N, N);
	for (int i=0;i<N;i++)
	{
		for (int j=1;j<2*N;j++)
		{
			if (board[i][j] == 1) cout << "*";
			else if (board[i][j] == 0) cout << " ";
		}
		cout << "\n";
	}
}