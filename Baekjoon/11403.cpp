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
			// i���� j�� ���� ���� �ִ��� Ž���Ѵ�.
			// ������ 1 ��� ������ 0 ���
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
					// ���� ��忡�� k���� ���� ���� �ְ� �湮���� �ʾҴٸ�
					if (k == j)
					{
						// j�� ���� ���� �ִٸ� ť�� ���� Ż��
						while (!bfs.empty())
							bfs.pop();
						route = true;
						break;
					}
					// k�� j�� �ƴѰ��
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

