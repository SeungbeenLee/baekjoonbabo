#include <iostream>
using namespace std;

int N;
int board[6561][6561];
int dy_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy_y[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void make_star(int x, int y, int num)
{
	if (num == 3)
	{
		for (int i=0;i<8;i++)
		{
			int nx, ny;
			nx = x + dy_x[i];
			ny = y + dy_y[i];
			board[nx][ny] = 1;
		}
	}
	int n = num/3;
	if (n >= 3)
	{
		x = x + n;
		y = y + n;
		for (int i=0;i<8;i++)
		{
			int nx, ny;
			nx = x + n * dy_x[i];
			ny = y + n * dy_y[i];
			make_star(nx, ny, n);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	make_star(1, 1, N);
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			if (board[i][j]) cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}
}