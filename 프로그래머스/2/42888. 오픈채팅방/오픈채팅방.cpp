#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> save_id; 
    vector<pair<string,string>> cm;
    for(int i=0; i<record.size(); i++){
        string cmd = "";
        string id = "";
        string nick = "";
        int cnt = 0;       
        // parsing 먼저
        for(int j=0; j<record[i].size(); j++){   
            if(record[i][j] == ' '){
                cnt++;
                continue;
            }
            if(!cnt){
                cmd += record[i][j];
            }
            if(cnt == 1){
                id += record[i][j];
            }
            if(cnt == 2){
                nick += record[i][j];
            }
        }
        // map으로 아이디와 닉네임 추적
        if(cnt == 2){
            save_id[id] = nick;
        }

        // vector<pair<string, string>> 으로 uid, command 등록
        cm.push_back({id,cmd});
    }
    
    for(int i=0; i<cm.size(); i++){
        if(cm[i].second == "Change")
            continue;
        string temp = "";
        temp += save_id[cm[i].first] + "님이 ";
        
        if(cm[i].second == "Enter"){
            temp += "들어왔습니다.";
        }else{
            temp += "나갔습니다.";
        }
        answer.push_back(temp);
    }
    
    return answer;
}