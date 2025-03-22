#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int>> visited(m, vector<int> (n));
    queue<pair<int, int>> q;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j] && !visited[i][j]){
                number_of_area++;
                int temp_area = 1;
                int save = picture[i][j];
                q.push({i,j});
                visited[i][j] = 1;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    
                    for(int l=0; l<4; l++){
                        int ny = y + dy[l];
                        int nx = x + dx[l];
                        if(ny <0 || nx < 0 || ny >= m || nx >=n) continue;
                        if(visited[ny][nx] || picture[ny][nx] != save) continue;
                        
                        q.push({ny,nx});
                        visited[ny][nx] = 1;
                        temp_area++;
                    }
                }
                max_size_of_one_area = max(temp_area, max_size_of_one_area);
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}