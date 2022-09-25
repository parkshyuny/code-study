#include <iostream>
using namespace std;

int N, M, K;
int A[100+10][100+10];
int O[6][3];
int sol; // 정답

int check[6 + 2];
int seq[6 + 2];
int copyA[100+10][100+10];
int d[4][2] = {{0, 1},
							 {1, 0},
							 {0,-1},
							 {-1,0}};

void InputData() {
	cin >> N;
  cin >> M;
  cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
  for (int i = 1; i <= K; i++) {
    cin >> O[i][0];
    cin >> O[i][1];
    cin >> O[i][2];
  }
}
void OutputData() {
	cout << sol << "\n";
}
void copy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
		  copyA[i][j] = A[i][j];
		}
	}
}
void rotate(int kindex) {
	int r_min, r_max, c_min, c_max;
	int i, j;
	int r = K[kindex][0];
	int c = K[kindex][1];
	int s = K[kindex][2];
	r_min = r - s; c_min = c - s;
	r_max = r + s; c_max = c + s;
	
	while (r_min != r && c_min != c) {
		int curr_r = r_min;
		int curr_c = c_min;
		for (int di = 0; di < 4; di++) {
		  while (nr_r <= r_max || nc_c <= c_max) {
				int nr = nr + d[di][0]; 
				int nc = nc + d[di][1];
				int tmp = copyA[nr][nc];
				
				copyA[nr][nc] = copyA[curr_r][curr_c];  // TODO
				copyA[
				curr_r = nr;
				curr_c = nc;
			}
		}
		r_min = r_min + 1; c_min = c_min + 1;
		r_max = r_max - 1; c_max = c_max - 1;
	}
}
int compute() {
	for (int i = 0; i < K; i++) {
		rotate(seq[i]);
	}
	
	int ret = 1 << 30;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += copyA[i][j];
		}
		ret = min(ret, sum);
	}
	return ret;
}
void DFS(int n) {
	if (n > K) {
		sol = min(sol, compute());
		return;
	}
	
	for (int i = 1; i <= K; i++) {
		if (check[i]) continue;
		
		seq[n] = i; check[i] = 1;
		DFS(n+1);
		seq[n] = 0; check[i] = 0;
	}
}
int main() {
	
	InputData(); // 입력

	// 코드를 작성하세요
	DFS(0);
	
	OutputData(); // 출력
	return 0;
}
