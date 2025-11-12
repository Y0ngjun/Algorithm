// BOJ 34540 Lunar Exploration
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;

        v[i] = { x, y };
    }

    int X, Y;
    char D;
    cin >> X >> Y >> D;

    long long ans = 0;
    if (D == 'E')
    {
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {return a.first < b.first; });

        for (int i = 0; i < N; ++i, ++X)
        {
            int dist = abs(X - v[i].first) + abs(Y - v[i].second);
            ans += dist;
        }

    }
    else
    {
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {return a.second < b.second; });

        for (int i = 0; i < N; ++i, ++Y)
        {
            int dist = abs(X - v[i].first) + abs(Y - v[i].second);
            ans += dist;
        }
    }

    cout << ans;

    return 0;
}
