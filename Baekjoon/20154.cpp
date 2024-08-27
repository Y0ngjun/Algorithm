#include <string>
#include <iostream>

int ctoi(char c)
{
	switch (c)
	{
	case 'A':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'K':
	case 'M':
	case 'N':
		return 3;
	case 'B':
	case 'D':
	case 'P':
	case 'Q':
	case 'R':
	case 'T':
	case 'W':
	case 'X':
	case 'Y':
		return 2;
	default:
		return 1;
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string str;
	std::cin >> str;

	int sum = 0;

	for (auto iter = str.begin(); iter != str.end(); ++iter)
	{
		sum += ctoi(*iter);
	}

	if (sum % 2 == 1)
	{
		std::cout << "I'm a winner!";
	}
	else
	{
		std::cout << "You're the winner?";
	}

	return 0;
}