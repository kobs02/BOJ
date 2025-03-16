#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
long tower;
stack <pair<long, int>> s; // 스택
vector <long> v;           // 타워 높이가 저장된 벡터(비교용)
vector <int> sol;

#if 0
void solve1() // 이중 for문으로 인한 시간초과. (O(n^2))
{
	int chk;
	sol.push_back(0);
	for (int i = 1; i < n; i++) { // 2번째 타워부터 마지막 타워까지 반복
		chk = 0; // 체크 플래그
		for (int j = 1; j <= i; j++) { // 선택한 타워에서 첫 번째 타워까지 탐색
			if (v[i] <= v[i - j]) {  // 앞 타워가 현재 타워보다 큰 경우
				sol.push_back(i-j+1);    // 앞 타워 순서를 sol에 저장
				chk = 1;
				break;
			}
		}
		if (chk == 0)
			sol.push_back(0);
	}
	for (int i = 0; i < n; i++)
		cout << sol[i] << " ";
}
#endif

void solve2()
{
	sol.resize(n); // 

	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first < v[i]) // i+1번째 타워(현재 타워)보다 낮은 타워 제거
			s.pop();

		if (!s.empty()) // 현재 타워보다 낮은 타워를 다 지웠는데 남아있는 타워가 있는 경우
			sol[i] = s.top().second; // 앞 타워에게 수신 가능
		else
			sol[i] = 0;
		s.push(make_pair(v[i], i + 1));
	}
	for (int i = 0; i < n; i++)
		cout << sol[i] << " ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tower;
		v.push_back(tower);
	}
	solve2();
	return 0;
}