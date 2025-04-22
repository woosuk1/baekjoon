#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    stack<pair<int,int>> stk;
        
    for(int i=0; i<numbers.size(); i++){
        
        // 반복 조건(numbers[i]가 stk.top().first보다 작을 때
        while(!stk.empty() && numbers[i] > stk.top().first){
        // 1. while(numbers 원소가 stk.top()보다 크면) stk.pop(), answer[stk.top().second] = numbers[i]
            answer[stk.top().second] = numbers[i];
            stk.pop();
        }
        
        stk.push({numbers[i], i});
    }
    
    while(!stk.empty()){
        answer[stk.top().second] = -1;
        stk.pop();
    }
    
    return answer;
}