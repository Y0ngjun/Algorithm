#include <stack>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int k;
	std::cin >> k;

	long long sum = 0;

	std::stack<int> stk;

	for (int i = 0; i < k; ++i)
	{
		int num;
		std::cin >> num;
		if (num == 0)
			stk.pop();
		else
			stk.push(num);
	}
	int size = stk.size();
	for (int i = 0; i < size; ++i)
	{
		sum += stk.top();
		stk.pop();
	}
	std::cout << sum;

	return 0;
}