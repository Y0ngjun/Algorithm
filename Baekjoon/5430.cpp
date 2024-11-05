#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		string p, arr;
		int n;
		cin >> p;
		cin >> n;
		cin >> arr;

		deque<int> numArr;
		string temp = "";
		for (int i = 1; i < arr.size() - 1; ++i)
		{
			if ('0' <= arr[i] && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',')
			{
				numArr.push_back(stoi(temp));
				temp = "";
			}
		}
		if (temp != "")
			numArr.push_back(stoi(temp));

		bool isError = false;
		bool isR = false;
		for (char c : p)
		{
			if (c == 'R')
			{
				isR = isR ? false : true;
			}
			else if (c == 'D')
			{
				if (numArr.empty())
				{
					isError = true;
					break;
				}
				if (isR)
					numArr.pop_back();
				else
					numArr.pop_front();
			}
		}

		if (isError)
			cout << "error\n";
		else
		{
			cout << '[';
			if (isR)
			{
				if (numArr.size()) cout << numArr[numArr.size() - 1];
				for (int i = numArr.size() - 2; i >= 0; --i)
					cout << ',' << numArr[i];
			}
			else
			{
				if (numArr.size()) cout << numArr[0];
				for (int i = 1; i < numArr.size(); ++i)
					cout << ',' << numArr[i];
			}
			cout << "]\n";
		}
	}

	return 0;
}