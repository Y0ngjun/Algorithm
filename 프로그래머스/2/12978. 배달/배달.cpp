#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int M = road.size();

    vector<vector<int>> adj(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++)
    {
        int u = road[i][0];
        int v = road[i][1];
        int c = road[i][2];

        if (adj[u][v] == -1 || adj[u][v] > c)
        {
            adj[u][v] = c;
            adj[v][u] = c;
        }
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(N + 1, -1);

    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] != -1)
            continue;

        dist[u] = -d;

        for (int v = 2; v <= N; v++)
        {
            if (dist[v] != -1 || adj[u][v] == -1)
                continue;

            int c = dist[u] + adj[u][v];
            pq.push({ -c, v });
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
        if (dist[i] <= K)
            answer++;

    return answer;
}
