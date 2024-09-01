#include <stack>
#include <string>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::stack<int> stk;
	stk.push(1);
	int count = 1;

	std::string answer = "+\n";

	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;

		if (answer == "NO")
			continue;

		if (stk.empty() || stk.top() != num)
		{
			if (!stk.empty() && num < stk.top())
			{
				answer = "NO";
				continue;
			}
			while (count != num)
			{
				count++;
				stk.push(count);
				answer += "+\n";
			}
		}
		if (stk.top() == num)
		{
			stk.pop();
			answer += "-\n";
		}
	}

	std::cout << answer;

	return 0;
}