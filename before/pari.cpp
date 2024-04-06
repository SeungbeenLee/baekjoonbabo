#include <iostream>
#include <utility>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	pair<int, int> t1 = make_pair(10, 11);
	// pair<int, int> t2 = {12, 13}; // C+11 이상
	pair<int, int> t2 = make_pair(12, 13);

	cout << t1.first << "\n";
	cout << t2.second << "\n";
}