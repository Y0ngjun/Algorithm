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

int DFS(const vector<int>& info, const vector<int>& adj, vector<int>& visited, int bitmask)
{
    int n = info.size();
    int sheep = 0, wolves = 0;

    for (int i = 0; i < n; i++)
        if (bitmask & (1 << i))
            info[i] ? wolves++ : sheep++;

    if (wolves >= sheep || visited[bitmask])
        return sheep;
    visited[bitmask] = true;

    int best = sheep;

    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & bitmask || !(adj[i] & bitmask))
            continue;

        int temp = DFS(info, adj, visited, bitmask | (1 << i));
        best = temp > best ? temp : best;
    }

    return best;
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    int n = info.size();
    int m = edges.size();

    vector<int> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u] |= (1 << v);
        adj[v] |= (1 << u);
    }

    vector<int> visited(1 << n);
    return DFS(info, adj, visited, 1);
}
