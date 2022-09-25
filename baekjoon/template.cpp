#include <iostream>
using namespace std;

int N, M;
int A[100+10][100+10];
int sol; // 정답

void InputData() {
	cin >> N;
  cin >> M;
  cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

}
void OutputData() {
	cout << sol << "\n";
}

int main() {
	
	InputData(); // 입력

	// 코드를 작성하세요

	OutputData(); // 출력
	return 0;
}
