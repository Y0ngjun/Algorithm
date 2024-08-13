#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int xmin=10000, xmax=-10000, ymin=10000, ymax=-10000;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x < xmin)
			xmin = x;
		if (x > xmax)
			xmax = x;
		if (y < ymin)
			ymin = y;
		if (y > ymax)
			ymax = y;
	}
	cout << (xmax - xmin) * (ymax - ymin);
	return 0;
}