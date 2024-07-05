#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[500001];

int lower_idx(int target, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st+en)/2;
        if (A[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int upper_idx(int target, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st+en)/2;
        if (A[mid] > target) en = mid;
        else st = mid+1;
    }
    return st;
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
        int tmp;
        cin >> tmp;
        cout << upper_idx(tmp, N) - lower_idx(tmp, N) << ' ';
        M--;
    }
}