#include <vector>
#include <climits>

using namespace std;

/*
1. 모든 노드를 순회하며 벨만-포드 계산
2. 가장 비용이 적은 합승 방법을 계산
*/

bool BellmanFord(int s, const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& distance)
{
    int n = adj.size() - 1;
    distance[s][s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (distance[s][u] == INT_MAX)
                continue;

            for (auto& [v, c] : adj[u])
                if (distance[s][u] + c < distance[s][v])
                    distance[s][v] = distance[s][u] + c;
        }
    }

    for (int u = 1; u <= n; u++)
    {
        if (distance[s][u] == INT_MAX)
            continue;

        for (auto& [v, c] : adj[u])
            if (distance[s][u] + c < distance[s][v])
                return false; // negative cycle
    }

    return true;
}

void FloydWarshall(const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& distance)
{
    int n = adj.size() - 1;

    for (int u = 1; u <= n; u++)
    {
        distance[u][u] = 0;
        for (const auto& [v, c] : adj[u])
        {
            distance[u][v] = c;
            distance[v][u] = c;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (distance[u][k] == INT_MAX)
                continue;

            for (int v = 1; v <= n; v++)
            {
                if (distance[k][v] == INT_MAX)
                    continue;

                if (distance[u][v] > distance[u][k] + distance[k][v])
                    distance[u][v] = distance[u][k] + distance[k][v];
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto& edge : fares)
    {
        int u = edge[0];
        int v = edge[1];
        int c = edge[2];

        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }

    vector<vector<int>> distance(n + 1, vector<int>(n + 1, INT_MAX));
    FloydWarshall(adj, distance);

    int answer = INT_MAX;
    for (int IC = 1; IC <= n; IC++)
    {
        int cost = distance[s][IC] + distance[IC][a] + distance[IC][b];
        answer = min(answer, cost);
    }

    return answer;
}
