#include <iostream>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << ((x < w - x ? x : w - x) < (y < h - y ? y : h - y) ? (x < w - x ? x : w - x) : (y < h - y ? y : h - y));
	return 0;
}