#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int node_num;
	cin >> node_num;
	vector<vector<int>> node(node_num, vector<int>(node_num, 0));

	for (int i = 0; i < node_num; ++i)
		for (int j = 0; j < node_num; ++j)
			cin >> node[i][j];

	for (int i = 0; i < node_num; ++i)
	{
		for (int j = 0; j < node_num; ++j)
		{
			// i에서 j로 가는 길이 있는지 탐색한다.
			// 있으면 1 출력 없으면 0 출력
			vector<int> visited(node_num, 0);
			queue<int> bfs;
			bfs.push(i);
			bool route = false;
			while (!bfs.empty())
			{
				int current_node = bfs.front();
				bfs.pop();
				for (int k = 0; k < node_num; ++k)
				{
					if (node[current_node][k] == 0)
						continue;
					if (visited[k])
						continue;
					// 현재 노드에서 k노드로 가는 길이 있고 방문하지 않았다면
					if (k == j)
					{
						// j로 가는 길이 있다면 큐를 비우고 탈출
						while (!bfs.empty())
							bfs.pop();
						route = true;
						break;
					}
					// k가 j가 아닌경우
					visited[k] = true;
					bfs.push(k);
				}
			}
			if (route)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << '\n';
	}
	return 0;
}

