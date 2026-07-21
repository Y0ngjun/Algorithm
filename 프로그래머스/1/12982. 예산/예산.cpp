#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    
    sort(d.begin(), d.end());
    int i = 0;
    while(i < d.size())
    {
        if(d[i] <= budget)
        {
            answer++;
            budget -= d[i];
        }
        else
        {
            break;
        }
        i++;
    }
    
    return answer;
}