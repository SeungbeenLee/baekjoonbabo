#include <list>
#include <iostream>
using namespace std;

int main(void)
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	list<int>::iterator t = L.begin(); // t 는 1을 가리킴

	L.push_front(10); // 10 1 2
	cout << *t << '\n'; // 1
	
	L.push_back(5); // 10 1 2 5
	L.insert(t, 6); // 10 6 1 2 5 : t 앞에 삽입

	t++; // t 는 2를 가리킴
	cout << *t << '\n'; // 2

	t = L.erase(t); // t = 5 : t가 가리키는 값을 제거 한 후 한 칸 뒤를 반환
	cout << *t << '\n'; // 5

	// 같은 결과를 내는 for 문
	// 야매와 달리 STL list는 L.end()가 제일 뒤에 있는 원소 한 칸 뒤를 의미
	for (auto i : L) cout << i << " "; // 10 6 1 5
	cout << "\n";
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
		cout << *it << ' ';
}