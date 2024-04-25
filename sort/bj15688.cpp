#include <iostream>
using namespace std;

int freq[2000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num_max = 1;
    cin >> N;
    for (int i=0;i<N;i++)
    {
        int num;
        cin >> num;
        num = num + 1000000;
        if (num > num_max) num_max = num;
        freq[num]++;
    }
    for (int i=0;i<=num_max;i++)
    {
        if (freq[i] <= 0) continue;
        while (freq[i] > 0)
        {
            cout << (i - 1000000) << '\n';
            freq[i]--;
        }
    }
}