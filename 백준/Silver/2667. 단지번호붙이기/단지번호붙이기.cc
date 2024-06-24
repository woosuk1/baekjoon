#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

//index 0은 사용하지 않음으로 배열을 하나 추가
bool visited[26][26];
int map[26][26];
vector<int> graph;

int a, cnt = 0;

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //상화좌우 이동

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx >= 0 && ny >= 0 && nx <= a && ny <= a) {
            if (visited[nx][ny] == false && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                cnt++;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            scanf("%1d",&map[i][j]);
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (visited[i][j] == false && map[i][j] == 1) {
                visited[i][j] = true;
                cnt++;
                dfs(i, j);
                graph.push_back(cnt); //단지개수 push
                cnt = 0;
            }
        }
    }

    printf("%d\n", graph.size());

    sort(graph.begin(), graph.end());

    for (int i = 0; i < graph.size(); i++) {
        printf("%d\n", graph[i]);
    }

}