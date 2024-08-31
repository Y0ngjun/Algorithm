#include <queue>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int m, n;
		std::cin >> m >> n;
		std::queue<int> que;
		std::priority_queue<int> maxQue;
		for (int j = 0; j < m; ++j)
		{
			int num;
			std::cin >> num;
			que.push(num);
			maxQue.push(num);
		}

		int count = 1;
		int idx = n;

		while (!que.empty())
		{
			if (que.front() == maxQue.top())
			{
				if (idx == 0)
					break;
				que.pop();
				maxQue.pop();
				idx--;
				count++;
			}
			else
			{
				if (idx == 0)
					idx = que.size();
				idx--;
				int temp = que.front();
				que.pop();
				que.push(temp);
			}
		}
		std::cout << count << '\n';
	}
	return 0;
}