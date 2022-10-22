#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000006];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    sort (a, a + n);
    for (int i = 0; i < n; ++i)
        printf("%lld ", a[i]);
}
