#include <iostream>
using namespace std;

int A[10], B[10];
int sol[20+1]; // 정답

void InputData() {
	for (int i = 1; i <= 10; i++) {
		cin >> A[i];
		cin >> B[i];
	}
}
void OutputData() {
	for (int i = 1; i <= 20; i++) cout << sol[i] << " ";
	cout << endl;
}
void Solve() {
	for (int i = 1; i <= 20; i++) sol[i] = i;

	int n, temp;
	for (int i = 1; i <= 10; i++) {
		int b = B[i], a = A[i];
		n = (b - a + 1) / 2;
		
		for (int i = 0; i < n; i++) {
			temp = sol[a + i];
			sol[a + i] = sol[b - i];
			sol[b - i] = temp;
		}
	}
}
int main() {
	InputData(); // 입력

	// 코드를 작성하세요
	Solve();

	OutputData(); // 출력
	return 0;
}
