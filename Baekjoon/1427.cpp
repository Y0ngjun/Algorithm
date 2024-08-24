#include <cstring>
#include <algorithm>
#include <functional>

#include <iostream>

int main()
{
	char n[11];
	std::cin >> n;
	std::sort(n, n + strlen(n), std::greater<>());
	std::cout << n;
	return 0;
}