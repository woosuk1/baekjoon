#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<string>> check;
// 가변적으로 사이즈 생성
vector<vector<string>> save;
// visited
map<string, bool> mp;

void dfs(int index, vector<string>& current){
    if(index == save.size()){
        check.push_back(current);
        return;
    }
    
    for(int i=0; i<save[index].size(); i++){
        // 방문한적이 없으면
        if(!mp[save[index][i]]){
            current.push_back(save[index][i]);
            mp[save[index][i]] = true;

            dfs(index+1, current);
            // 원상태 복귀
            current.pop_back();
            mp[save[index][i]] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    save.resize(banned_id.size());
    
    //map에 저장하기 위한 배열
    for(int i=0; i<user_id.size(); i++){
        mp.insert({user_id[i], false});
    }
    
    for(int i=0; i<banned_id.size(); i++){
        for(int j=0; j<user_id.size(); j++){
            bool flag = true;

            // 유저 아이디와 불량 아이디 사이즈가 같지 않을 때
            if(user_id[j].size() != banned_id[i].size()){
                continue;
            }
            //사이즈가 같을 때 banned_id, user_id 원소 값 비교
            for(int k=0; k<user_id.size(); k++){
                if(banned_id[i][k] == '*')
                    continue;
                if(banned_id[i][k] != user_id[j][k]){
                    flag = false;
                }
            }            
            // flag가 true일 때(조건 다 만족) banned_id[index]의 index에 user_id 추가
            if(flag == true)
                save[i].push_back(user_id[j]);
        }
    }
    
    vector<string> current;
    dfs(0, current);    
    
    // 직접 비교하려다 참은 것
    for(int i=0; i<check.size(); i++){
        sort(check[i].begin(), check[i].end());
    }
    
    bool visited[check.size()];
    
    memset(visited, false, sizeof(visited));
    
    for(int i=0; i<check.size(); i++){
        if(visited[i])
            continue;
        for(int j=i+1; j<check.size(); j++){
            if(visited[j])            
                continue;
            // 같은 경우
            if(equal(check[i].begin(), check[i].end(), check[j].begin())){
                visited[j] = true;                     
            }    
        }
    }
    
    for(int i=0; i<check.size(); i++){
        if(!visited[i])
            answer++;
    }
    
    return answer;
}