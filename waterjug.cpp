#include <bits/stdc++.h>
using namespace std;
#define int long long
int pour(int fromCap, int toCap, int d)
{
    int from = fromCap;
    int to = 0;
    int step = 1;
    while (from != d && to != d)
    {
        int temp = min(from, toCap - to);
        to += temp;
        from -= temp;
        step++;
        if (from == d || to == d) break;
        if (from == 0)
        {
            from = fromCap;
            step++;
        }
        if (to == toCap)
        {
            to = 0;
            step++;
        }
    }
    return step;
}
int minSteps(int m, int n, int d)
{
    if (m > n) swap(m, n);
    if (d > n) return -1;
    if (d % __gcd(n, m)) return -1;
    return min(pour(n, m, d), pour(m, n, d));
}

int m, n, d, T;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int Try(int x, int y, int k, int p, int q)
{
    int xx = x + k * p, yy = y - k * q;
    if (xx < 0 && d > n) return (abs(xx) + abs(yy)) * 2;
    if (xx == 0 || yy == 0) return (abs(xx) + abs(yy)) * 2;
    return (abs(xx) + abs(yy)) * 2 - 2;
}
#undef int
int main()
{
#define int long long
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> m >> n >> d;
        if (d > max(m, n))
        {
            cout << "-1\n";
            continue;
        }
        int tmp = __gcd(m, n);
        if (d % tmp)
        {
            cout << "-1\n";
            continue;
        }
        if (m == d || n == d)
        {
            cout << "1\n";
            continue;
        }
        int x, y, g;
        if (m < n) swap(m, n);
        find_any_solution(m, n, d, x, y, g);
        //cout << x << ' ' << y << ' ' << g << '\n';
        int p = n / g, q = m / g;
        int tmp2 = (p + q);
        int k = (y - x) / tmp2;
        cout << min(Try(x, y, k, p, q), min(Try(x, y, k + 1, p, q), Try(x, y, k - 1, p, q))) << '\n';
        //cout << minSteps(m, n, d) << '\n';
    }
}
