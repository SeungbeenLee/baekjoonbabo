#include <iostream>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i=0;i<num;i++)
    {
        for (int j=0;j<i;j++)
            cout << " ";
        for (int k=0;k<2*num-2*i-1;k++)
            cout << "*";
        cout << "\n";
    }
    return (0);
}