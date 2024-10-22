#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Comp
{
	bool operator()(const int& a, const int& b)
	{
		int absA = abs(a);
		int absB = abs(b);
		if (absA != absB)
			return absA > absB;
		return a > b;
	}
};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, Comp> pq;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num)
			pq.push(num);
		else
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}