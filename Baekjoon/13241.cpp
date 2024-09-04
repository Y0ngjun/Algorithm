#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long a, b;
	std::cin >> a >> b;
	long long big = a > b ? a : b;
	long long small = a > b ? b : a;
	long long num = big;
	while (true)
	{
		if (num % small == 0)
			break;
		else
			num += big;
	}

	std::cout << num;

	return 0;
}