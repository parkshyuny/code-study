// https://www.acmicpc.net/problem/11758
#include <iostream>
using namespace std;

int P1[2], P2[2], P3[2];
int sol; // 정답

void InputData()
{
	cin >> P1[0]; cin >> P1[1];
	cin >> P2[0]; cin >> P2[1];
	cin >> P3[0]; cin >> P3[1];
}
void OutputData()
{
	cout << sol << "\n";
}
void Solve() {
	int a_x = P2[0] - P1[0];
	int a_y = P2[1] - P1[1];
	int b_x = P3[0] - P1[0];
	int b_y = P3[1] - P1[1];
	int a_z = 0, b_z = 0;

	int c_x = (a_y * b_z) - (a_z * b_y);
	int c_y = (a_z * b_x) - (a_x * b_z);
	int c_z = (a_x * b_y) - (a_y * b_x);
	int cp = c_x + c_y + c_z;

	sol = 0;
	if (cp < 0) sol = -1;
	else if (cp > 0) sol = 1;
}
int main()
{
	InputData(); // 입력

	// 코드를 작성하세요
	Solve();

	OutputData(); // 출력
	return 0;
}
