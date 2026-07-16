int solution(int n)
{
    int p0 = 0, p1 = 1, p2 = 2;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        p0 = p1;
        p1 = p2;
        p2 = (p0 + p1) % mod;
    }

    return p0;
}
