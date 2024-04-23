#include <iostream>
using namespace std;

int N;
int board[59049][59049];
int dy[8] = {0, 1, 1, 2, 2, 2, 2, 2};
int dx[8] = {0, -1, 1, -2 , -1, 0, 1, 2};

void mk_star(int x, int y, int num)
{
	if (num == 3)
	{
		for (int j=0;j<3;j++)
		{
			for (int i=0;i<8;i++)
			{
				int nx, ny;
				nx = x + dx[i];
				ny = y + dy[i];
				board[nx][ny] = 1;
			}
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
}