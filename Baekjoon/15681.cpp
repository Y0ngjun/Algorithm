#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, q;
	cin >> n >> r >> q;

	vector<vector<int>> linked_list(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		linked_list[a].push_back(b);
		linked_list[b].push_back(a);
	}

	vector<int> parent(n + 1);
	vector<int> leafs;
	queue<int> bfs;
	bfs.push(r);
	while (!bfs.empty())
	{
		int curr = bfs.front();
		bfs.pop();

		if (linked_list[curr].size() == 1 && curr != r)
		{
			leafs.push_back(curr);
			continue;
		}
		for (const auto& node : linked_list[curr])
		{
			if (node == parent[curr])
				continue;
			parent[node] = curr;
			bfs.push(node);
		}
	}

	for (const auto& leaf : leafs)
		bfs.push(leaf);

	vector<bool> visited(n + 1);
	vector<int> subtree(n + 1);
	while (!bfs.empty())
	{
		int curr = bfs.front();
		bfs.pop();

		if (visited[curr])
			continue;

		bool isEnd = true;
		int temp = 1;
		for (const auto& node : linked_list[curr])
		{
			if (node == parent[curr])
				continue;

			if (!visited[node])
			{
				isEnd = false;
				break;
			}
			temp += subtree[node];
		}

		if (isEnd)
		{
			subtree[curr] = temp;
			visited[curr] = true;
			bfs.push(parent[curr]);
		}
	}

	for (int i = 0; i < q; ++i)
	{
		int num;
		cin >> num;
		cout << subtree[num] << '\n';
	}

	return 0;
}