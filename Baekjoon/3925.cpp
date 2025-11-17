// BOJ 3925 암호화의 취약점 찾기
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        vector<unsigned int> M(9);

        for (int i = 0; i < 9; ++i)
        {
            cin >> hex >> M[i];
        }

        // Ci = NSUM_(i-1) / 2
        // (MSUM_i % 2 == M9_i) && (C_i % 2 == 0)   -->  K_i == 0
        // (MSUM_i % 2 == M9_i) && (C_i % 2 != 0)   -->  K_i == 1
        // (MSUM_i % 2 != M9_i) && (C_i % 2 == 0)   -->  K_i == 1
        // (MSUM_i % 2 != M9_i) && (C_i % 2 != 0)   -->  K_i == 0

        unsigned int K = 0;
        unsigned int C = 0;

        for (int i = 0; i < 32; ++i)
        {
            unsigned int MSUM = 0;

            for (int j = 0; j < 8; ++j)
            {
                MSUM += (M[j] & (1 << i)) > 0 ? 1 : 0;
            }

            if (((MSUM % 2) == ((M[8] & (1 << i)) > 0 ? 1 : 0)) ^ ((C % 2) == 0))
            {
                K = K | (1 << i);
            }

            unsigned int NSUM = C;

            for (int j = 0; j < 8; ++j)
            {
                NSUM += ((M[j] & (1 << i)) > 0 ? 1 : 0) ^ ((K & (1 << i)) > 0 ? 1 : 0);
            }

            C = NSUM / 2;
        }

        cout << hex << K << '\n';
    }

    return 0;
}
