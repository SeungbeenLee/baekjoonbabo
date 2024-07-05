#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ifprime(int st, int en)
{
    vector<int> primes;
    vector<bool> state(en+1, true);

    state[1] = false;
    for (int i=st;i<=en;i++)
    {
        if (!state[i]) continue;
        for (int j=i*i;j<=en;j+=i)
            state[i] = false;
    }
    for (int i=st;i<=en;i++)
        if (state[i]) primes.push_back(i);
    return primes;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<int> primes = ifprime(N, M);
    for (int i=0;i<primes.size();i++)
        cout << primes[i] << '\n';
}