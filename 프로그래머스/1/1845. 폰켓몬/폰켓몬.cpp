#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool cmp(const pair<int, int>&a, const pair<int, int>&b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<int> nums)
{
    int answer = 0, Max = nums.size() / 2;
    map<int, int> mp;
    
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;            
    }
    
    for(auto i: mp){
        answer++;
        if(answer == Max)
            break;
    }
    
    
    return answer;
}