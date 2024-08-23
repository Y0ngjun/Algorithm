#include <vector>
#include <algorithm>

#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> score(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> score[i];
	}
	std::sort(score.begin(), score.end());
	std::cout << score[n - k];
	return 0;
}