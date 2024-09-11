#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
	vector<int> stage(N + 1, 0);
	for (auto iter : stages)
		stage[iter - 1]++;

	vector<int> clear(N, 0);
	int sum = stage[N];
	int k = 1;

	for (auto iter = stage.rbegin() + 1; iter != stage.rend(); ++iter)
	{
		sum += *iter;
		clear[N - k++] = sum;
	}

	vector<pair<int, double>> vec;
	for (int i = 0; i < N; ++i)
	{
		if (clear[i] == 0)
			vec.push_back({ i + 1, 0 });
		else
			vec.push_back({ i + 1, static_cast<double>(stage[i]) / clear[i] });
	}

	sort(vec.begin(), vec.end(), [](auto a, auto b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			return a.second > b.second;
		});

	vector<int> answer;
	for (int i = 0; i < N; ++i)
	{
		answer.push_back(vec[i].first);
	}

	return answer;
}