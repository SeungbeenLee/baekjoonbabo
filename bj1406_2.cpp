#include <iostream>
#include <algorithm>
using namespace std;

const int	MX = 1000005;
char		dat[MX];
int			pre[MX];
int			nxt[MX];
int			unused = 1;

void insert(int addr, char num)
{
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre+MX, -1);
	fill(nxt, nxt+MX, -1);

	int	cursor = 0;
	string	s;
	cin >> s;
	for (int i=0;i<s.size();i++)
		insert(cursor++, s[i]);
	int		num;
	char	c;
	cin >> num;
	for (int i=0;i<num;i++)
	{
		cin >> c;
		if (c == 'P')
		{
			cin >> c;
			insert(cursor, c);
			cursor = nxt[cursor];
		}
		else if (c == 'L' && pre[cursor] != -1) cursor = pre[cursor];
		else if (c == 'D' && nxt[cursor] != -1) cursor = nxt[cursor];
		else if (c == 'B' && pre[cursor] != -1)
		{
			erase(cursor);
			cursor = pre[cursor];
		}
	}
	int idx = nxt[0];
	while (idx != -1)
	{
		cout << dat[idx];
		idx = nxt[idx];
	}
}