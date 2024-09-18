#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string quiz;
	cin >> quiz;

	int j = 0;
	while (j != quiz.size())
	{
		if (quiz[j] == '-')
		{
			for (j += 2; quiz[j] != '-' && j < quiz.size(); ++j)
			{
				if (quiz[j] == '+')
					quiz[j] = '-';
			}
		}
		else
			++j;
	}

	string temp = "";
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < quiz.size(); ++i)
	{
		switch (quiz[i])
		{
		case '+':
			if (flag)
				answer += stoi(temp);
			else
				answer -= stoi(temp);
			temp = "";
			flag = true;
			break;
		case '-':
			if (flag)
				answer += stoi(temp);
			else
				answer -= stoi(temp);
			temp = "";
			flag = false;
			break;
		default: temp += quiz[i];
		}
	}

	if (flag)
		answer += stoi(temp);
	else
		answer -= stoi(temp);

	cout << answer;

	return 0;
}