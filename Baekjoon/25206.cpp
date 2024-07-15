#include <iostream>
#include <string>

using namespace std;

int gtoi(string grade)
{
	if (grade == "A+")
		return 45;
	else if (grade == "A0")
		return 40;
	else if (grade == "B+")
		return 35;
	else if (grade == "B0")
		return 30;
	else if (grade == "C+")
		return 25;
	else if (grade == "C0")
		return 20;
	else if (grade == "D+")
		return 15;
	else if (grade == "D0")
		return 10;
	else if (grade == "P")
		return 0;
	else if (grade == "F")
		return 0;
}

int main()
{
	int sum = 0;
	int size = 0;
	for (int i = 0; i < 20; i++)
	{
		string name;
		double size_;
		string grade;
		cin >> name >> size_ >> grade;
		if (grade != "P")
		{
			size += size_;
			sum += (int(size_) * gtoi(grade));
		}
	}
	cout << double(sum) / double(size) / 10.0;
	return 0;
}