#include <vector>

using namespace std;

int solution(int n)
{
    int fib0 = 0, fib1 = 1, fib2 = 1;
    for (int i = 0; i < n; i++)
    {
        fib0 = fib1;
        fib1 = fib2;
        fib2 = (static_cast<long long>(fib0) + fib1) % 1234567;
    }

    return fib0;
}
