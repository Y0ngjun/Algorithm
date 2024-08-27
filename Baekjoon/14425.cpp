#include <unordered_set>
#include <string>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	std::unordered_set<std::string> strings;
	for (int i = 0; i < n; ++i)
	{
		std::string str;
		std::cin >> str;
		strings.insert(str);
	}

	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		std::string str;
		std::cin >> str;
		if (strings.find(str) != strings.end())
		{
			++count;
		}
	}

	std::cout << count;

	return 0;
}