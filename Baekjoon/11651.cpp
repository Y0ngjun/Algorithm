#include <vector>
#include <queue>
#include <iostream>

struct Point
{
	int _x;
	int _y;

	Point(int x, int y)
		: _x(x), _y(y)
	{

	}

	bool operator <(const Point& point) const
	{
		if (_y == point._y)
		{
			return _x < point._x;
		}
		else
		{
			return _y < point._y;
		}
	}

	bool operator >(const Point& point) const
	{
		return point < *this;
	}
};

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::priority_queue<Point, std::vector<Point>, std::greater<Point>> minHeap;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		minHeap.push(Point(x, y));
	}
	while (!minHeap.empty())
	{
		std::cout << minHeap.top()._x << ' ' << minHeap.top()._y << '\n';
		minHeap.pop();
	}
	return 0;
}