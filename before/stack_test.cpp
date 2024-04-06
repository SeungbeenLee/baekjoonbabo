#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
	dat[pos++] = x;
}

void pop()
{
	if (pos > 0) dat[--pos] = 0;
	else dat[pos] = 0;
}

int top()
{
	int tmp;
	if (pos > 0) tmp = pos - 1;
	else tmp = 0;
	return (dat[tmp]);
}

void test()
{
  push(5); push(4); push(3);
  cout << top() << '\n'; // 3
  pop(); pop();
  cout << top() << '\n'; // 5
  push(10); push(12);
  cout << top() << '\n'; // 12
  pop();
  cout << top() << '\n'; // 10
}

int main(void)
{
	test();
}