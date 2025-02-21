#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int i =0;
    
    while(1){
        if(answer.size() == number.size() - k)
            break;
        
        pair<char,int> temp_max; // 값과 인덱스 저장용
        for(;i<number.size(); i++){
            
            // 검증 할 게 아닌 것이 break;
            if(number.size() - i < (number.size() - k) - answer.size()){
                break;                
            }
            else if(number[i] == '9'){
                temp_max = make_pair(number[i], i);
                break;
            }
            
            if(temp_max.first < number[i]){
                temp_max = make_pair(number[i], i);
            }            
        }
        // 인덱스 지정        
        i= temp_max.second + 1;
        // 문자열 추가
        answer += temp_max.first;
    }
    
    return answer;
}