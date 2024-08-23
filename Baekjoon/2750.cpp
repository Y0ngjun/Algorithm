#include <vector>
#include <algorithm>

#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
	}
	std::sort(v.begin(), v.end());
	for (int i : v)
	{
		std::cout << i << std::endl;
	}
	return 0;
}