// 회의실 배정
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, int>> A(n);

  for (int i = 0; i < n; i++)
  {                     // 종료 시간이 우선순위가 높음(정렬할 때)
    cin >> A[i].second; // 첫 번째 값으로 종료시간을 받고
    cin >> A[i].first;  // 두 번째 값으로 시작시간을 받는다.
  }

  sort(A.begin(), A.end()); // 정렬 완료

   int cnt = 0;
  int end = -1; // 음수로 두는 이유: 0보다 작은 것으로 세팅하기 위해....(현재 회의의 종료 시간)

  for (int i = 0; i < n; i++)
  {
    if (A[i].second >= end)
    { // 겹치지 않으면
      end = A[i].first;
      cnt++;
    }
  }

  cout << cnt << "\n";
}