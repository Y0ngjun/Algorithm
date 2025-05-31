// ��������: O(V + E), 0-based index
// �ۼ���: forest528

// DAG(����Ŭ ���� ���� �׷���)������ ���
// answer[i]: ��� i�� �����ϱ���� ���ľ� �ϴ� �ܰ� ��

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