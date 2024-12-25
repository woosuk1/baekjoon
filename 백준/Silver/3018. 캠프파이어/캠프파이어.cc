#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <deque>
#include <climits>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <sstream>

using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {

	init();

    // n은 사람의 수, e는 mt 기간
    int n, e;
    cin >> n >> e;

    // 저장할 노래의 최대 갯수
    vector<int> save[51];

    // 각 번호가 가지고 있는 노래 목록
    vector<int> mem[101];

    // 새로운 요소 인덱스 저장용
    int count = 1;

    for (int l = 0; l < e; l++) {
        int num;
        cin >> num;

        vector<int> tmp_arr(num);
        bool hasSunyoung = false;

        for (int i = 0; i < num; i++) {
            cin >> tmp_arr[i];
            if (tmp_arr[i] == 1)
                hasSunyoung = true;
        }

        if (hasSunyoung) {
            for (int person : tmp_arr) {
                save[count].push_back(person);
                mem[person].push_back(count);
            }
            count++;
        }
        else {
            set<int> sharedSongs;

            for (int person : tmp_arr) {
                for (int song : mem[person]) {
                    sharedSongs.insert(song);
                }
            }

            for (int person : tmp_arr) {
                for (int song : sharedSongs) {
                    mem[person].push_back(song);
                }
            }
        }
    }

    // 각 mem 배열에서 중복 제거
    for (int i = 1; i <= n; i++) {
        sort(mem[i].begin(), mem[i].end());
        mem[i].erase(unique(mem[i].begin(), mem[i].end()), mem[i].end());
    }

    // 모든 노래를 아는 사람 찾기
    set<int> allSongs;
    for (int i = 1; i < count; i++) {
        allSongs.insert(i);
    }

    vector<int> allKnownPeople;
    for (int i = 1; i <= n; i++) {
        set<int> personSongs(mem[i].begin(), mem[i].end());
        if (includes(personSongs.begin(), personSongs.end(), allSongs.begin(), allSongs.end())) {
            allKnownPeople.push_back(i);
        }
    }

    // 오름차순 출력
    sort(allKnownPeople.begin(), allKnownPeople.end());
    for (int person : allKnownPeople) {
        cout << person << "\n";
    }
    cout << "\n";

    return 0;
}