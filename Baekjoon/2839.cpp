#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int bag = -1;
	for (int i = 0; i <= n / 5; ++i) // 5kg 봉지가 0개에서 n/5개 까지 가능
	{
		int sugar = n;
		int count = 0;

		sugar -= i * 5; // 설탕을 5kg * 봉지수 만큼 차감
		count += i; // 봉지 카운트를 5kg봉지만큼 증가
		if (sugar % 3 == 0) // 남은 설탕이 3으로 나누어 떨어진다면
		{
			count += (sugar / 3); // 봉지카운트를 3kg봉지만큼 증가
			bag = count; // count는 점점 줄어듬 이전값과 비교가 불필요
		}
	}
	cout << bag;
	return 0;
}