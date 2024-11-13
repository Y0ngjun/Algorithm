#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Comp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<bool> visited(100001, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
	pq.push({ n,0 });
	while (!pq.empty())
	{
		int idx = pq.top().first;
		int time = pq.top().second;
		pq.pop();

		if (visited[idx])
			continue;
		visited[idx] = true;

		if (idx == k)
		{
			cout << time;
			return 0;
		}

		if (idx + 1 <= 100000 && !visited[idx + 1])
			pq.push({ idx + 1,time + 1 });
		if (idx - 1 >= 0 && !visited[idx - 1])
			pq.push({ idx - 1,time + 1 });
		if (idx * 2 <= 100000 && !visited[idx * 2])
			pq.push({ idx * 2,time });
	}

	return 0;
}