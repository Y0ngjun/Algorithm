#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	std::unordered_map<std::string, std::string> pokemons;
	for (int i = 0; i < n; ++i)
	{
		std::string pokemon;
		std::cin >> pokemon;

		pokemons.insert({ std::to_string(pokemons.size() + 1), pokemon });
	}

	std::unordered_map<std::string, std::string> reverse;
	for (int i = 1; i <= n; ++i)
	{
		reverse.insert({ pokemons.find(std::to_string(i))->second, std::to_string(i) });
	}

	for (int i = 0; i < m; ++i)
	{
		std::string quiz;
		std::cin >> quiz;
		if (pokemons.find(quiz) == pokemons.end())
		{
			std::cout << reverse.find(quiz)->second + '\n';
		}
		else
		{
			std::cout << pokemons.find(quiz)->second + '\n';
		}
	}

	return 0;
}