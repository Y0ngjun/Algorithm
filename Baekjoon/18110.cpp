#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int> scores(n);
	for (int& score : scores)
		std::cin >> score;

	std::sort(scores.begin(), scores.end());

	int exclude = round(static_cast<double>(n) * 0.15);

	int sum = 0;
	for (int i = 0 + exclude; i < n - exclude; ++i)
	{
		sum += scores[i];
	}

	int mean = round(static_cast<double>(sum) / (n - 2 * exclude));
	if (n == 0)
		mean = 0;
	std::cout << mean;

	return 0;
}