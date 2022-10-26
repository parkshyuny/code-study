#Problem: https://www.acmicpc.net/problem/1016

#include <iostream>
#include <cmath>
using namespace std;

int low, high;
int sol; // 정답

void InputData()
{
	cin >> low;
	cin >> high;
}
void OutputData()
{
	cout << sol << "\n";
}
void Solve() {
	int divs[high + 10];
	for (int i = 2; i < sqrt(high); i++) {
		int base = pow(i, 2);
		int idx = 1;

		while () {
			
		}
	}

	int cnt = 0;
	for (int i = low; i <= high; i++) {
		if (!divs[i]) ++cnt;
	}
	sol = cnt;
}
int main()
{

	InputData(); // 입력

	// 코드를 작성하세요
	Solve();

	OutputData(); // 출력
	return 0;
}

1 2 3 5 6 7 10 11 13 14 15 17 19
4 8 12 14 16 18 20 24 25 

4: 4 8 12 16 ...
9: 9 18 ....
