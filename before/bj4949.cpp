#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	while (getline(cin, str))
	{
		if (str == ".") return (0);
		bool done = false;
		stack<char> S;
		for (size_t i=0;i<str.length();i++)
		{
			if (str[i] == '(' || str[i] == '[') S.push(str[i]);
			else if (str[i] == ')')
			{
				if (!S.empty() && S.top() == '(') S.pop();
				else
				{
					cout << "no\n";
					done = true;
					break;
				}
			}
			else if (str[i] == ']')
		 	{
				if (!S.empty() && S.top() == '[') S.pop();
				else
				{
					cout << "no\n";
					done = true;
					break;
				}
			}
		}
		if (done)
			continue;
		else
		{
			if (S.empty()) cout << "yes\n";
			else cout << "no\n";
		}
	}
}