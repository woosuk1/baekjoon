#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_val = -1;

// 최종점수 계산 함수
void cal(vector<int> &apeach, vector<int> &rian, vector<int> &answer) {
    int rian_val = 0;
    int apeach_val = 0;

    for (int i = 0; i < apeach.size(); i++) {
        // 둘다 0일 때
        if (!apeach[i] && !rian[i])
            continue;
        if (apeach[i] >= rian[i])
            apeach_val += 10 - i;
        else
            rian_val += 10 - i;
    }

    int diff = rian_val - apeach_val;
    if (diff > 0) {
        if (diff > max_val) {
            max_val = diff;
            answer = rian;
        }
        // 점수차가 같으면 낮은 점수를 더 많이 맞힌 쪽이 이긴다고 했으므로 비교 필요
        else if (diff == max_val) {
            // 뒤에서부터 비교 (낮은 점수 우선)
            for (int i = apeach.size() - 1; i >= 0; i--) {
                if (rian[i] > answer[i]) {
                    answer = rian;
                    break;
                } else if (rian[i] < answer[i]) {
                    break;
                }
            }
        }
    }
    
}

// 라이언의 경우의 수 백트래킹
void backtrack(int n, int idx, int remain, vector<int> &answer, vector<int> &rian, vector<int> &apeach) {
    // base point
    if (idx == 11) {
        if (remain > 0) rian[10] += remain;
        cal(apeach, rian, answer);
        return;
    }

    vector<int> origin = rian;

    for (int i = 0; i <= remain; i++) {
        rian[idx] += i;
        backtrack(n, idx + 1, remain - i, answer, rian, apeach);
        rian = origin;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(info.size());
    vector<int> rian(info.size());    
    backtrack(n,0,n,answer, rian, info);
    
    // max_val이 한번도 바뀌지 않았을 때
    if(max_val == -1){
        answer = {-1};
    }
    
    return answer;
}