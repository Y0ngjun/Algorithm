#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int main()
{
	int node_num, edge_num;
	cin >> node_num >> edge_num;

	vector<vector<int>> distance(node_num, vector<int>(node_num, -1));
	for (int i = 0; i < edge_num; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		distance[start - 1][end - 1] = cost;
		distance[end - 1][start - 1] = cost;
	}

	int v1, v2;
	cin >> v1 >> v2;
	--v1;
	--v2;

	// 1 to v1, v2
	int startToV1 = -1;
	int startToV2 = -1;
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> bfs;
		vector<bool> visited(node_num, false);
		bfs.push({ 0,0 });
		while (!bfs.empty() && (!visited[v1] || !visited[v2]))
		{
			int curr = bfs.top().first;
			int cost = bfs.top().second;
			bfs.pop();

			if (visited[curr])
				continue;
			visited[curr] = true;

			if (curr == v1)
				startToV1 = cost;
			if (curr == v2)
				startToV2 = cost;

			for (int i = 0; i < node_num; ++i)
				if (!visited[i] && distance[curr][i] != -1)
					bfs.push({ i,cost + distance[curr][i] });
		}
	}

	// v1 to v2, n-1
	int v1ToV2 = -1;
	int v1ToEnd = -1;
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> bfs;
		vector<bool> visited(node_num, false);
		bfs.push({ v1,0 });
		while (!bfs.empty() && (!visited[v2] || !visited[node_num - 1]))
		{
			int curr = bfs.top().first;
			int cost = bfs.top().second;
			bfs.pop();

			if (visited[curr])
				continue;
			visited[curr] = true;

			if (curr == v2)
				v1ToV2 = cost;
			if (curr == node_num - 1)
				v1ToEnd = cost;

			for (int i = 0; i < node_num; ++i)
				if (!visited[i] && distance[curr][i] != -1)
					bfs.push({ i,cost + distance[curr][i] });
		}
	}

	// v2 to n-1
	int v2ToEnd = -1;
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> bfs;
		vector<bool> visited(node_num, false);
		bfs.push({ v2,0 });
		while (!bfs.empty() && !visited[node_num - 1])
		{
			int curr = bfs.top().first;
			int cost = bfs.top().second;
			bfs.pop();

			if (visited[curr])
				continue;
			visited[curr] = true;

			if (curr == node_num - 1)
				v2ToEnd = cost;

			for (int i = 0; i < node_num; ++i)
				if (!visited[i] && distance[curr][i] != -1)
					bfs.push({ i,cost + distance[curr][i] });
		}
	}

	int path1, path2;
	if (startToV1 == -1 || v1ToV2 == -1 || v2ToEnd == -1)
		path1 = -1;
	else
		path1 = startToV1 + v1ToV2 + v2ToEnd;

	if (startToV2 == -1 || v1ToV2 == -1 || v1ToEnd == -1)
		path2 = -1;
	else
		path2 = startToV2 + v1ToV2 + v1ToEnd;

	if (path1 == -1 && path2 == -1)
		cout << -1;
	else if (path1 == -1)
		cout << path2;
	else if (path2 == -1)
		cout << path1;
	else
		cout << (path1 > path2 ? path2 : path1);

	return 0;
}
