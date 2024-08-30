#include <stack>
#include <string>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	while (true)
	{
		std::string str;
		std::getline(std::cin, str);

		if (str == ".")
			break;

		std::stack<char> stk;

		for (const char& c : str)
		{
			switch (c)
			{
			case '(':
			case '[':
				stk.push(c);
				break;
			case ')':
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
					stk.push(c);
				break;
			case ']':
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
					stk.push(c);
				break;
			}
		}

		if (stk.empty())
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}
	return 0;
}