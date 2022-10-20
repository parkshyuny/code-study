#include <iostream>
using namespace std;

int N, M;
int A[1000 + 10][1000 + 10];
int sol; // 정답

// New DT
int d[][2] = {{-1, 0}, {0, -1}, {-1, -1}};
int dp[1000 + 10][1000 + 10];

void InputData()
{
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
		}
	}
}
void OutputData()
{
	cout << sol << "\n";
}
void Solve() {
	dp[1][1] = A[1][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int max_val = -1;
			for (int di = 0; di < 3; di++) {
				max_val = max(max_val, dp[i + d[di][0]][j + d[di][1]]);
			}
			dp[i][j] = max_val + A[i][j];
		}
	}
	sol = dp[N][M];
}
int main()
{

	InputData(); // 입력

	// 코드를 작성하세요
	Solve();

	OutputData(); // 출력
	return 0;
}
