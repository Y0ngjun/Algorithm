#include <set>
#include <unordered_set>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	std::unordered_set<std::string> persons;
	for (int i = 0; i < n; ++i)
	{
		std::string person;
		std::cin >> person;
		persons.insert(person);
	}

	std::set<std::string> sorted;
	for (int i = 0; i < m; ++i)
	{
		std::string person;
		std::cin >> person;
		if (persons.find(person) != persons.end())
		{
			sorted.insert(person);
		}
	}

	std::cout << sorted.size() << '\n';
	for (auto person : sorted)
		std::cout << person << '\n';


	return 0;
}