#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 200000
int N;

struct INFO {
	int id;
	int color;
	int size;
};
INFO input[MAXN + 10];

void InputData()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int col, size;
		cin >> col;
		cin >> size;
		input[i] = {i+1, col, size};
	}
}
int comp(INFO d1, INFO d2) { return d1.size < d2.size; }
void Solve() {
	int check[N + 1], sol[N + 1];
	int acc = 0;

	sort(input, input + N, comp);
	for (int i = 1; i <= N; i++) { sol[i] = 0; }
	for (int i = 1; i <= N; i++) { check[i] = 0; }

	for (int i = 0; i < N; i++) {
		int col = input[i].color;
		int size = input[i].size;

		sol[input[i].id] = acc - check[col];
		acc += size;
		check[col] += size;
	}

	for (int i = 1; i <= N; i++) { 
		cout << sol[i] << '\n'; 
	}
}
int main()
{
	InputData(); // 입력

	// 코드를 작성하세요
	Solve();

	return 0;
}
