// BOJ 1891 사분면
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// (0, 1) * 2^0 +
// (1, 1) * 2^1 +
// (1, 0) * 2^2 =
// (6, 3)

pair<long long, long long> stopll(string s)
{
    static vector<pair<int, int>> v =
    {
        {0, 1},
        {0, 0},
        {1, 0},
        {1, 1}
    };

    pair<long long, long long> ret = { 0LL, 0LL };
    int i = s.size() - 1;
    long long j = 1;

    while (i >= 0)
    {
        ret.first += v[s[i] - '1'].first * j;
        ret.second += v[s[i] - '1'].second * j;

        i -= 1;
        j *= 2;
    }

    return ret;
}

long long pow(int n, int m)
{
    long long ret = 1;

    for (int i = 0; i < m; ++i)
    {
        ret *= n;
    }

    return ret;
}

string plltos(pair<long long, long long> pll, int d)
{
    static map<pair<int, int>, char> m =
    {
        {{0, 1}, '1'},
        {{0, 0}, '2'},
        {{1, 0}, '3'},
        {{1, 1}, '4'}
    };

    string s = "";
    long long j = pow(2, d - 1);

    while (j > 0)
    {
        pair<int, int> pii = { 0, 0 };

        if (pll.first >= j)
        {
            pii.first += 1;
            pll.first -= j;
        }

        if (pll.second >= j)
        {
            pii.second += 1;
            pll.second -= j;
        }

        s += m[pii];
        j /= 2;
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    string s;
    cin >> d >> s;

    long long x, y;
    cin >> x >> y;

    pair<long long, long long> pll = stopll(s);
    pll.first -= y;
    pll.second += x;

    if (pll.first < 0 || pll.first >= pow(2, d) || pll.second < 0 || pll.second >= pow(2, d))
    {
        cout << -1;
    }
    else
    {
        cout << plltos(pll, d);
    }

    return 0;
}
