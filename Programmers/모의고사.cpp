#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {

	int a1 = 0, a2 = 0, a3 = 0;

	vector<int> arr1 = { 1,2,3,4,5 };
	vector<int> arr2 = { 2,1,2,3,2,4,2,5 };
	vector<int> arr3 = { 3,3,1,1,2,2,4,4,5,5 };

	int count1 = 0, count2 = 0, count3 = 0;

	for (int i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == arr1[a1++ % 5])
			count1++;
		if (answers[i] == arr2[a2++ % 8])
			count2++;
		if (answers[i] == arr3[a3++ % 10])
			count3++;
	}

	vector<int> answer;
	if (count1 >= count2 && count1 >= count3)
		answer.push_back(1);
	if (count2 >= count1 && count2 >= count3)
		answer.push_back(2);
	if (count3 >= count2 && count3 >= count1)
		answer.push_back(3);

	return answer;
}