#include <string>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string str1, str2, str3;
	std::cin >> str1 >> str2 >> str3;

	int num;

	if (atoi(str1.c_str()) != 0)
		num = atoi(str1.c_str()) + 3;
	else if (atoi(str2.c_str()) != 0)
		num = atoi(str2.c_str()) + 2;
	else if (atoi(str3.c_str()) != 0)
		num = atoi(str3.c_str()) + 1;

	if (num % 3 == 0)
		std::cout << "Fizz";
	if (num % 5 == 0)
		std::cout << "Buzz";
	if (num % 3 != 0 && num % 5 != 0)
		std::cout << num;

	return 0;
}