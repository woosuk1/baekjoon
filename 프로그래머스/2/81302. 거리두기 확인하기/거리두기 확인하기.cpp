#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
char each[5][5];
int visited[5][5];

// 거리두기를 위하여 응시자들 끼리는 맨해튼 거리1가 2 이하로 앉지 말아 주세요.
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int l=0; l<5; l++){
    // for(int l=0; l<1; l++){
        // visitied 배열 초기화
        // fill(&visited[0][0], &visited[4][5], 0);
        
        bool flag = true;
        
        for(int i =0; i<5; i++){
            for(int j=0; j<5; j++){
                // 할당
                each[i][j] = places[l][i][j];
            }
        }
        
        
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                fill(&visited[0][0], &visited[4][5], 0);        
                queue<pair<int,int>> q;
                if(each[i][j] == 'P'){
                    q.push({i,j});
                    visited[i][j] = 1;
                    
                    while(!q.empty()){
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();
                        
                        for(int k=0; k<4; k++){
                            int ny = y + dy[k];
                            int nx = x + dx[k];
                            
                            if(ny < 0 || nx < 0 || ny > 4 || nx > 4) continue;
                            if(abs(ny-i) + abs(nx-j) > 2){
                                continue;  
                            } 
                            // 파티션이 있거나, 방문했었으면
                            if(each[ny][nx] == 'X' || visited[ny][nx]) continue;                            
                            // 사람을 만났을 때
                            if(each[ny][nx] == 'P'){
                                flag = false;
                                break;
                            }
                            // 빈 테이블을 만났을 때
                            q.push({ny,nx});
                            visited[ny][nx] = 1;
                            // cout << "value: " << abs(ny-i) << ' ' << abs(nx- j) << '\n';
                            // cout << "y: " << i << " x: " << j <<  " ny: " << ny << " nx: " << nx << '\n';
                        }
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(flag) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}