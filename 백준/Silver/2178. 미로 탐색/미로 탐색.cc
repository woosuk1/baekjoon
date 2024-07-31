#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

struct tomato {
    int x, y;
};

//queue<tomato> q;


// queue<int> q;

//index 0은 사용하지 않음으로 배열을 하나 추가
int map[101][101] = { 0, };
bool visited[101][101];
int dist[101][101] = { 0, };
int M, N, cnt = 1;

//int dir[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1} }; //상하좌우대각 이동
int dirX[4] = {0, 0, 1, -1}; //상하좌우
int dirY[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
    queue<tomato> q;
    q.push({ x,y });
    visited[x][y] = true;

    dist[x][y]++;
    
    while (!q.empty()) {

        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
//        int temp = 0;
        for (int i = 0; i < 4; i++) {

            int ny = y + dirY[i], nx = x + dirX[i];

            if (ny < N && nx < M && ny >= 0 && nx >= 0 && !visited[nx][ny] && map[nx][ny] == 1) {
          
//                    map[ny][nx] = map[y][x] + 1; //개수 증가는 의미 없음
                  //  temp++;
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                  //  if (temp == 1)
                    //    cnt++;
                
            }
        }
    }
}

int main() {

    scanf("%d %d", &M, &N); //가로, 세로 길이 입력
    

    for (int i = 0; i <M; i++) {
        for (int j = 0; j <N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    

    bfs(0,0);

    printf("%d", dist[M-1][N-1]);

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                printf("-1");
                return 0;
            }
        }
    }

    //memset(visited, 0, sizeof(visited));
    

    sort(graph.begin(), graph.end());

    for (int i = 0; i < graph.size(); i++) {
        printf("%d\n", graph[i]);
    }
    */
    return 0;
}