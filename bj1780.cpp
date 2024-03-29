#include <iostream>
using namespace std;
int cnt[3];
int board[2188][2188];
int N;

bool check(int x, int y, int num)
{
	for (int i=x;i<x+num;i++)
	for (int j=y;j<y+num;j++)
		if (board[x][y] != board[i][j]) return false;
	return true;
}
void func(int x, int y, int num)
{
	if (check(x, y, num))
	{
		cnt[board[x][y] + 1] += 1;
		return ;
	}
	int n = num / 3;
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++)
		func(x+n*i,y+n*j,n);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		cin >> board[i][j];
	func(0,0,N);
	for (int k=0;k<3;k++)
		cout << cnt[k] << '\n';
}