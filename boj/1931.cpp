#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// ���� 1931�� "ȸ�ǽ� ����"

int n;
pair<pair<int, int>, int> jobs[100000]; // end time, start time, index

void solve()
{
	int cnt = 0; // ������ ȸ�� ����

	// ������ �ð��� �������� �������� ����
	priority_queue <pair<pair<int, int>, int>,
					vector<pair<pair<int, int>, int>>,
					greater<pair<pair<int, int>, int>>> myq;

	// ȸ�ǵ��� ť�� �������
	for (int i = 0; i < n; i++) 
		myq.push(jobs[i]);

	int si, ei;
	int last_end_time = 0;

	while (!myq.empty()) {
		ei = myq.top().first.first;  // ���� �۾��� �����½ð�
		si = myq.top().first.second; // ���� �۾��� ���۽ð�
		myq.pop();

		// ���� �۾��� ������ �ð� ���� �����ϴ� �۾��� ����
		if (si >= last_end_time) {
			cnt++; // ���õ� ȸ�� �� ���� ����
			last_end_time = ei; // ���������� ������ �ð� ����
		}
	}
	cout << cnt << endl; // ���õ� �� ȸ���� ���� ���
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