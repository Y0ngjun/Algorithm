#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> node(n, vector<int>());
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		node[a - 1].push_back(b - 1);
		node[b - 1].push_back(a - 1);
	}

	vector<bool> checked(n, false);
	vector<int> parent(n);
	queue<int> bfs;
	bfs.push(0);
	checked[0] = true;
	while (!bfs.empty())
	{
		int current = bfs.front();
		bfs.pop();
		for (int i : node[current])
		{
			if (checked[i])
				continue;
			checked[i] = true;
			parent[i] = current;
			bfs.push(i);
		}
	}

	for (int i = 1; i < n; ++i)
		cout << parent[i] + 1 << '\n';

	return 0;
}