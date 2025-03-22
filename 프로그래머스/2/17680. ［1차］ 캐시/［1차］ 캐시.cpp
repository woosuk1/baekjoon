#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <map>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    map<string, int> mp;
    vector<string> arr(cities.size());
    
    if(!cacheSize){
        answer += cities.size() * 5;
        return answer;
    }
    
    for(int i=0; i<cities.size(); i++){
        for(int j=0; j<cities[i].size(); j++){
            cities[i][j] = tolower(cities[i][j]);
        }
        
        if(mp.size() < cacheSize){
            if(mp[cities[i]] > 0){
                mp.erase(cities[i]);
                mp.insert({cities[i], i+1});
                answer += 1;
            }
            else{
                mp.erase(cities[i]);
                arr[i] = cities[i];
                mp.insert({cities[i], i+1});
                answer += 5;
            }
            continue;
        }
                
        if(mp[cities[i]] > 0){
            mp.erase(cities[i]);
            mp.insert({cities[i], i+1});
            answer += 1;
        }else{
            mp.erase(cities[i]); 
            // 살아있는 애들 중, 가장 이른 애들
            // mp.erase(arr[i-cacheSize]);
            string min_key; 
            int min_val= 100001;
            for(auto m: mp){
                if(min_val > m.second){
                    min_val = m.second;
                    min_key = m.first;
                }
            }
            mp.erase(min_key);
            mp.insert({cities[i], i+1});
            answer += 5;
        }
        arr[i] = cities[i];
    }
    
    return answer;
}