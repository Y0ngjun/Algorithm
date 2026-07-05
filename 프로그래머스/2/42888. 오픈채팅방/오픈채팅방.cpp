#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    unordered_map<string, string> id2name;

    for (const string& rec : record)
    {
        istringstream iss(rec);
        string command;

        iss >> command;

        if (command == "Enter" || command == "Change")
        {
            string id, name;
            iss >> id >> name;

            id2name[id] = name;
        }
    }

    for (const string& rec : record)
    {
        istringstream iss(rec);
        string command, id;

        iss >> command >> id;

        if (command == "Enter")
        {
            answer.push_back(id2name[id] + "님이 들어왔습니다.");
        }
        else if (command == "Leave")
        {
            answer.push_back(id2name[id] + "님이 나갔습니다.");
        }
    }

    return answer;
}
