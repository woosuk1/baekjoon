#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // input
    // 1. 2 ≤ friends의 길이 = 친구들의 수 ≤ 50(소문자로 이루어지고, 중복 x)
    // 2. 1 ≤ gifts의 길이 ≤ 10,000 | "A B" 같은 이름인 경우는 없다.
    
    // 이번 달까지 선물을 주고 받은 기록을 바탕으로 다음 달에 누가 선물을 많이 받을지 예측
    // 기록 하기 위해서,, map<string, vector<pair<string, int>>> mp 선언
    map<string, map<string, int>> mp;
    map<string, int> currentGiver;
    map<string, int> save;
    
    for(int i=0; i<friends.size(); i++){
        save[friends[i]] = 0;
        for(int j=0; j<friends.size(); j++){
            if(i !=j){
                mp[friends[i]][friends[j]] = 0;
            }
        }
    }
    
    for(int i=0; i<gifts.size(); i++){
        string giver = "";
        string receiver = "";
        bool flag = false;
        for(int j=0; j<gifts[i].size(); j++){
            if(gifts[i][j] == ' '){
                flag = true;
                continue;
            }
            if(!flag){
                giver += gifts[i][j];
            }else{
                receiver += gifts[i][j];
            }
        }
        mp[giver][receiver]++;
        // 수 저장하기
        // 선물 지수란 이번 달까지 자신이 친구들에게 준 선물의 수 - 받은 선물의 수
        // frodo -> neo 
        currentGiver[giver]++;
        currentGiver[receiver]--;
    }

    // 두 사람이 선물을 주고 받은 기록이 있다면,
    // 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받는다.
    
    // 두 사람이 선물을 주고받은 기록이 없거나, 주고받은 수가 같다면,
    // 선물 지수가 더 큰 사람이 작은 사람에게 선물을 하나 받는다.
    // if(두 사람의 선물 지수 equal) 선물 주고 받기 x (continue?)
    // -> 선물 지수란 이번 달까지 자신이 친구들에게 준 선물의 수 - 받은 선물의 수
    for(auto m: mp){
        // 내부 루프 돌기
        for(auto sec : m.second){
            // 주고 받았던 적이 있을 때  
            if(sec.second > mp[sec.first][m.first]){
                save[m.first]++;
            }else if(sec.second < mp[sec.first][m.first]){
                save[sec.first]++;
            } 
            // 선물을 주고 받은 수가 같을 때
            else{
                if(currentGiver[m.first] > currentGiver[sec.first]){
                    save[m.first]++;
                }
                else if(currentGiver[m.first] < currentGiver[sec.first]){
                    save[sec.first]++;
                }
            }
            
        }
    }
    // 선물을 가장 많이 받을 친구가 받을 선물의 수 
    for(auto s: save){
        answer = max(answer, s.second / 2) ;
    }
    return answer;
}