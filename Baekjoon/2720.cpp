#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		int q, d, kn, p;
		q = c / 25;
		c = c % 25;
		d = c / 10;
		c = c % 10;
		kn = c / 5;
		c = c % 5;
		p = c / 1;
		cout << q << ' ' << d << ' ' << kn << ' ' << p << endl;
	}
	return 0;
}