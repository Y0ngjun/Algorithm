#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	while (a + b + c)
	{
		if (a + b > c && a + c > b && b + c > a)
			cout << ((a == b && b == c) ? "Equilateral\n" : ((a == b || b == c || a == c) ? "Isosceles\n" : "Scalene\n"));
		else
			cout << "Invalid\n";
		cin >> a >> b >> c;
	}
	return 0;
}

