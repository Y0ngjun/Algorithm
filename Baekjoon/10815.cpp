#include <unordered_set>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::unordered_set<int> cards;
	for (int i = 0; i < n; ++i)
	{
		int card;
		std::cin >> card;
		cards.insert(card);
	}

	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int num;
		std::cin >> num;
		if (cards.find(num) == cards.end())
		{
			std::cout << "0 ";
		}
		else
		{
			std::cout << "1 ";
		}
	}

	return 0;
}