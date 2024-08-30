#include <queue>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::queue<int> que;

	for (int i = 0; i < n; ++i)
	{
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "push")
		{
			int num;
			std::cin >> num;
			que.push(num);
		}
		else if (cmd == "pop")
		{
			if (que.empty())
				std::cout << -1 << '\n';
			else
			{
				std::cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (cmd == "size")
		{
			std::cout << que.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (que.empty())
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else if (cmd == "front")
		{
			if (que.empty())
				std::cout << -1 << '\n';
			else
				std::cout << que.front() << '\n';
		}
		else if (cmd == "back")
		{
			if (que.empty())
				std::cout << -1 << '\n';
			else
				std::cout << que.back() << '\n';
		}
	}

	return 0;
}