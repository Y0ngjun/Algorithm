#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int A, B;
		cin >> A >> B;

		vector<string> history(10000);
		vector<bool> visited(10000, false);

		queue<int> bfs;
		bfs.push(A);
		visited[A] = true;

		while (!bfs.empty())
		{
			int num = bfs.front();
			bfs.pop();

			int num_D = num * 2 % 10000;
			if (!visited[num_D])
			{
				bfs.push(num_D);
				visited[num_D] = true;
				history[num_D] = history[num] + "D";
			}
			if (num_D == B)
			{
				break;
			}

			int num_S = num ? num - 1 : 9999;
			if (!visited[num_S])
			{
				bfs.push(num_S);
				visited[num_S] = true;
				history[num_S] = history[num] + "S";
			}
			if (num_S == B)
			{
				break;
			}

			int num_L = (num * 10 % 10000) + (num * 10 / 10000);
			if (!visited[num_L])
			{
				bfs.push(num_L);
				visited[num_L] = true;
				history[num_L] = history[num] + "L";
			}
			if (num_L == B)
			{
				break;
			}

			int num_R = (num % 10 * 1000) + num / 10;
			if (!visited[num_R])
			{
				bfs.push(num_R);
				visited[num_R] = true;
				history[num_R] = history[num] + "R";
			}
			if (num_R == B)
			{
				break;
			}
		}
		cout << history[B] << '\n';
	}

	return 0;
}