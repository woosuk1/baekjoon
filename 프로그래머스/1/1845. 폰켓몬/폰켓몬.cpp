#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 1, temp = 0;
    
    sort(nums.begin(), nums.end());
    
    temp = nums[0];
    
    for(int i=1; i<nums.size(); i++){
        if(temp == nums[i]){
            continue;
        }
        else{
            if(answer < nums.size() / 2){
                temp = nums[i];
                answer++;
            }
            else{
                return answer;
            }
        }
        
    }
    
    return answer;
}