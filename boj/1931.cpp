#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 백준 1931번 "회의실 배정"

int n;
pair<pair<int, int>, int> jobs[100000]; // end time, start time, index

void solve()
{
	int cnt = 0; // 선택한 회의 개수

	// 끝나는 시간을 기준으로 오름차순 정렬
	priority_queue <pair<pair<int, int>, int>,
					vector<pair<pair<int, int>, int>>,
					greater<pair<pair<int, int>, int>>> myq;

	// 회의들을 큐에 집어넣음
	for (int i = 0; i < n; i++) 
		myq.push(jobs[i]);

	int si, ei;
	int last_end_time = 0;

	while (!myq.empty()) {
		ei = myq.top().first.first;  // 현재 작업의 끝나는시간
		si = myq.top().first.second; // 현재 작업의 시작시간
		myq.pop();

		// 이전 작업의 끝나는 시간 이후 시작하는 작업만 선택
		if (si >= last_end_time) {
			cnt++; // 선택된 회의 총 개수 증가
			last_end_time = ei; // 마지막으로 끝나는 시간 갱신
		}
	}
	cout << cnt << endl; // 선택된 총 회의의 개수 출력
}	

int main()
{
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		jobs[i] = make_pair(make_pair(b, a), i + 1); // end, start, index
	}
	solve();
	return 0;
}