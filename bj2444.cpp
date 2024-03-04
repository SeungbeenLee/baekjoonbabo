#include <iostream>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i=0;i<num-1;i++)
    {
        for (int j=0;j<num-i-1;j++)
            cout << " ";
        for (int j=0;j<2*i+1;j++)
            cout << "*";
        cout << "\n";
    }
    for (int i=0;i<2*num-1;i++)
        cout << "*";
    cout << "\n";
    for (int i=0;i<num-1;i++)
    {
        for (int j=0;j<i+1;j++)
            cout << " ";
        for (int j=0;j<2*num-1-2*(i+1);j++)
            cout << "*";
        cout << "\n";
    }
    return (0);
}