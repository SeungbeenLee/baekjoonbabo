#include <iostream>
using namespace std;

int dp[301];
int step[301];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 0;
    int N;
    cin >> N;
    for (int i=1;i<=N;i++)
        cin >> step[i];
    for (int i=1;i<=N;i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]) + step[i];
        cout << dp[i] << '\n';
    }
    cout << "ans : " << dp[N];
}