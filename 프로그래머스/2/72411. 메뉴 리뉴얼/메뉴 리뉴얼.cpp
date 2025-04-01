#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    map<pair<string,int>, int> mp;

    for(int i=0; i<orders.size(); i++){
        // 1. 각각의 원소에 대한 길이가 2 이상인 조합을 구한다. (나중엔 필요한 것만 조합구하도록 하기)
        for(int j=0; j<course.size(); j++){
            if(orders[i].size() < course[j])
                continue;
                        
            int length = orders[i].size();
            vector<int> temp_arr(length);
            // for(int k=j; k<orders[i].size(); k++){
            //     temp_arr[k] = 1;
            // }
            for(int k=course[j]; k<orders[i].size(); k++){
                temp_arr[k] = 1;
            }
            
            // 2. 그 조합을 map에 집어넣는다. map<pair<string, int>>, int>;
            // 2.1 map[{string, int}]++;
            do{
                string temp ="";
                for(int k=0; k<orders[i].size(); k++){
                    if(temp_arr[k] == 0)
                        temp += orders[i][k];                    
                }
                sort(temp.begin(), temp.end());
                mp[{temp, temp.size()}]++;
            }while(next_permutation(temp_arr.begin(), temp_arr.end()));

        
//         for(int j=2; j<=orders[i].size(); j++){
            
//             int length = orders[i].size();
//             vector<int> temp_arr(length);
//             for(int k=j; k<orders[i].size(); k++){
//                 temp_arr[k] = 1;
//             }
            
//             // 2. 그 조합을 map에 집어넣는다. map<pair<string, int>>, int>;
//             // 2.1 map[{string, int}]++;
//             do{
//                 string temp ="";
//                 for(int k=0; k<orders[i].size(); k++){
//                     if(temp_arr[k] == 0)
//                         temp += orders[i][k];                    
//                 }
//                 sort(temp.begin(), temp.end());
//                 mp[{temp, temp.size()}]++;
//             }while(next_permutation(temp_arr.begin(), temp_arr.end()));
        }
    }
    
    set<string> temp_arr;
    // 3. course[i] == m.first.second인 것을 찾는다. max가되고 바뀔 때까지 .
    for(int i=0; i<course.size(); i++){
        int temp_max = 0;
        vector<string> temp_answer;
        for(auto m:mp){
            if(m.first.second == course[i]){
                if(m.second > temp_max){
                    temp_max = m.second;
                    // 기존 배열 삭제
                    temp_answer.clear();
                }
                if(m.second == temp_max && m.second > 1){
                    temp_answer.push_back(m.first.first);
                }
            }
        }
        temp_arr.insert(temp_answer.begin(), temp_answer.end());
    }
    
    answer.insert(answer.begin(), temp_arr.begin(), temp_arr.end());
    
    return answer;
}