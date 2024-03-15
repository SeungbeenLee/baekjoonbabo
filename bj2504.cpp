#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	stack<char> B;
	bool first = true;
	int gop = 1, ans = 0;

	for (size_t i=0;i<s.length();i++)
	{
		if (s[i] == '(')
		{
			gop *= 2;
			B.push(s[i]);
			first = true;
		}
		else if (s[i] == '[')
		{
			gop *= 3;
			B.push(s[i]);
			first = true;
		}
		else if (s[i] == ')')
		{
			if (!B.empty() && B.top() == '(')
			{
				if (first)
					ans += gop;
				gop /= 2;
				B.pop();
				first = false;
			}
			else
			{
				cout << 0;
				return (0);
			}
		}
		else if (s[i] == ']')
		{
			if (!B.empty() && B.top() == '[')
			{
				if (first)
					ans += gop;
				gop /= 3;
				B.pop();
				first = false;
			}
			else
			{
				cout << 0;
				return (0);
			}
		}
	}
	if (B.empty())
		cout << ans;
	else
		cout << 0;
}