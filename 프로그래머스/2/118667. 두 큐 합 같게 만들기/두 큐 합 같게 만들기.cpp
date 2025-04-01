#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    // int answer = -2;
    int answer = 0;
    long long target = 0;
    long long sum1 = 0;
    long long sum2 = 0;

    deque<int> deque1(queue1.begin(), queue1.end());
    deque<int> deque2(queue2.begin(), queue2.end());
    // 길이가 같은 두 개의 큐에서 하나의 큐를 골라 pop, 다른 큐에 insert 작업을 통해 각 큐의 원소 합이 같도록 함.
    // 한번의 pop, insert를 작업을 1회 수행한 것으로 간주
    
    // 이 문제에서는 큐를 배열로 표현하며, 배열 앞쪽에 있을수록 먼저 집어넣은 원소임을 의미
    
    // 1. 두 큐의 원소들의 합을 구한다. 합을 더해 /2 를 하여 타겟을 구한다.

    // 2. 두 수 중에 값이 target보다 낮으면 그 쪽으로 pop, insert를 함
    // 몇 이상이어야지 모든 경우의 수를 다 해보는 걸까?
    for(int i=0; i<queue1.size(); i++){
        target += queue1[i];
        sum1 += queue1[i];
    }
    
    for(int i=0; i<queue2.size(); i++){
        target += queue2[i];
        sum2 += queue2[i];
    }
    
    if(target % 2 != 0 )
        return -1;

    target /= 2;
    
    while(true){
        
        if(target == sum1)
            break;
        if(answer > (deque1.size() + deque2.size())+1){
            return -1;    
        }
        
        // sum1이 더 작을 때
        if(sum1 < sum2){
            deque1.push_back(deque2.front());
            sum1 += deque2.front();
            sum2 -= deque2.front();
            deque2.pop_front();
        }
        else{
            deque2.push_back(deque1.front());
            sum1 -= deque1.front();
            sum2 += deque1.front();
            deque1.pop_front();
        }

        answer++;
    }
    
    
    return answer;
}