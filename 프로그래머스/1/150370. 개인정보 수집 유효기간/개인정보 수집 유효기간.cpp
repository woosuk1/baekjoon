#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // today는 "YYYY.MM.DD" 형태로 오늘 날짜로 파싱하기
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,7));
    int todayDay = stoi(today.substr(8,10));
    // terms는 ["A 6"]
    
    map<char, int> mp;
    
    for(int i=0; i<terms.size(); i++){
        // 약관 종류, 유효기간 파싱
        mp.insert({terms[i][0], stoi(terms[i].substr(2,terms[i].size()))});
    }
    
    // privacies ["2021.05.02 A"]
    for(int i=0; i<privacies.size(); i++){
        int tempYear = stoi(privacies[i].substr(0,4));
        int tempMonth = stoi(privacies[i].substr(5,7));
        int tempDay = stoi(privacies[i].substr(8,10));
        
        int validMonth = mp[privacies[i][privacies[i].size()-1]];
        
        bool flag1 = false;
        bool flag2 = false;
        
        // 유효기간 맞추기
        // 계약날짜 day가 1인 경우 month -1, day = 28
        // 이때 month == 0 이면 month = 12, year -= 1
        if(tempDay == 1){
            tempMonth -= 1;
            tempDay = 28;
            if(tempMonth == 0){
                tempMonth = 12;
                tempYear -= 1;
            }
        }else{
            tempDay -=1;
        }      
        // 현재 날짜 - privacies(계약 날짜) - 1 - 유효달기간 > 0
        // year의 수만큼 *12해서 달에 추가.
        int saveYear = todayYear - tempYear;
        int saveMonth = (todayYear - tempYear) * 12; 
        
        if(todayYear - tempYear > 0){
            todayMonth += (todayYear - tempYear) * 12;   
            todayYear -= (todayYear - tempYear);
            flag1 = true;
        }
        
        if(tempDay - todayDay < 0){
            todayDay += 30;
            todayMonth += 1; 
            flag2 = true;
        }
                            
        if(todayMonth - tempMonth - validMonth > 0){
            answer.push_back(i+1);
        }        
        if(flag1){
            todayYear += saveYear;
            todayMonth -=saveMonth;
        }
        if(flag2){
            todayDay -= 30;
            todayMonth -= 1;
        }
    }
    
    return answer;
}