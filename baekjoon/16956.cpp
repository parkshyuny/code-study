#include <iostream>
using namespace std;

int R, C;
char farm[500 + 10][500 + 10];
int sol; // 정답

int d[4][2] = {{0, 1},
			   {1, 0},
			   {-1, 0},
			   {0, -1}};

void InputData()
{
	cin >> R;
	cin >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> farm[i][j];
		}
	}
}
void OutputData()
{
	cout << sol << endl;
	if (sol == 1)
	{
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				cout << farm[i][j];
			}
			cout << endl;
		}
	}
}
void solve()
{
	sol = 0;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (farm[i][j] == 'W')
			{
				for (int di = 0; di < 4; di++)
				{
					int nr = i + d[di][0];
					int nc = j + d[di][1];
					if (nr < 1 || nr > R || nc < 1 || nr > C) continue;
					if (farm[nr][nc] == 'S') return;
					if (farm[nr][nc] == '.') farm[nr][nc] = 'D';
				}
			}
		}
	}
	sol = 1;
}
int main()
{

	InputData(); // 입력

	// 코드를 작성하세요
	solve();
	OutputData(); // 출력
	return 0;
}
