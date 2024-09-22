#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>

using namespace std;

struct tomato {
	int z, y, x;
};

queue<tomato> q;

int mp[101][101][101]; //면부터 

int M, N, H , cnt = 0;

int dirX[6] = { 0, 0, 1, -1, 0, 0 };
int dirY[6] = { 1, -1, 0, 0 , 0, 0};
int dirZ[6] = { 0, 0, 0, 0, 1, -1 };

void bfs() {
	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
        int z = q.front().z;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int ny = y + dirY[i], nx = x + dirX[i], nz = z + dirZ[i];
			if (ny < N && nx < M && nz < H && ny >= 0 && nx >= 0 && nz >= 0) {
				if (mp[nz][ny][nx] == 0) {
					mp[nz][ny][nx] = mp[z][y][x] + 1;
					q.push({nz, ny, nx });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mp[h][i][j];
                if (mp[h][i][j] == 1)
                    q.push({ h,i,j });
            }
        }
    }

    bfs();

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mp[h][i][j] == 0) {
                    cout << "-1";
                    return 0;
                }
                if (cnt < mp[h][i][j])
                    cnt = mp[h][i][j];
            }
        }
    }

    cout << cnt - 1;

    return 0;
}
