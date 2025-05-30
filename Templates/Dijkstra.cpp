// 다익스트라 알고리즘: O(V log V + E log V), 0-based index
// 작성자: forest528

#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int V, int root, vector<int>& distance, const vector<vector<pair<int, int>>>& graph)
{
	distance.assign(V, INT_MAX);
	distance[root] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, root });

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist > distance[node])
			continue;

		for (const pair<int, int>& edge : graph[node])
		{
			int cost = dist + edge.first;
			int neighbor = edge.second;

			if (cost < distance[neighbor])
			{
				pq.push({ cost, neighbor });
				distance[neighbor] = cost;
			}
		}
	}
}