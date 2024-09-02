#include <vector>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int k, n;
	std::cin >> k >> n;

	std::vector<int> line(k);
	long long sum = 0;
	for (int i = 0; i < k; ++i)
	{
		std::cin >> line[i];
		sum += line[i];
	}

	long long max = sum / n + 1;
	long long min = 1;
	long long middle = (max + min) / 2;

	if (max == 0)
	{
		std::cout << 0;
		return 0;
	}

	while (min + 1 < max)
	{
		int count = 0;
		for (int l : line)
		{
			l -= middle;
			while (l >= 0)
			{
				count++;
				l -= middle;
			}
		}

		if (count >= n)
		{
			min = middle;
		}

		else
		{
			max = middle;
		}

		middle = (max + min) / 2;
	}

	std::cout << middle;

	return 0;
}