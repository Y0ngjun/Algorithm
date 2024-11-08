#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ladder_num, snake_num;
	cin >> ladder_num >> snake_num;

	unordered_map<int, int> path;
	for (int i = 0; i <= 100; ++i)
		path[i] = i;
	for (int i = 0; i < ladder_num + snake_num; ++i)
	{
		int start, end;
		cin >> start >> end;
		path[start] = end;
	}

	vector<int> count(101, 0);
	vector<int> visited(101, 0);
	queue<pair<int,int>> bfs;
	bfs.push({1,0});
	visited[1] = true;
	while (!bfs.empty())
	{
		int idx = bfs.front().first;
		int cnt = bfs.front().second;
		bfs.pop();

		count[idx] = cnt;
		if (idx == 100)
			break;

		for (int i = 1; i <= 6; ++i)
		{
			int nidx = idx + i;
			int ncnt = cnt + 1;
			if (nidx > 100)
				break;
			if (visited[path[nidx]])
				continue;
			bfs.push({ path[nidx], ncnt });
			visited[path[nidx]] = true;
		}
	}

	cout << count[100];

	return 0;
}