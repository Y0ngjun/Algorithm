#include <unordered_map>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::unordered_map<int, int> cards;

	for (int i = 0; i < n; ++i)
	{
		int card;
		std::cin >> card;
		if (cards[card] == 0)
		{
			cards[card] = 1;
		}
		else
		{
			cards[card]++;
		}
	}

	int m;
	std::cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int card;
		std::cin >> card;
		std::cout << cards[card] << ' ';
	}

	return 0;
}