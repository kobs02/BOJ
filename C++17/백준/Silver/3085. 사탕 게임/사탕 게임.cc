#include <iostream>

using namespace std;

int n;
int solution = 0;
char arr[51][51];

// 현재 테이블에서 색이 같은 사탕의 최대 개수 찾기
void find_max() {
	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				count++;
			}
			else {
				count = 1;
			}
			solution = max(solution, count);
		}
	}

	for (int j = 0; j < n; j++) {
		int count = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i][j] == arr[i - 1][j]) {
				count++;
			}
			else {
				count = 1;
			}
			solution = max(solution, count);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << endl;
	}
	*/

	// 1. n-1 행까지 세로로 탐색, 교환
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n; j++) {

			// 세로로 탐색 도중 바로 아래와 같은 문자열일 경우 교환하지않음
			if (arr[i][j] == arr[i + 1][j]) 
				continue;

			// 세로로 탐색 도중 바로 아래와 다른 문자열일 경우 교환
			char temp = arr[i][j];
			arr[i][j] = arr[i + 1][j];
			arr[i + 1][j] = temp;

			// 현재 테이블에서 최대값 확인
			find_max();

			// 원상복구
			temp = arr[i][j];
			arr[i][j] = arr[i + 1][j];
			arr[i + 1][j] = temp;
		}
	}

	// 2. n-1 열까지 가로로 탐색, 교환
    for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n; i++) {

			// 가로로 탐색 도중 바로 오른쪽과 같은 문자열일 경우 교환하지않음
			if (arr[i][j] == arr[i][j + 1])
				continue;

			// 가로로 탐색 도중 바로 오른쪽과 다른 문자열일 경우 교환
			char temp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;

			// 현재 테이블에서 최대값 확인
			find_max();

			// 원상복구
			temp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;
		}
	}

	cout << solution; // 최대값 출력

	return 0;
}