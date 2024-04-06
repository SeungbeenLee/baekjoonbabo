#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		list<char> pw;
		list<char>::iterator t = pw.begin();
		string s;
		cin >> s;
		for (auto j : s)
		{
			if (j == '<' && t != pw.begin()) t--;
			else if (j == '>' && t != pw.end()) t++;
			else if (j == '-' && t != pw.begin()) t = pw.erase(--t);
			else pw.insert(t, j);
		}
		for (auto p : pw) cout << p;
		cout << "\n";
	}
	return (0);
}