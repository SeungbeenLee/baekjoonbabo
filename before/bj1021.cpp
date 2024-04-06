#include <iostream>
#include <deque>
using namespace std;

void num1(deque<int>& DQ)
{
	DQ.push_back(DQ.front());
	DQ.pop_front();
}

void num2(deque<int>& DQ)
{
	DQ.push_front(DQ.back());
	DQ.pop_back();
}
int find_num(const deque<int>& DQ, int x, int& cnt)
{
	int idx = 0;
	while (x != DQ[idx])
	{
		idx++;
		if (idx >= DQ.size())
			idx -= DQ.size();
		cnt++;
	}
	if (cnt < DQ.size() - cnt)
		return (1);
	else
	{
		cnt = DQ.size() - cnt;
		return (0);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> DQ;
	int N, M , cnt, ans = 0;
	cin >> N >> M;
	for (int i=1;i<=N;i++)
		DQ.push_back(i);
	for (int i=0;i<M;i++)
	{
		int x;
		cin >> x;
		cnt = 0;
		if (find_num(DQ, x, cnt))
		{
			ans += cnt;
			while (cnt-- > 0)
				num1(DQ);
		}
		else
		{
			ans += cnt;
			while (cnt-- > 0)
				num2(DQ);
		}
		DQ.pop_front();
	}
	cout << ans;
	return (0);
}