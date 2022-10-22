#include <bits/stdc++.h>
using namespace std;
float a[600000], b1, b2;
int n, m;
FILE *o1, *o2, *i1, *i2;
int solve()
{
    o1 = fopen("1.tmp", "w");
    o2 = fopen("2.tmp", "w");
    scanf("%d", &n);
    m = n / 2;
    n -= m;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%f", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        fprintf(o1, "%.2f ", a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%f", &a[i]);
    }
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        fprintf(o2, "%.2f ", a[i]);
    }
    fclose(o1);
    fclose(o2);
    i1 = fopen("1.tmp", "r");
    i2 = fopen("2.tmp", "r");
    int i = 1, j = 1;
    fscanf(i1, "%f", &b1);
    fscanf(i2, "%f", &b2);

    while(i <= n && j <= m){
        if (b1 < b2)
        {
            ++i;
            printf("%.2f ", b1);
            if (i <= n) fscanf(i1, "%f", &b1);
        }
        else
        {
            j++;
            printf("%.2f ", b2);
            if (j <= m) fscanf(i2, "%f", &b2);
        }
    }
    while(i++ <= n)
    {
        printf("%.2f ", b1);
        fscanf(i1, "%f", &b1);
    }
    while(j++ <= m)
    {
        printf("%.2f ", b2);
        fscanf(i2, "%f", &b2);
    }
    return 0;
}
int main()
{
    solve();
    return 0;
}
