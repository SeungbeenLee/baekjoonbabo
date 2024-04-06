#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> DQ;
	int num;
	cin >> num;
	for (int i=0;i<num;i++)
	{
		string s;
		cin >> s;
		if (s == "push_front")
		{
			int n;
			cin >> n;
			DQ.push_front(n);
		}
		else if (s == "push_back")
		{
			int n;
			cin >> n;
			DQ.push_back(n);
		}
		else if (s == "pop_front")
		{
			if (DQ.empty())
				cout << -1 << "\n";
			else
			{
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (DQ.empty())
				cout << -1 << "\n";
			else
			{
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		}
		else if (s == "size")
			cout << DQ.size() << "\n";
		else if (s == "empty")
			cout << DQ.empty() << "\n";
		else if (s == "front")
		{
			if (DQ.empty())
				cout << -1 << "\n";
			else
			{
				cout << DQ.front() << "\n";
			}
		}
		else if (s == "back")
		{
			if (DQ.empty())
				cout << -1 << "\n";
			else
			{
				cout << DQ.back() << "\n";
			}
		}
	}
}