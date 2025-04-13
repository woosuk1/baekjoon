#include <string>
#include <vector>

using namespace std;

int emo_size;
int member = 0;
int sales = 0;
int discnt[4] = {10,20,30,40};

// 들어갈 매개변수 : (emoticon 인덱스, 가입자수, 금액 합계, (유저별 금액, 가입여부)
void backtrack(int idx,vector<vector<int>> &users, vector<int> &emoticons,  vector<vector<int>> &record){
    if(idx == emo_size){
        int mem = 0;
        int price = 0;
        // 전체 한번 스캔 하기
        for(int j=0; j<users.size(); j++){
            if(record[j][0] >= users[j][1]){
                mem++;
            } else {
                price += record[j][0];
            }
        }
        // 전체 다 돌았고, mem, price값 최대 비교
        if(mem > member){
            member = mem;
            sales = price;
        }else if(mem == member){
            if(price > sales){
                sales = price;
            }
        }
        return;
    }
    
    // 일정 비율 이상 할인하는 이모티콘을 모두 구매합니다.
    // 이모티콘 구매 비용의 합이 일정 가격 이상이 된다면, 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입합니다.
        
    vector<vector<int>> origin = record;
    // 할인율 명시
    for(int i=0; i<4; i++){
        // 전체스캔하여, 구매하는지 여부를 측정
        for(int j=0; j<users.size(); j++){
            if(discnt[i] >= users[j][0]){
                record[j][0] += emoticons[idx] * (100 - discnt[i]) / 100;
            }
        }
        backtrack(idx+1, users, emoticons, record);
        record = origin;
    }
    
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    emo_size = emoticons.size();
    
    vector<vector<int>> record(users.size(), vector<int>(2,0));
    
    // 1. 플러스 가입자를 최대한 늘리는 것.
    // 2. 판매액을 최대한 늘리는 것.
    backtrack(0, users, emoticons, record);

    answer.push_back(member);
    answer.push_back(sales);
    
    return answer;
}