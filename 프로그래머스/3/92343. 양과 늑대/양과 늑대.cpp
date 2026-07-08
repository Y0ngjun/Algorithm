/*
* 알고리즘 DFS
* 1. 현재 비트마스크로 sheep, wolves 계산
* 2. 현재 비트마스크에 방문한적 있거나 wolves >= sheep일 경우
*   2-1. return sheep
* 3. 방문 기록
* 4. 현재 비트마스크에서 도달 가능한 모드 노드에 대해 DFS 수행
*   4-1. best에 최대값 저장
* 5. return best
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
