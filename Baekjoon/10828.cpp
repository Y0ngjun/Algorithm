#include <stack>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::stack<int> stk;

	for (int i = 0; i < n; ++i)
	{
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "push")
		{
			int num;
			std::cin >> num;
			stk.push(num);
		}
		else if (cmd == "pop")
		{
			if (stk.empty())
				std::cout << -1 << '\n';
			else
			{
				std::cout << stk.top() << '\n';
				stk.pop();
			}
		}
		else if (cmd == "size")
		{
			std::cout << stk.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (stk.empty())
				std::cout << 1 << '\n';
			else
				std::cout << 0 << '\n';
		}
		else if (cmd == "top")
		{
			if (stk.empty())
				std::cout << -1 << '\n';
			else
				std::cout << stk.top() << '\n';
		}
	}

	return 0;
}