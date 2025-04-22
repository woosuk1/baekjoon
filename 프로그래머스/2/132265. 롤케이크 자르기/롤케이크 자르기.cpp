#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int,int> mp;
    map<int,int> mp2;
    
    for(int i=0; i<topping.size(); i++){
        // 토핑 개수 세기 위해서
        mp[topping[i]]++;
    }
     
    for(int i=0; i<topping.size(); i++){
        if(mp2.size() > mp.size())
            break;
        mp2[topping[i]]++;
        mp[topping[i]]--;
        if(mp[topping[i]] <= 0)
            mp.erase(topping[i]);
        
        // cout << "i: " << i;
        // cout << " mp.size(): " << mp.size() << ' ';
        // cout << "mp2.size(): " << mp2.size() << '\n';
        
        if(mp.size() == mp2.size())
            answer++;
    }
    
    return answer;
}