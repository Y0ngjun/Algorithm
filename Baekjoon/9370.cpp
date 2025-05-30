#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;

		vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
		for (int i = 0; i < m; ++i)
		{
			int a, b, d;
			cin >> a >> b >> d;

			graph[a - 1].push_back({ d, b - 1 });
			graph[b - 1].push_back({ d, a - 1 });
		}

		vector<int> candi(t);
		for (int i = 0; i < t; ++i)
		{
			int x;
			cin >> x;
			candi[i] = x - 1;
		}
		sort(candi.begin(), candi.end());

		vector<int> s_distance, g_distance, h_distance;
		Dijkstra(n, s - 1, s_distance, graph);
		Dijkstra(n, g - 1, g_distance, graph);
		Dijkstra(n, h - 1, h_distance, graph);

		for (int c : candi)
		{
			if (s_distance[c] == s_distance[g - 1] + g_distance[h - 1] + h_distance[c] ||
				s_distance[c] == s_distance[h - 1] + h_distance[g - 1] + g_distance[c])
				cout << c + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}