// BOJ 12456 - 모닝커피 (Large)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		long long K;
		cin >> N >> K;

		vector<pair<pair<long long, long long>, int>> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i].first.first >> v[i].first.second >> v[i].second;

		sort(v.begin(), v.end(), [](const auto& a, const auto& b)
			{
				return a.first.second > b.first.second;
			});

		priority_queue<pair<int, long long>> pq;
		long long ans = 0;
		int i = 0;
		while (K > 0)
		{
			// 큐 업데이트
			while (i < N && v[i].first.second >= K)
			{
				pq.push({ v[i].second, v[i].first.first });
				++i;
			}

			// 다음 업데이트 시기
			long long d = (i < N ? v[i].first.second : 0);

			// 커피 마시기
			while (K > d)
			{
				if (pq.empty())
				{
					K = d;
				}
				else
				{
					auto [s, c] = pq.top();
					pq.pop();

					if (c > K - d)
					{
						c -= K - d;
						ans += s * (K - d);
						pq.push({ s, c });
						K = d;
					}
					else
					{
						ans += s * c;
						K -= c;
					}
				}
			}
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
