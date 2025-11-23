// BOJ 1948 임계경로
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> edge(N + 1, vector<pair<int, int>>());
    vector<vector<pair<int, int>>> reverse(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;

        edge[u].push_back({ v, d });
        reverse[v].push_back({ u, d });
    }

    int S, E;
    cin >> S >> E;

    queue<pair<int, int>> bfs;
    vector<int> visited(N + 1, 0);

    bfs.push({ S, 0 });
    visited[S] = 0;

    while (!bfs.empty())
    {
        auto [u, dist] = bfs.front();
        bfs.pop();

        for (auto [v, d] : edge[u])
        {
            if (dist + d <= visited[v])
            {
                continue;
            }

            bfs.push({ v, dist + d });
            visited[v] = dist + d;
        }
    }

    // 역추적
    int K = 0;
    vector<int> revisited(N + 1, 0);
    bfs.push({ E, 0 });

    while (!bfs.empty())
    {
        auto [v, dist] = bfs.front();
        bfs.pop();

        if (revisited[v] == 1)
        {
            continue;
        }

        revisited[v] = 1;

        for (auto [u, d] : reverse[v])
        {
            if (dist + d + visited[u] < visited[E])
            {
                continue;
            }

            bfs.push({ u, dist + d });
            K++;
        }
    }

    cout << visited[E] << '\n' << K << '\n';

    return 0;
}
