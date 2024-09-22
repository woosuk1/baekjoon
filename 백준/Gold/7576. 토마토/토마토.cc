#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

struct tomato {
    int y, x;
};

queue<tomato> q;

//index 0은 사용하지 않음으로 배열을 하나 추가
int map[1001][1001];

int M, N, cnt = 0;


//int dir[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1} }; //상하좌우대각 이동
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

void bfs(void) {
    while (!q.empty()) {

        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dirY[i], nx = x + dirX[i];
            if (ny < N && nx < M && ny >= 0 && nx >= 0) {
                if (map[ny][nx] == 0) {
                    map[ny][nx] = map[y][x] + 1;
                    q.push({ ny, nx });
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &M, &N); //가로, 세로 길이 입력
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
                q.push({ i,j });
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                printf("-1");
                return 0;
            }
            if(cnt < map[i][j])
                cnt = map[i][j];
        }
    }

    printf("%d", cnt - 1);
    //memset(visited, 0, sizeof(visited));
    
    /*
    sort(graph.begin(), graph.end());

    for (int i = 0; i < graph.size(); i++) {
        printf("%d\n", graph[i]);
    }
    */
    return 0;
}