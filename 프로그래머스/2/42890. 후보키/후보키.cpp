#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    int numRows = relation.size();
    int numCols = relation[0].size();
    
    // 지금까지 발견한 후보키들을 문자열로 저장(예: "02"는 0번과 2번 컬럼으로 구성된 후보키)
    vector<string> candidateKeys;
    
    // 1부터 전체 컬럼 개수(numCols)까지 각 조합의 길이에 대해 검사
    for (int len = 1; len <= numCols; len++) {
        // mask 배열: 0은 선택, 1은 미선택. len개의 0과 (numCols-len)개의 1을 배치
        vector<int> mask(numCols, 0);
        for (int i = len; i < numCols; i++) {
            mask[i] = 1;
        }
        // mask는 이미 정렬된 상태 (0이 먼저 나오므로)
        
        do {
            // mask에 따라 선택된 컬럼 인덱스를 combi에 저장
            vector<int> combi;
            for (int i = 0; i < numCols; i++) {
                if (mask[i] == 0) { // 0이면 선택됨
                    combi.push_back(i);
                }
            }

            // [최소성 검사] 기존 후보키 중, 이미 저장된 후보키가 현재 조합(combi)의 부분집합이면 건너뛴다.
            // 현재 조합을 문자열로 변환 (예: 컬럼 0, 2, 5 -> "025")
            string curKey = "";
            for (int col : combi) {
                curKey += to_string(col);
            }
            bool isMinimal = true;
            for (const string &key : candidateKeys) {
                bool subset = true;
                // 이미 저장된 후보키의 각 숫자(컬럼 인덱스)가 curKey에 모두 있는지 확인
                for (char ch : key) {
                    if (curKey.find(ch) == string::npos) {
                        subset = false;
                        break;
                    }
                }
                if (subset) { // 기존 후보키가 부분집합이면 최소성을 위배
                    isMinimal = false;
                    break;
                }
            }
            if (!isMinimal)
                continue;
            
            // [유일성 검사] 각 튜플마다, combi에 해당하는 컬럼 값들을 이어붙여 집합에 저장하고, 중복이 발생하면 유일성이 깨진다.
            set<string> tuples;
            bool isUnique = true;
            for (int i = 0; i < numRows; i++) {
                string record = "";
                for (int idx : combi) {
                    record += relation[i][idx] + ",";
                }
                if (tuples.find(record) != tuples.end()) { // 중복 발견
                    isUnique = false;
                    break;
                }
                tuples.insert(record);
            }
            if (!isUnique)
                continue;
            
            // 유일성과 최소성을 모두 만족하면 후보키로 저장
            candidateKeys.push_back(curKey);
            
        } while (next_permutation(mask.begin(), mask.end()));
    }
    
    return candidateKeys.size();
}
