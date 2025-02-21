#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // string answer = "";
    
    map<string, int> mp;
    
    for(auto i : participant){
        mp[i]++;
    }    
    
    for(auto i: completion){
        mp[i]--;
    }
    
    for(auto i: mp){
        if(i.second == 1)
            return i.first;
    }
    
    
    // return answer;
}