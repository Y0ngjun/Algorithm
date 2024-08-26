#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::vector<int*> nums(n);
	for (int i = 0; i < n; ++i)
	{
		nums[i] = new int;
		std::cin >> *nums[i];
	}

	std::vector<int*> sorted = nums;
	std::sort(sorted.begin(), sorted.end(), [](int* a, int* b) { return *a < *b; });
	int order = 0;
	int prev = 1000000001;
	for (int* num : sorted)
	{
		if (*num != prev)
		{
			prev = *num;
			*num = order++;
		}
		else
		{
			*num = order - 1;
		}
	}

	for (int* num : nums)
	{
		std::cout << *num << ' ';
		delete num;
	}

	return 0;
}