#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];
int N;
int M, ck;

int binarysearch(int target)
{
    int st, en, mid;
    st = 0;
    en = N - 1;
    while (st <= en)
    {
        mid = (st+en)/2;
        if (A[mid] > target)
            en = mid - 1;
        else if (A[mid] < target)
            st = mid + 1;
        else
            return (1);
    }
    return (0);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++)
        cin >> A[i];
    sort(A, A+N);
    cin >> M;
    while (M > 0)
    {
        cin >> ck;
        cout << binarysearch(ck) << '\n';
        M--;
    }
}