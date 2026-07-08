#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int DFS(const vector<vector<char>>& adj, int parent, int node)
{
    int n = adj.size() - 1;
    int ret = 1;

    for (int i = 1; i <= n; i++)
        if (adj[node][i] && i != parent)
            ret += DFS(adj, node, i);

    return ret;
}

int solution(int n, vector<vector<int>> wires)
{
    vector<vector<char>> adj(n + 1, vector<char>(n + 1, false));
    for (int i = 0; i < n - 1; i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = true;
        adj[v][u] = true;
    }

    int answer = n;

    for (int i = 0; i < n - 1; i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];

        adj[u][v] = false;
        adj[v][u] = false;

        int num = DFS(adj, -1, 1);
        int temp = abs(n - num - num);

        answer = min(answer, temp);
        adj[u][v] = true;
        adj[v][u] = true;
    }

    return answer;
}
