// BOJ 19953 영재의 산책
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v0, m, t;
    cin >> v0 >> m >> t;

    long long x = 0, y = 0, v = v0, d = 0;
    vector<int> dx = { 0, 1, 0, -1 };
    vector<int> dy = { 1, 0, -1, 0 };
    vector<vector<long long>> cycle;

    for (int i = 0; i < t; ++i)
    {
        vector<long long> curr = { x, y, v, d };

        for (int j = 0; j < i; ++j)
        {
            if (cycle[j][2] == curr[2] && cycle[j][3] == curr[3])
            {
                int cycleD = i - j;
                int cycleQ = (t - j) / cycleD;
                int cycleR = (t - j) % cycleD;

                long long cycleX = curr[0] - cycle[j][0];
                long long cycleY = curr[1] - cycle[j][1];

                long long ansX = cycle[j + cycleR][0] + cycleQ * cycleX;
                long long ansY = cycle[j + cycleR][1] + cycleQ * cycleY;

                cout << ansX << ' ' << ansY;

                return 0;
            }
        }

        cycle.push_back(curr);

        x += v * dx[d];
        y += v * dy[d];
        v = (v * m) % 10;
        d = (d + 1) % 4;
    }

    cout << x << ' ' << y;

    return 0;
}
