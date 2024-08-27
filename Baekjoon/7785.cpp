#include <set>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::set<std::string> log;

	for (int i = 0; i < n; ++i)
	{
		std::string name, stat;
		std::cin >> name >> stat;
		if (stat == "enter")
		{
			log.insert(name);
		}
		else
		{
			log.erase(name);
		}
	}

	for (auto iter = log.rbegin(); iter != log.rend(); ++iter)
	{
		std::cout << *iter + '\n';
	}

	return 0;
}