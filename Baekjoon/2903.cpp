#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a = 2;
	for (int i = 0; i < n; i++)
		a += (a - 1);
	cout << a * a;
	return 0;
}