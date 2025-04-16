#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0, p = 0; // 현재 위치(i번째 집 이후)에서 처리해야 할 누적 배달과 수거 상자 수

    // 집은 가장 멀리 있는 집부터 검사 (뒤에서부터 이동)
    for (int i = n - 1; i >= 0; i--) {
        // 현재 집의 배달 및 수거 수량을 누적합니다.
        d += deliveries[i];
        p += pickups[i];

        // 현재 구간에 처리할 배달 혹은 수거 상자가 있다면
        while (d > 0 || p > 0) { 
            // 한 번 왕복으로 최대 cap만큼 처리할 수 있으므로
            d -= cap; // 배달 상자에서 cap만큼 처리
            p -= cap; // 수거 상자에서도 cap만큼 처리
            // 트럭이 이 집(i번째 집, 실제 거리 i+1)를 기준으로 왕복하였으므로 이동 거리 추가
            answer += (i + 1) * 2; // i는 0-indexed이므로 거리 = i+1, 왕복이므로 곱하기 2
        }
    }
    return answer;
}