#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations)
{
    multiset<int> ms;

    for (const auto& operation : operations)
    {
        stringstream ss(operation);
        string command;
        string value;

        ss >> command >> value;

        if (command == "I")
        {
            ms.insert(stoi(value));
        }
        else
        {
            if (value == "1")
            {
                if (!ms.empty())
                {
                    ms.erase(*ms.rbegin());
                }
            }
            else
            {
                if (!ms.empty())
                {
                    ms.erase(*ms.begin());
                }
            }
        }
    }

    if (!ms.empty())
    {
        return { *ms.rbegin(), *ms.begin() };
    }
    else
    {
        return { 0, 0 };
    }
}
