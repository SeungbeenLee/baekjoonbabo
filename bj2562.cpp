#include <iostream>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];
    for (int i=0;i<9;i++)
        cin >> arr[i];
    
    int max = arr[0];
    int max_idx = 0;
    for (int i=0;i<9;i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
            max_idx = i;
        }
    }
    cout << max << "\n" << max_idx+1;
    return (0);
}