// 위상정렬: O(V + E), 0-based index
// 작성자: forest528

// DAG(사이클 없는 유향 그래프)에서만 사용
// answer[i]: 노드 i에 도달하기까지 거쳐야 하는 단계 수

#include <vector>
#include <queue>

using namespace std;

void topologicalSort(int n, const vector<vector<int>>& graph, vector<int>& answer)
{
	answer.resize(n);

	vector<int> degree(n, 0);
	for (int u = 0; u < n; ++u)
		for (int v : graph[u])
			++degree[v];


	queue<pair<int, int>> q;	// node, step
	for (int i = 0; i < n; ++i)
		if (degree[i] == 0)
			q.push({ i, 1 });

	while (!q.empty())
	{
		int node = q.front().first;
		int step = q.front().second;
		q.pop();

		answer[node] = step;

		for (int next : graph[node])
			if (--degree[next] == 0)
				q.push({ next, step + 1 });
	}
}