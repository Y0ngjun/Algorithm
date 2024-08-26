#include <unordered_set>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::unordered_set<int> s;

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		s.insert(num);
	}

	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int num;
		std::cin >> num;
		if (s.find(num) != s.end())
		{
			std::cout << "1\n";
		}
		else
		{
			std::cout << "0\n";
		}
	}

	return 0;
}