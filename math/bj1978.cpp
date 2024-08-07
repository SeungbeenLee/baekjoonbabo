#include <iostream>
using namespace std;

bool   ifprime(int num)
{
    if (num == 1) return 0;
    for (int i=2;i*i<=num;i++)
        if (num % i == 0) return 0;
    return 1;
} 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp, cnt = 0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> tmp;
        if (ifprime(tmp)) cnt++;
    }
    cout << cnt;
}