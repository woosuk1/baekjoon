#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <math.h>
#include <stack>
#include <deque>

using namespace std;

int cnt;

bool canPlaceSlope(int i, int start, int direction, int l, vector<vector<int> > &arr, vector<vector<bool> > &visited) {
    int height = arr[i][start];
    for (int k = 0; k < l; k++) {
        int next = start + k * direction;
        if (next < 0 || next >= arr.size()) return false; // 범위 초과
        if (arr[i][next] != height) return false; // 높이가 다름
        if (visited[i][next]) return false; // 이미 방문됨
    }
    for (int k = 0; k < l; k++) {
        visited[i][start + k * direction] = true; // 경사로 설치
    }
    return true;
}

bool canPlaceSlope2(int i, int start, int direction, int l, vector<vector<int> > &arr, vector<vector<bool> > &visited) {
    int height = arr[start][i];
    for (int k = 0; k < l; k++) {
        int next = start + k * direction;
        if (next < 0 || next >= arr.size()) return false; // 범위 초과
        if (arr[next][i] != height) return false; // 높이가 다름
        if (visited[next][i]) return false; // 이미 방문됨
    }
    for (int k = 0; k < l; k++) {
        visited[start + k * direction][i] = true; // 경사로 설치
    }
    return true;
}

void checkRows(int n, int l, vector<vector<int> > &arr, vector<vector<bool> > &visited) {
    for (int i = 0; i < n; i++) {
        bool valid = true;
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] == arr[i][j + 1]) continue; // 높이 동일
            if (abs(arr[i][j] - arr[i][j + 1]) > 1) {
                // 높이 차이 1 초과
                valid = false;
                break;
            }
            if (arr[i][j] > arr[i][j + 1]) {
                // 내리막길
                if (!canPlaceSlope(i, j + 1, 1, l, arr, visited)) {
                    valid = false;
                    break;
                }
            } else {
                // 오르막길
                if (!canPlaceSlope(i, j - l + 1, 1, l, arr, visited)) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            cnt++;
        }
    }
}

void checkCols(int n, int l, vector<vector<int> > &arr, vector<vector<bool> > &visited) {
    for (int i = 0; i < n; i++) {
        bool valid = true;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j][i] == arr[j + 1][i]) continue; // 높이 동일
            if (abs(arr[j][i] - arr[j + 1][i]) > 1) {
                // 높이 차이 1 초과
                valid = false;
                break;
            }
            if (arr[j][i] > arr[j + 1][i]) {
                // 내리막길
                if (j + l >= n || !canPlaceSlope2(i, j + 1, 1, l, arr, visited)) {
                    valid = false;
                    break;
                }
            } else {
                // 오르막길
                if (j - l + 1 < 0 || !canPlaceSlope2(i, j - l + 1, 1, l, arr, visited)) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l;

    cin >> n >> l;

    vector<vector<int> > arr(n, vector<int>(n));
    vector<vector<bool> > visited(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    checkRows(n, l, arr, visited);

    vector<vector<bool> > visited2(n, vector<bool>(n));

    checkCols(n, l, arr, visited2);

    cout << cnt;

    return 0;
}
