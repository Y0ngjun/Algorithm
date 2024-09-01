#include <cmath>
#include <map>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		auto result = m.insert({ num, 1 });
		if (result.second)
			continue;
		result.first->second++;
	}

	int sum = 0;
	for (const auto& pair : m)
	{
		sum += pair.first * pair.second;
	}

	int mean = round(static_cast<double>(sum) / n);

	int count = 0;
	int middle;
	for (const auto& pair : m)
	{
		count += pair.second;
		if (count >= n / 2 + 1)
		{
			middle = pair.first;
			break;
		}
	}

	int freq = 0;
	int freqNum;
	int freqCount = 0;
	for (const auto& pair : m)
	{
		if (freq < pair.second)
		{
			freq = pair.second;
			freqNum = pair.first;
			freqCount = 1;
		}
		else if (freq == pair.second)
		{
			if (++freqCount == 2)
				freqNum = pair.first;
		}
	}

	int bound = (--m.end())->first - m.begin()->first;

	std::cout << mean << '\n';
	std::cout << middle << '\n';
	std::cout << freqNum << '\n';
	std::cout << bound << '\n';

	return 0;
}