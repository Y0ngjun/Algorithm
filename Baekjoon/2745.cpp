#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int sum = 0;
	string num;
	int base;
	cin >> num >> base;
	for (int i = 0; i < num.size(); i++)
	{
		char c = num[num.size() - 1 - i];
		if (c >= '0' && c <= '9')
		{
			sum += (c - '0') * pow(base, i);
		}
		else
		{
			sum += (c - 'A' + 10) * pow(base, i);
		}
	}
	cout << sum;
	return 0;
}