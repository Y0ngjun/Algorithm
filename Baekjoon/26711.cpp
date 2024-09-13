#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string a;
	string b;

	cin >> a >> b;

	int aSize = a.size();
	int bSize = b.size();

	int len = aSize > bSize ? aSize : bSize;

	vector<int> A(len);
	for (int i = 0; i < aSize; ++i)
		A[len - 1 - i] = a[aSize - 1 - i] - '0';

	vector<int> B(len);
	for (int i = 0; i < bSize; ++i)
		B[len - 1 - i] = b[bSize - 1 - i] - '0';

	vector<int> answer(len + 1);

	for (int i = 0; i < len; ++i)
	{
		int idx = len - 1 - i;
		int num = A[idx] + B[idx] + answer[idx + 1];
		if (num > 9)
			answer[idx]++;
		answer[idx + 1] = num % 10;
	}

	if (answer[0] == 0)
		for (int i = 1; i < len + 1; ++i)
			cout << answer[i];
	else
		for (int i = 0; i < len + 1; ++i)
			cout << answer[i];

	return 0;
}