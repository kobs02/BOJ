#include <iostream>

using namespace std;

int x_cnt, o_cnt, dot_cnt;
string test;

// 빙고가 있는지 확인하는 함수
bool isBingo(char player, string test) {
	return
		(test[0] == player && test[1] == player && test[2] == player) ||
		(test[3] == player && test[4] == player && test[5] == player) ||
		(test[6] == player && test[7] == player && test[8] == player) ||
		(test[0] == player && test[3] == player && test[6] == player) ||
		(test[1] == player && test[4] == player && test[7] == player) ||
		(test[2] == player && test[5] == player && test[8] == player) ||
		(test[0] == player && test[4] == player && test[8] == player) ||
		(test[2] == player && test[4] == player && test[6] == player);
}

// 최종 상태인지 검사하는 함수
bool check(int x_cnt, int o_cnt, int dot_cnt, string test)
{
	bool x_win = isBingo('X', test);
	bool o_win = isBingo('O', test);

	// 1. X의 개수는 5개 이하, O의 개수는 4개 이하여야함 (전제조건)
	if (x_cnt > 5 || o_cnt > 4)
		return false;
	
	// 5. 둘 다 이긴 경우
	if (x_win && o_win)
		return false;

	// 2. X가 이긴 경우
	if (x_win && x_cnt - 1 == o_cnt)
		return true;

	// 3. O가 이긴 경우
	if (o_win && x_cnt == o_cnt)
		return true;
	
	// 4. 비긴 경우 (빙고가 없고 빈칸도 없음)
	if (!x_win && !o_win && dot_cnt == 0)
		return true;

	

	return false;
}

int main()
{
	while (true) {
		cin >> test;

		if (test == "end")
			break;

		x_cnt = 0;
		o_cnt = 0;
		dot_cnt = 0;

		for (int i = 0; i < 9; i++) {
			if (test[i] == 'X') 
				x_cnt++;
			else if (test[i] == 'O') 
				o_cnt++;
			else if (test[i] == '.') 
				dot_cnt++;
		}
		
		// cout << x_cnt << o_cnt << dot_cnt << endl;

		if (check(x_cnt, o_cnt, dot_cnt, test) == true)
			cout << "valid" << endl;
		else
			cout << "invalid" << endl;
	}
	return 0;
}