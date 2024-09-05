#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;
	for (auto iter = numbers.begin(); iter != numbers.end() - 1; ++iter)
	{
		for (auto it = iter + 1; it != numbers.end(); ++it)
		{
			answer.push_back(*iter + *it);
		}
	}

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}