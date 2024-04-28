#include <iostream>
using namespace std;

int dp[12];
int ans[12];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i=4;i<=11;i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    for (int i=0;i<T;i++)
        cin >> ans[i];
    for (int i=0;i<T;i++)
        cout << dp[ans[i]] << '\n';
}