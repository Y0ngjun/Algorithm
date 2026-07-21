#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> um;
    for(int i: tangerine)
        um[i]++;
    
    vector<int> v;
    for(const auto& p: um)
        v.push_back(p.second);
    
    sort(v.rbegin(), v.rend());
    
    int answer = 0;
    int sum = 0;
    
    for(int i:v)
    {
        sum += i;
        answer++;
        if(sum >= k)
            break;
    }
    
    return answer;
}