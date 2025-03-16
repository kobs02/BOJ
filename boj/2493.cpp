#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
long tower;
stack <pair<long, int>> s; // ����
vector <long> v;           // Ÿ�� ���̰� ����� ����(�񱳿�)
vector <int> sol;

#if 0
void solve1() // ���� for������ ���� �ð��ʰ�. (O(n^2))
{
	int chk;
	sol.push_back(0);
	for (int i = 1; i < n; i++) { // 2��° Ÿ������ ������ Ÿ������ �ݺ�
		chk = 0; // üũ �÷���
		for (int j = 1; j <= i; j++) { // ������ Ÿ������ ù ��° Ÿ������ Ž��
			if (v[i] <= v[i - j]) {  // �� Ÿ���� ���� Ÿ������ ū ���
				sol.push_back(i-j+1);    // �� Ÿ�� ������ sol�� ����
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
		while (!s.empty() && s.top().first < v[i]) // i+1��° Ÿ��(���� Ÿ��)���� ���� Ÿ�� ����
			s.pop();

		if (!s.empty()) // ���� Ÿ������ ���� Ÿ���� �� �����µ� �����ִ� Ÿ���� �ִ� ���
			sol[i] = s.top().second; // �� Ÿ������ ���� ����
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