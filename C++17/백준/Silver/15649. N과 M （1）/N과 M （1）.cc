#include <iostream>

using namespace std;

int n, m;
int arr[8];       // 만들어낼 수열을 저장할 배열
bool visited[8];  // dfs 방문 여부 확인

void dfs(int depth)
{
	// 수열에 m개의 숫자가 채워지면 출력
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	// 1부터 n까지 순회하며 수열 생성
	for (int i = 1; i <= n; i++) {
		// 방문하지 않은 숫자일 경우
		if (!visited[i])
		{
			visited[i] = true; // 해당 숫자	방문 표시
			arr[depth] = i;    // 현재 깊이에 숫자를 저장
			dfs(depth + 1);    // 다음 깊이로 재귀호출
			visited[i] = false; // 백트래킹(방문 표시 해제)
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(0);
	return 0;
}