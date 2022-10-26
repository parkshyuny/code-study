#include <iostream>
#include <queue>
using namespace std;

int N;
int R1, C1, R2, C2;
int sol; // 정답

// New
int d[][2] = {{-2, -1},
			  {-2, 1},
			  {0, -2},
			  {0, 2},
			  {2, -1},
			  {2, 1}};
struct LOC {
	int r;
	int c;
	int cnt;
};
queue<LOC> QUE;
#define MAXN 200
int visited[MAXN + 10][MAXN + 10];

void InputData()
{
	cin >> N;
	cin >> R1;
	cin >> C1;
	cin >> R2;
	cin >> C2;
}
void OutputData()
{
	cout << sol << "\n";
}
void BFS() {
	QUE.push({R1, C1, 0});
	sol = -1;
	visited[R1][C1] = 1;

	while (!QUE.empty()) {
		LOC curr = QUE.front(); QUE.pop();

		for (int i = 0; i < 6; i++) {
			int nr = curr.r + d[i][0];
			int nc = curr.c + d[i][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (visited[nr][nc]) continue;
			if (nr == R2 && nc == C2) {
				sol = curr.cnt + 1;
				return;
			}
			visited[nr][nc] = 1;
			QUE.push({nr, nc, curr.cnt + 1});
		}
	}
}
int main()
{
	InputData(); // 입력

	// 코드를 작성하세요
	BFS();

	OutputData(); // 출력
	return 0;
}
