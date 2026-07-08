/*
* 알고리즘 DFS
* 1. 현재 상태로 방문한적 있다면 return
* 2. 현재 노드의 첫 방문이라면 방문 처리
* 3. 현재 노드의 첫 방문이라면 sheep, wolves를 업데이트
* 4. wolves >= sheep이라면 return
* 5. 인접한 모든 노드에 대해 DFS
* 6. max(sheep, max(DFS))를 return
*/
#include <vector> 

using namespace std;

int DFS(const vector<int>& info, const vector<vector<int>>& adj, vector<vector<char>>& visited, int bitmask, int node, int sheep, int wolves)
{
    if (visited[bitmask][node])
        return sheep;

    visited[bitmask][node] = true;

    int bit = (1 << node);

    if (!(bitmask & bit))
    {
        bitmask |= bit;
        sheep += (1 - info[node]);
        wolves += info[node];
    }

    if (wolves >= sheep)
        return sheep;

    int ret = sheep;

    for (int v : adj[node])
    {
        int temp = DFS(info, adj, visited, bitmask, v, sheep, wolves);
        ret = temp > ret ? temp : ret;
    }

    return ret;
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    int n = info.size();
    int m = edges.size();

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<char>> visited((1 << n), vector<char>(n, false));
    return DFS(info, adj, visited, 0, 0, 0, 0);
}
