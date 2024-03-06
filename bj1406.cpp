#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	list<char> s_list;
	for (int i=0;i<s.size();i++) s_list.push_back(s[i]);
	list<char>::iterator t = s_list.end();
	
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		char input;
		cin >> input;
		if (input == 'L' && t != s_list.begin()) t--;
		else if (input == 'D' && t != s_list.end()) t++;
		else if (input == 'B' && t != s_list.begin()) t = s_list.erase(--t);
		else if (input == 'P')
		{
			char c;
			cin >> c;
			s_list.insert(t, c);	
		}
	}
	for (auto i : s_list) cout << i;
}