#include <iostream>
using namespace std;

int N;
int board[130][130];
int cnt[2];

bool check(int x, int y, int num)
{
	for (int i=x;i<x+num;i++)
	for (int j=y;j<y+num;j++)
		if (board[x][y] != board[i][j]) return false;
	return true;
}

void func(int x, int y, int num)
{
	if (check(x,y,num))
	{
		cnt[board[x][y]] += 1;
		return ;
	}
	int n = num / 2;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
		func(x+n*i, y+n*j, n);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin.ignore();
	int j, idx;
	string s;
	for (int i=0;i<N;i++)
	{
		idx = 0, j = 0;
		getline(cin, s);
		while (s[idx])
		{
			if (s[idx] == ' ') idx++;
			else
			{
				board[i][j] = s[idx] - '0';
				idx++;
				j++;
			}
		}
	}
	func(0,0,N);
	for (int k=0;k<2;k++)
		cout << cnt[k] << '\n';
}