#include <bitset>

using namespace std;

int solution(int n)
{
    bitset<32> bits(n);
    return bits.count();
}
