#include <cmath>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int m, n;
	std::cin >> m >> n;
	for (int i = m; i <= n; ++i)
	{
		int count = 0;
		int limit = static_cast<int>(sqrt(i));
		for (int j = 2; j <= limit; ++j)
		{
			if (i % j == 0)
			{
				count++; break;
			}
		}
		if (count == 0 && i != 1)
			std::cout << i << '\n';
	}

	return 0;
}