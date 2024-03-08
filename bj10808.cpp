#include <iostream>
#include <algorithm>
using namespace std;

int freq[26];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	for (char c : input)
		freq[c - 'a'] += 1;
	for (int i=0;i<26;i++)
		cout << freq[i] << " ";
	return (0);
}