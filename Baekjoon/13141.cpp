// BOJ 13141 Ignition
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_DIST = 20000;

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N, vector<int>(N, MAX_DIST));
    vector<vector<int>> edge(M);

    for (int i = 0; i < N; ++i)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int S, E, L;
        cin >> S >> E >> L;

        edge[i] = { S - 1, E - 1, L };
        dist[S - 1][E - 1] = min(dist[S - 1][E - 1], L);
        dist[E - 1][S - 1] = min(dist[E - 1][S - 1], L);
    }

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    float ans = MAX_DIST;

    for (int i = 0; i < N; ++i)
    {
        float t = 0.0f;

        for (int j = 0; j < M; ++j)
        {
            t = max(t, (float)(dist[i][edge[j][0]] + dist[i][edge[j][1]] + edge[j][2]) / 2.0f);
        }

        ans = min(ans, t);
    }

    cout << fixed << setprecision(1) << ans;

    return 0;
}
