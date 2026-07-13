long long solution(long long n)
{
    int count[10] = {};
    while (n > 0)
    {
        int digit = n % 10;
        count[digit]++;
        n /= 10;
    }

    long long answer = 0;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < count[i]; j++)
        {
            answer *= 10;
            answer += i;
        }
    }

    return answer;
}
