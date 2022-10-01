#include <iostream>
#include <string.h>
using namespace std;

int N, M, K;
int A[100 + 10][100 + 10];
int O[6][3];
int sol; // 정답

int check[6 + 2];
int seq[6 + 2];
int copyA[100 + 10][100 + 10];
int d[4][2] = {{0, 1},  // R
			   {1, 0},  // D
			   {0, -1}, // L
			   {-1, 0}};// U

void InputData()
{
	cin >> N;
	cin >> M;
	cin >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= K; i++)
	{
		cin >> O[i][0];
		cin >> O[i][1];
		cin >> O[i][2];
	}
}
void OutputData()
{
	cout << sol << "\n";
}
void copy()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			copyA[i][j] = A[i][j];
		}
	}
}
void rotate(int kindex)
{
	int r_min, r_max, c_min, c_max;
	int nr, nc, curr_r, curr_c;
	int i, j;
	int preVal, nextVal;
	int r = O[kindex][0];
	int c = O[kindex][1];
	int s = O[kindex][2];
	r_min = r - s;
	c_min = c - s;
	r_max = r + s;
	c_max = c + s;

	while (r_min != r && c_min != c)
	{
		curr_r = r_min; 
		curr_c = c_min;
		preVal = copyA[curr_r][curr_c];
		for (int di = 0; di < 4; di++)
		{
			nr = curr_r + d[di][0];
			nc = curr_c + d[di][1];
			while (nr <= r_max && nc <= c_max && nr >= r_min && nc >= c_min)
			{
				if (nr > N || nc > M || nr < 1 || nc < 1) break;
				//if (nr == r_min && nc == c_min) break;
				
				nextVal = copyA[nr][nc];
				copyA[nr][nc] = preVal;
				preVal = nextVal;

				curr_r = nr;
				curr_c = nc;
				nr = nr + d[di][0]; 
				nc = nc + d[di][1];
			}
		}
		r_min = r_min + 1;
		c_min = c_min + 1;
		r_max = r_max - 1;
		c_max = c_max - 1;
	}
}
int compute()
{
	copy();
	for (int i = 0; i < K; i++)
	{
		rotate(seq[i]);
	}

	int ret = 1 << 30;
	int sum;
	for (int i = 1; i <= N; i++)
	{
		sum = 0;
		for (int j = 1; j <= M; j++)
		{
			sum += copyA[i][j];
		}
		ret = min(ret, sum);
	}
	return ret;
}
void DFS(int n)
{
	if (n == K)
	{
		sol = min(sol, compute());
		return;
	}

	for (int i = 1; i <= K; i++)
	{
		if (check[i]) continue;

		seq[n] = i;
		check[i] = 1;
		DFS(n + 1);
		seq[n] = 0;
		check[i] = 0;
	}
}
int main()
{

	InputData(); // 입력

	// 코드를 작성하세요
	memset(check, 0, sizeof(check));
	sol = 1 << 30;
	DFS(0);

	OutputData(); // 출력
	return 0;
}
