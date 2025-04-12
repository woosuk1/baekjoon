#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    // 자를 문자열 길이 (문자열 / 2 보다 큰 문자열은 없다.. )
    for (int i = 1; i <= s.size() / 2; i++) {
        int idx = 0;
        // 이전값
        string prev = s.substr(0, i);
        // 같은 값들 세기
        int cnt = 1;
        // 임시 완성 문자열
        string temp_answer = "";
        // idx가 s.size()보다 작을 때까지만 반복

        for (idx = i; idx < s.size(); idx += i) {
            string temp = s.substr(idx, i);
            if (temp == prev) {
                cnt++;
            } else {
                if (cnt > 1)
                    temp_answer += to_string(cnt);
                temp_answer += prev;
                prev = temp;
                cnt = 1;
            }
        }

        if (cnt > 1)
            temp_answer += to_string(cnt);
        temp_answer += prev;

        // answer 최소값인지 검증
        if (temp_answer.size() < answer) {
            answer = temp_answer.size();
        }
    }

    return answer;
}