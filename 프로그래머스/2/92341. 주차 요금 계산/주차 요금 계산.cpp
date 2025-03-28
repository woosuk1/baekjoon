#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // 요금표와 입차 출차 기록이 주어졌을 때, 차량 별 주차 요금을 계산하려 함
    
    // 어떤 차량이 입차된 후에 출차된 내역이 없다면 23:59에 출차된 것으로 간주
    // 차량별 누적 주차 시간을 계산 (map을 이용하고 싶다는 생각)
    
    // 차량 번호가 작은 자동차부터 return (map 쓰라는 거지)
    
    // input.
    // records의 각 원소 "시각 차량번호 내역", ex) "05:34 5961 IN" IN,OUT
    // 시각을 기준으로 오름차순으로 정렬되어 주어짐.
    
    // 차량번호, 입차시각(int형으로) 저장용 -> 출차시각이 들어왔을 때 [출차시간-입차시각], mp.erase(key)
    map<string, int> mp;
    // 시간 저장 map
    map<string, int> save;
    
    for(int i=0; i<records.size(); i++){
        // 시각을 분으로 바꾸는로직
        int minutes = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2));
        string car_num = records[i].substr(6,4);
        // 입차일 때 
        if(records[i].substr(11,2) == "IN"){
            mp.insert({car_num, minutes});            
        }
        // 출차일 때
        else{
            int inMinutes = mp[car_num];
            minutes -= inMinutes;
            save[car_num] += minutes;
            mp.erase(car_num);
        }
    }
    
    // mp에 있는 마지막값들 다 flush해주기 for -> (1439 - int)
    for(auto m :mp){
        int notyet = 1439;
        notyet -= m.second;
        save[m.first] += notyet;
    }
    
    
    // fees를 통해 금액 계산해서 순차적으로 answer.push_back
    // 누적 주차 시간이 기본 시간 이하라면, 기본 요금
    // 초과한 시간이 단위 시간으로 떨어지지 않으면, 올림한다.(/에 %를 해서 0이 아니면 +1)
    for(auto s: save){
        if(s.second <= fees[0]){
            answer.push_back(fees[1]);
        }else{
            if((s.second - fees[0]) % fees[2] != 0 ){
                answer.push_back(fees[1]+((s.second - fees[0]) / fees[2]+1) * fees[3]);
            }else{
                answer.push_back(fees[1]+((s.second - fees[0]) / fees[2] * fees[3]));
            }
        }
    }
    
    return answer;
}