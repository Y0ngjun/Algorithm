#include <unordered_set>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b;
	std::cin >> a >> b;

	std::unordered_set<int> nums;

	for (int i = 0; i < a; ++i)
	{
		int num;
		std::cin >> num;
		nums.insert(num);
	}
	for (int i = 0; i < b; ++i)
	{
		int num;
		std::cin >> num;
		if (nums.find(num) == nums.end())
			nums.insert(num);
		else
			nums.erase(num);
	}

	std::cout << nums.size();

	return 0;
}