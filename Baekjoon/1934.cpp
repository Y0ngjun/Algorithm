#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		int num = a;
		while (true)
		{
			if (num % b == 0)
				break;
			else
				num += a;
		}

		std::cout << num << '\n';
	}
	return 0;
}