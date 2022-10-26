#include <iostream>
#include <queue>
using namespace std;

int N, M;
int A[100 + 10];
int sol; // 정답

// New
int visited[100 + 10];
int d[100 + 10];
struct LOC {
	int loc;
	int cnt;
};
queue<LOC> QUE;

void InputData()
{
	cin >> N;
	cin >> M;
	int from, to;
	for (int i = 1; i <= N + M; i++)
	{
		cin >> from; cin >> to;
		A[from] = to;
	}
}
void OutputData()
{
	cout << sol << "\n";
}
/*
void DFS(int cnt, int loc) {
	if (cnt >= sol) return;
	if (loc == 100) {
		sol = min(sol, cnt);
		return;
	}

	for (int i = 1; i <= 6; i++) {
		int nloc = i + loc;
		if (A[nloc]) nloc = A[nloc];
		if (nloc > 100 || visited[nloc]) return;

		visited[nloc] = 1;
		DFS(cnt + 1, nloc);
		visited[nloc] = 0;
	}
}
*/
void BFS() {
	for (int i = 1; i <= 100; i++) d[i] = 1;
	visited[1] = 1;
	QUE.push({1, 0});

	while (!QUE.empty()) {
		LOC curr = QUE.front(); QUE.pop();

		for (int i = 1; i <= 6; i++) {
			int nloc = i + curr.loc;
			if (nloc > 100 || visited[nloc]) continue;
			if (nloc == 100) {
				sol = min(sol, curr.cnt + 1);
				return;
			}
			if (A[nloc]) nloc = A[nloc];
			QUE.push({nloc, curr.cnt + 1});
			visited[nloc] = 1;
		}
	}
}
int main()
{
	InputData(); // 입력

	// 코드를 작성하세요
	sol = 1 << 30;
	BFS();

	OutputData(); // 출력
	return 0;
}
