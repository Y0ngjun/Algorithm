#include <stack>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		std::stack<char> vps;

		std::string str;
		std::cin >> str;

		for (auto iter = str.begin(); iter != str.end(); ++iter)
		{
			if (*iter == '(')
			{
				vps.push('(');
			}
			else if (*iter == ')')
			{
				if (!vps.empty() && vps.top() == '(')
					vps.pop();
				else
					vps.push(')');
			}
		}

		if (vps.empty())
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

	return 0;
}