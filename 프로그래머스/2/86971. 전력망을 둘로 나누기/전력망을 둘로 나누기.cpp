#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[101];
int visited[101];
int ans = 101;
int cnt = 0;

void dfs(int idx){
    cnt++;
    visited[idx]++;
    
    for(int i=0; i< graph[idx].size(); i++){
        if(!visited[graph[idx][i]])
            dfs(graph[idx][i]);
    }
}

int solution(int n, vector<vector<int>> wires) {
    //wires 원소 하나씩 제외 완탐
    for(int i=0; i<wires.size(); i++){
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        for(int j=0; j<wires.size(); j++){
            if(i==j) //하나씩 끊기
                continue;
            else{ 
                graph[wires[j][0]].push_back(wires[j][1]);
                graph[wires[j][1]].push_back(wires[j][0]);
            }
        }
        //1부터만 세면 됨
        dfs(1);
        //abs(n - (n - cnt))
        ans = min(ans, abs(n - 2*cnt));
    }    
    
    
    return ans;
}