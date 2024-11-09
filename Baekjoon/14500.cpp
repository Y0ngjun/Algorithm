#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> paper(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> paper[i][j];

	int max = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m - 3; ++j)
		{
			int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
			if (sum > max)
				max = sum;
		}
	}

	for (int i = 0; i < n - 3; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int sum = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
			if (sum > max)
				max = sum;
		}
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			int sum = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1];
			if (sum > max)
				max = sum;
		}
	}

	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			int left_bar = paper[i][j] + paper[i + 1][j] + paper[i + 2][j];

			int sum = left_bar + paper[i][j + 1];
			if (sum > max)
				max = sum;

			sum = left_bar + paper[i + 1][j + 1];
			if (sum > max)
				max = sum;

			sum = left_bar + paper[i + 2][j + 1];
			if (sum > max)
				max = sum;

			int right_bar = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];

			sum = right_bar + paper[i][j];
			if (sum > max)
				max = sum;

			sum = right_bar + paper[i + 1][j];
			if (sum > max)
				max = sum;

			sum = right_bar + paper[i + 2][j];
			if (sum > max)
				max = sum;

			int middle_bar = paper[i + 1][j] + paper[i + 1][j + 1];

			sum = middle_bar + paper[i][j] + paper[i + 2][j + 1];
			if (sum > max)
				max = sum;

			sum = middle_bar + paper[i][j + 1] + paper[i + 2][j];
			if (sum > max)
				max = sum;
		}
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < m - 2; ++j)
		{
			int upper_bar = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];

			int sum = upper_bar + paper[i + 1][j];
			if (sum > max)
				max = sum;

			sum = upper_bar + paper[i + 1][j + 1];
			if (sum > max)
				max = sum;

			sum = upper_bar + paper[i + 1][j + 2];
			if (sum > max)
				max = sum;

			int lowwer_bar = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];

			sum = lowwer_bar + paper[i][j];
			if (sum > max)
				max = sum;

			sum = lowwer_bar + paper[i][j + 1];
			if (sum > max)
				max = sum;

			sum = lowwer_bar + paper[i][j + 2];
			if (sum > max)
				max = sum;

			int middle_bar = paper[i][j + 1] + paper[i + 1][j + 1];

			sum = middle_bar + paper[i][j] + paper[i + 1][j + 2];
			if (sum > max)
				max = sum;

			sum = middle_bar + paper[i][j + 2] + paper[i + 1][j];
			if (sum > max)
				max = sum;
		}
	}

	cout << max;

	return 0;
}