#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    // 같은 키 값을 가졌을 때, value값 순서대로 정렬
    map<pair<string,int>, vector<string>> mp;
    
    for(int i=0; i<files.size(); i++){
        int index = 0;
        // 이때, 문자열 비교 시 대소문자 구분을 하지 않는다. MUZI와 muzi, MuZi는 정렬 시에 같은 순서로 취급된다.
        string temp = "";
        for(;;index++){
            // 숫자를 만났을 시 index-- 하고 종료
            if(files[i][index] >= '0' && files[i][index] <= '9'){
                break;
            }
            temp+= files[i][index];            
        }
        string temptemp = "";        
        // 대소문자 소문자로 변환
        for(int j=0; j<temp.size(); j++){
            temptemp += tolower(temp[j]);
        }
    
        // NUMBER는 한 글자에서 최대 다섯 글자 사이의 연속된 숫자로 이루어져 있으며, 앞쪽에 0이 올 수 있다. 0부터 99999 사이의 숫자로, 00000이나 0101 등도 가능하다.        
        string temp_number ="";
        
        for(;;index++){
            if(!isdigit(files[i][index]))
                break;
            temp_number += files[i][index];
        }
                
        int temptemp_number;
        temptemp_number = stoi(temp_number);
        
        mp[{temptemp,temptemp_number}].push_back(files[i]);
    }    
    
    for(auto m: mp){
        for(auto a: m.second){
            answer.push_back(a);
        }
    }
    
    // 출력시, key값에 따른 배열의 사이즈 대로 answer에 push
    
    return answer;
}