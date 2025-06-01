#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	long long dx1 = x2 - x1;
	long long dy1 = y2 - y1;
	long long dx2 = x4 - x3;
	long long dy2 = y4 - y3;

	// 수직 수직
	if (dx1 == 0 && dx2 == 0)
	{
		if (x1 == x3 && max(y1, y2) >= min(y3, y4) && min(y1, y2) <= max(y3, y4))
			cout << 1;
		else
			cout << 0;
	}
	// 수직 수평
	else if (dx1 == 0 && dy2 == 0)
	{
		if (min(y1, y2) <= y3 && y3 <= max(y1, y2) && min(x3, x4) <= x1 && x1 <= max(x3, x4))
			cout << 1;
		else
			cout << 0;
	}
	// 수직 대각
	else if (dx1 == 0)
	{
		long long dx2y = dy2 * x1 + y3 * dx2 - dy2 * x3;
		if (dx2 > 0)
		{
			if (min(x3, x4) <= x1 && x1 <= max(x3, x4)
				&& min(y1, y2) * dx2 <= dx2y && dx2y <= max(y1, y2) * dx2)
				cout << 1;
			else
				cout << 0;
		}
		else
		{
			if (min(x3, x4) <= x1 && x1 <= max(x3, x4)
				&& min(y1, y2) * dx2 >= dx2y && dx2y >= max(y1, y2) * dx2)
				cout << 1;
			else
				cout << 0;
		}
	}
	// 수평 수직
	else if (dy1 == 0 && dx2 == 0)
	{
		if (min(y3, y4) <= y1 && y1 <= max(y3, y4) && min(x1, x2) <= x3 && x3 <= max(x1, x2))
			cout << 1;
		else
			cout << 0;
	}
	// 수평 수평
	else if (dy1 == 0 && dy2 == 0)
	{
		if (y1 == y3 && max(x1, x2) >= min(x3, x4) && min(x1, x2) <= max(x3, x4))
			cout << 1;
		else
			cout << 0;
	}
	// 수평 대각
	else if (dy1 == 0)
	{
		long long dy2x = dx2 * y1 - dx2 * y3 + dy2 * x3;
		if (dy2 > 0)
		{
			if (min(y3, y4) <= y1 && y1 <= max(y3, y4)
				&& min(x1, x2) * dy2 <= dy2x && dy2x <= max(x1, x2) * dy2)
				cout << 1;
			else
				cout << 0;
		}
		else
		{
			if (min(y3, y4) <= y1 && y1 <= max(y3, y4)
				&& min(x1, x2) * dy2 >= dy2x && dy2x >= max(x1, x2) * dy2)
				cout << 1;
			else
				cout << 0;
		}
	}
	// 대각 수직
	else if (dx2 == 0)
	{
		long long dx1y = dy1 * x3 + y1 * dx1 - dy1 * x1;
		if (dx1 > 0)
		{
			if (min(x1, x2) <= x3 && x3 <= max(x1, x2)
				&& min(y3, y4) * dx1 <= dx1y && dx1y <= max(y3, y4) * dx1)
				cout << 1;
			else
				cout << 0;
		}
		else
		{
			if (min(x1, x2) <= x3 && x3 <= max(x1, x2)
				&& min(y3, y4) * dx1 >= dx1y && dx1y >= max(y3, y4) * dx1)
				cout << 1;
			else
				cout << 0;
		}
	}
	// 대각 수평
	else if (dy2 == 0)
	{
		long long dy1x = dx1 * y3 - dx1 * y1 + dy1 * x1;
		if (dy1 > 0)
		{
			if (min(y1, y2) <= y3 && y3 <= max(y1, y2)
				&& min(x3, x4) * dy1 <= dy1x && dy1x <= max(x3, x4) * dy1)
				cout << 1;
			else
				cout << 0;
		}
		else
		{
			if (min(y1, y2) <= y3 && y3 <= max(y1, y2)
				&& min(x3, x4) * dy1 >= dy1x && dy1x >= max(x3, x4) * dy1)
				cout << 1;
			else
				cout << 0;
		}
	}
	// 대각 대각
	else
	{
		long long div = dy1 * dx2 - dy2 * dx1;
		long long yz1 = (y1 * dx1 - dy1 * x1) * dx2;
		long long yz2 = (y3 * dx2 - dy2 * x3) * dx1;

		if (div == 0)
		{
			if (yz1 == yz2
				&& max(x1, x2) >= min(x3, x4) && max(x3, x4) >= min(x1, x2)
				&& max(y1, y2) >= min(y3, y4) && max(y3, y4) >= min(y1, y2))
				cout << 1;
			else
				cout << 0;
		}
		else
		{
			long long divx = dy1 * dx2 * x1 - dx1 * dy2 * x3 + (y3 - y1) * dx1 * dx2;
			if (div > 0)
			{
				if (min(x1, x2) * div <= divx && divx <= max(x1, x2) * div
					&& min(x3, x4) * div <= divx && divx <= max(x3, x4) * div)
					cout << 1;
				else
					cout << 0;
			}
			else
			{
				if (min(x1, x2) * div >= divx && divx >= max(x1, x2) * div
					&& min(x3, x4) * div >= divx && divx >= max(x3, x4) * div)
					cout << 1;
				else
					cout << 0;
			}
		}
	}

	return 0;
}