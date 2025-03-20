#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 인덱스에 맞게 ++ 해주면 될 듯하다.
    vector<int> answer(id_list.size());
    map<string, std::set<std::string>> mp;
    
    // 한 번에 한 명의 유저를 신고할 수 있음
    // 한 명은 여러명을 신고할 수 있고, 동일한 유저에 대한 신고횟수는 1
    
    // k번 이상 신고된 유저는 게시판 이용이 정지됨.
    // 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송 -> 역 인덱스?
    // 마지막에 한꺼번에 게시판 이용 정지를 시킴
    
    // map에 id_list 매핑
    map<string, int> id;
    
    for(int i=0; i<id_list.size(); i++){
        id.insert({id_list[i], i});
    }
    
    // 1. "muzi frodo"에서 map으로 매핑 frodo 키에 value는 set.insert
    for(int i=0; i<report.size(); i++){
        string temp1;
        string temp2;
        int idx;
        for(int j=0; j<report[i].size(); j++){
            if(report[i][j] == ' '){
                idx = j+1;
                break;
            }
            temp1 += report[i][j];
        }
        
        for(int j=idx; j<report[i].size(); j++){
            temp2 += report[i][j];
        }
        // 중복으로 들어가지 않도록 set으로 넣어줌
        mp[temp2].insert(temp1);
    }
    // 2. frodo 가 해당되니까 frodo key의  muzi, apeach에 발송한다.
    // 3. {muzi, 0 }로 해서 answer[mp["muzi"]]++; 처럼 하면 될듯? 
    for(auto m: mp){
        if(m.second.size() >= k){
            for(auto s:m.second){
                answer[id[s]]++;
            }
        }
    }
    return answer;
}